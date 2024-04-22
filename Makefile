SYSTEM_ROOT=$$SYSROOT
AS=x86_64-unknown-lockdown-as
CC=x86_64-unknown-lockdown-gcc
LD=x86_64-unknown-lockdown-ld

CFLAGS=-std=gnu11 -fno-stack-protector -fno-stack-check -Wall -Wextra -fpic \
	   -I$(SYSTEM_ROOT)/System/Headers -g

MODULES=worstc lockdown linit
all: lockdown worstc wcrt linit

$(foreach m,$(MODULES),$(eval include $(m)/recipes.mk))
