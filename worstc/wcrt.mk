WCRT_OUTPUT=$(addprefix $(WORSTC_BUILD_DIR)/,wcruntime.o crti.o crtbegin.o crtend.o crtn.o)

WCRT_FILES=wcrt/wcruntime.s wcrt/crti.s wcrt/crtn.s wcrt/crtbegin.s wcrt/crtend.s
WCRT_SOURCES=$(addprefix $(WORSTC_SOURCE_DIR)/,$(WCRT_FILES))
WCRT_BUILD=$(addprefix $(WORSTC_BUILD_DIR)/,$(addsuffix .o,$(WCRT_FILES)))

wcrt_install: wcrt
# Because WCRT source files count will likely never grow, we can use this
# workaround.
	cp $(WORSTC_BUILD_DIR)/wcrt/wcruntime.s.o $(WORSTC_BUILD_DIR)/wcrt/wcruntime.o 
	cp $(WORSTC_BUILD_DIR)/wcrt/crti.s.o $(WORSTC_BUILD_DIR)/wcrt/crti.o
	cp $(WORSTC_BUILD_DIR)/wcrt/crtbegin.s.o $(WORSTC_BUILD_DIR)/wcrt/crtbegin.o
	cp $(WORSTC_BUILD_DIR)/wcrt/crtend.s.o $(WORSTC_BUILD_DIR)/wcrt/crtend.o
	cp $(WORSTC_BUILD_DIR)/wcrt/crtn.s.o $(WORSTC_BUILD_DIR)/wcrt/crtn.o

	install -t $(SYSTEM_ROOT)/System/Libraries $(WORSTC_BUILD_DIR)/wcrt/wcruntime.o \
		$(WORSTC_BUILD_DIR)/wcrt/crtbegin.o $(WORSTC_BUILD_DIR)/wcrt/crtend.o \
		$(WORSTC_BUILD_DIR)/wcrt/crti.o  \
		$(WORSTC_BUILD_DIR)/wcrt/crtn.o

wcrt: $(WCRT_BUILD)

$(WORSTC_BUILD_DIR)/wcrt/%.s.o: $(WORSTC_SOURCE_DIR)/wcrt/%.s
	mkdir -p $(WORSTC_BUILD_DIR)/wcrt
	$(AS) $< -o $@