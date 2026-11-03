# Makefile placeholder for the manually configured STM32F103C8T6 project.
# Firmware build rules are intentionally not fabricated: CMSIS/device headers,
# FreeRTOS Kernel + ARM_CM3 port, startup assembly and linker script are not
# included in the uploaded repository yet. Add those sources before building.

.PHONY: help clean
help:
	@echo "Solar Tracker project scaffold"
	@echo "Build is not configured yet: add CMSIS, FreeRTOS ARM_CM3, startup and linker files."

clean:
	rm -rf build
