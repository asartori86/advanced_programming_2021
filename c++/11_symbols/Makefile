all:
	+$(MAKE) $@ -C 01_greetings_library && $(MAKE) $@ -C 02_link_library
	+$(MAKE) $@ -C 03_internal_external
	+$(MAKE) $@ -C 04_static

%:
	+$(MAKE) $@ -C 01_greetings_library && $(MAKE) $@ -C 02_link_library
	+$(MAKE) $@ -C 03_internal_external
	+$(MAKE) $@ -C 04_static
	+$(MAKE) $@ -C 05_one_definition_rule

