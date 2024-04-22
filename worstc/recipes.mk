WORSTC_BUILD_DIR=build/wc
WORSTC_SOURCE_DIR=worstc/source
WORSTC_INCLUDE_DIR=worstc/include

WORSTC_OUTPUT=$(WORSTC_BUILD_DIR)/libworstc.so

# ============================ FILES
WORSTC_MALLOC_FILES=malloc/liballoc_interface.c malloc/liballoc.c
WORSTC_STDLIB_FILES=stdlib/strtoul.c
WORSTC_STDIO_FILES=stdio/fopen.c stdio/getc.c stdio/fread.c stdio/stdout.c \
				   stdio/feof.c stdio/fseek.c
WORSTC_STRING_FILES=string/strcpy.c string/memset.c string/strlen.c string/memcmp.c \
					string/memchr.c string/strspn.c string/memmove.c string/strtok.c
WORSTC_FILES=start.c $(WORSTC_STRING_FILES) $(WORSTC_MALLOC_FILES) $(WORSTC_STDIO_FILES) \
					 $(WORSTC_STDLIB_FILES)
# =============================

WORSTC_SOURCES=$(addprefix $(WORSTC_SOURCE_DIR)/,$(WORSTC_FILES))
WORSTC_BUILD=$(addprefix $(WORSTC_BUILD_DIR)/,$(addsuffix .o,$(WORSTC_FILES)))
WORSTC_HEADERS=$(shell find $(WORSTC_INCLUDE_DIR)/ -type f -name '*.h')

# Ugly hack for install to place the headers inside their correct directories 
WORSTC_INSTALLED_HEADERS=$(addprefix $(SYSTEM_ROOT)/System/Headers/,$(subst $(WORSTC_INCLUDE_DIR)/,,$(WORSTC_HEADERS)))
include worstc/wcrt.mk
WORSTC_CFLAGS=$(CFLAGS) \
			  -I$(WORSTC_INCLUDE_DIR)
WORSTC_LDFLAGS=-shared -z now -L$(LKD_BUILD_DIR) -llockdown -Bsymbolic

worstc: $(WORSTC_OUTPUT)

worstc_install: worstc $(WORSTC_INSTALLED_HEADERS)
	install -C -t $(SYSTEM_ROOT)/System/Libraries $(WORSTC_OUTPUT) -v

$(SYSTEM_ROOT)/System/Headers/%.h: $(WORSTC_INCLUDE_DIR)/%.h
	install -C -D -t $(SYSTEM_ROOT)/System/Headers/$(dir $(subst $(WORSTC_INCLUDE_DIR)/,,$^)) $^ -v

$(WORSTC_OUTPUT): $(WORSTC_BUILD)
	$(LD) $(WORSTC_LDFLAGS) $(WORSTC_BUILD) -o $(WORSTC_OUTPUT)

$(WORSTC_BUILD_DIR)/%.c.o: $(WORSTC_SOURCE_DIR)/%.c
	mkdir -p build/$(dir $(subst $(WORSTC_SOURCE_DIR)/,wc/,$^))
	$(CC) $(WORSTC_CFLAGS) $^ -c -o $@

worstc_clean:
	rm -rf $(WORSTC_BUILD_DIR)
	mkdir -p $(WORSTC_BUILD_DIR)
