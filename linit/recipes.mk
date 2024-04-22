LINIT_SOURCE_DIR=linit/source
LINIT_BUILD_DIR=build/linit
LINIT_OUTPUT=$(LINIT_BUILD_DIR)/linit.elf

LINIT_FILES=main.c pmount.c
LINIT_SOURCES=$(addprefix $(LINIT_SOURCE_DIR)/,$(LINIT_FILES))
LINIT_BUILD=$(addprefix $(LINIT_BUILD_DIR)/,$(addsuffix .o,$(LINIT_FILES)))

LINIT_LDFLAGS=$(LDFLAGS) $(SYSTEM_ROOT)/System/Libraries/wcruntime.o -lworstc -llockdown
LINIT_CFLAGS=$(CFLAGS)

$(LINIT_OUTPUT): $(LINIT_BUILD)
	$(LD) $(LINIT_LDFLAGS) $(LINIT_BUILD) -o $(LINIT_OUTPUT)

$(LINIT_BUILD_DIR)/%.c.o: $(LINIT_SOURCE_DIR)/%.c
	mkdir -p $(dir $(subst $(LINIT_SOURCE_DIR)/,$(LINIT_BUILD_DIR)/,$^))
	$(CC) $(LINIT_CFLAGS) $^ -c -o $@

linit: $(LINIT_OUTPUT)

linit_install: linit
	install -C -D -t $(SYSTEM_ROOT)/System/ $(LINIT_OUTPUT)
