NAME := weiss

include sdcc_msx/Makefile.in

CCFLAGS_MSX   += -DKONAMI5
CCFLAGS_MSX   += --all-callee-saves --opt-code-speed
#CCFLAGS_MSX   += --reserve-regs-iy --callee-saves-bc

OPENMSX_BIN = /opt/openMSX/bin/openmsx
#OPENMSX_PARAM = -command "profile::section_scope_bp frame 0xFD9F; profile_osd p;" 

ADDR_DATA = 0xC000

#CCZ80 = sdcc_msx/bin/sdcc-3.9.0/bin/sdcc
CCZ80 = sdcc_msx/bin/sdcc-4.0.0/bin/sdcc

MAX_ALLOCS = 20000
