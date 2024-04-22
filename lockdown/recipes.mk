LKD_SOURCE_DIR=lockdown/source
LKD_BUILD_DIR=build/lockdown
LKD_OUTPUT=$(LKD_BUILD_DIR)/liblockdown.so

LKD_INCLUDE_DIR=lockdown/include
LKD_HEADERS=$(shell find $(LKD_INCLUDE_DIR)/ -type f -name '*.h')

# Ugly hack for install to place the headers inside their correct directories 
LKD_INSTALLED_HEADERS=$(addprefix $(SYSTEM_ROOT)/System/Headers/,$(subst $(LKD_INCLUDE_DIR)/,,$(LKD_HEADERS)))

LKD_FILES=syscall.s file.c mem.c
LKD_SOURCES=$(addprefix $(LKD_SOURCE_DIR)/,$(LKD_FILES))
LKD_BUILD=$(addprefix $(LKD_BUILD_DIR)/,$(addsuffix .o,$(LKD_FILES)))
LKD_LDFLAGS=-shared -Bsymbolic
LKD_CFLAGS=$(CFLAGS) -I$(LKD_INCLUDE_DIR)

$(LKD_OUTPUT): $(LKD_BUILD)
	$(LD) $(LKD_LDFLAGS) $(LKD_BUILD) -o $(LKD_OUTPUT)

$(LKD_BUILD_DIR)/%.c.o: $(LKD_SOURCE_DIR)/%.c
	mkdir -p build/$(dir $(subst $(LKD_SOURCE_DIR)/,lockdown/,$^))
	$(CC) $(LKD_CFLAGS) $^ -c -o $@

$(LKD_BUILD_DIR)/%.s.o: $(LKD_SOURCE_DIR)/%.s
	mkdir -p build/$(dir $(subst $(LKD_SOURCE_DIR)/,lockdown/,$^))
	$(AS) $(LKD_ASFLAGS) $^ -o $@

$(SYSTEM_ROOT)/System/Headers/%.h: $(LKD_INCLUDE_DIR)/%.h
	install -C -D -t $(SYSTEM_ROOT)/System/Headers/$(dir $(subst $(LKD_INCLUDE_DIR)/,,$^)) $^ -v

install_library: $(LKD_OUTPUT)
	install -C -D -t $(SYSTEM_ROOT)/System/Libraries/ $(LKD_OUTPUT) -v

lockdown: $(LKD_OUTPUT) 

lockdown_install: lockdown $(LKD_INSTALLED_HEADERS) install_library
