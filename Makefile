# Library metadata.
TARGET       := GoldHEN_Hook.prx
TARGETSTUB   := GoldHEN_Hook_Stub.so
TARGETSTATIC := libGoldHEN_Hook.a

# Libraries linked into the ELF.
LIBS         := -lkernel -lSceLibcInternal -lSceSysmodule

# Additional compile flags.
#EXTRAFLAGS  :=

# Root vars
TOOLCHAIN   := $(OO_PS4_TOOLCHAIN)
PROJDIR     := source
INTDIR      := build
INCLUDEDIR  := include

# Define objects to build
CFILES      := $(wildcard $(PROJDIR)/*.c)
CPPFILES    := $(wildcard $(PROJDIR)/*.cpp)
COMMONFILES := $(wildcard $(COMMONDIR)/*.cpp)
OBJS        := $(patsubst $(PROJDIR)/%.c, $(INTDIR)/%.o, $(CFILES)) $(patsubst $(PROJDIR)/%.cpp, $(INTDIR)/%.o, $(CPPFILES)) $(patsubst $(COMMONDIR)/%.cpp, $(INTDIR)/%.o, $(COMMONFILES))
STUBOBJS    := $(patsubst $(PROJDIR)/%.c, $(INTDIR)/%.o, $(CFILES)) $(patsubst $(PROJDIR)/%.cpp, $(INTDIR)/%.o.stub, $(CPPFILES)) $(patsubst $(COMMONDIR)/%.cpp, $(INTDIR)/%.o.stub, $(COMMONFILES))

# Define final C/C++ flags
CFLAGS      := --target=x86_64-pc-freebsd12-elf -fPIC -funwind-tables -c $(EXTRAFLAGS) -isysroot $(TOOLCHAIN) -isystem $(TOOLCHAIN)/$(INCLUDEDIR) -Iinclude
CXXFLAGS    := $(CFLAGS) -isystem $(TOOLCHAIN)/$(INCLUDEDIR)/c++/v1
LDFLAGS     := -m elf_x86_64 -pie --script $(TOOLCHAIN)/link.x -e _init --eh-frame-hdr -L$(TOOLCHAIN)/lib $(LIBS)

# Create the intermediate directory incase it doesn't already exist.
_unused     := $(shell mkdir -p $(INTDIR))

# Check for linux vs macOS and account for clang/ld path
UNAME_S     := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
		CC      := clang
		CCX     := clang++
		LD      := ld.lld
		CDIR    := linux
		AR      := llvm-ar
endif
ifeq ($(UNAME_S),Darwin)
		CC      := /usr/local/opt/llvm/bin/clang
		CCX     := /usr/local/opt/llvm/bin/clang++
		LD      := /usr/local/opt/llvm/bin/ld.lld
		CDIR    := macos
endif

$(TARGET): $(INTDIR) $(OBJS)
	$(LD) $(INTDIR)/*.o -o $(INTDIR)/$(PROJDIR).elf $(LDFLAGS)
	$(TOOLCHAIN)/bin/$(CDIR)/create-fself -in=$(INTDIR)/$(PROJDIR).elf -out=$(INTDIR)/$(PROJDIR).oelf --lib=$(TARGET) --paid 0x3800000000000011

$(TARGETSTATIC): $(INTDIR) $(OBJS)
	$(AR) --format=bsd rcs $(TARGETSTATIC) $(INTDIR)/*.o

$(TARGETSTUB): $(INTDIR) $(STUBOBJS)
	$(CC) $(INTDIR)/*.o.stub -o $(TARGETSTUB) -target x86_64-pc-linux-gnu -shared -fuse-ld=lld -ffreestanding -nostdlib -fno-builtin -L$(TOOLCHAIN)/lib $(LIBS)

$(INTDIR)/%.o: $(PROJDIR)/%.c
	$(CC) $(CFLAGS) -o $@ $<

$(INTDIR)/%.o: $(PROJDIR)/%.cpp
	$(CCX) $(CXXFLAGS) -o $@ $<

$(INTDIR)/%.o.stub: $(PROJDIR)/%.c
	$(CC) -target x86_64-pc-linux-gnu -ffreestanding -nostdlib -fno-builtin -fPIC -s -c -o $@ $<

$(INTDIR)/%.o.stub: $(PROJDIR)/%.cpp
	$(CCX) -target x86_64-pc-linux-gnu -ffreestanding -nostdlib -fno-builtin -fPIC -s -c -o $@ $<

.PHONY: clean
.DEFAULT_GOAL := all

all: $(TARGETSTATIC)

clean:
	rm -rf $(TARGET) $(TARGETSTUB) $(INTDIR) $(OBJS)
