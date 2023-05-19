.phony: configure all clean build flash_erase flash_program flash_verify flash_reset

configure:
	mkdir -p build
	cmake -DCMAKE_TOOLCHAIN_FILE=cmake/riscv.cmake -B build

clean:
	rm -rf build

flash_erase:
	openocd -f wch-riscv.cfg -c init -c halt -c "flash erase_sector wch_riscv 0 last" -c exit

flash_program:
	openocd -f wch-riscv.cfg -c init -c halt -c "program build/wch_demo.hex" -c exit

flash_verify:
	openocd -f wch-riscv.cfg -c init -c halt -c "verify_image build/wch_demo.hex" -c exit

flash_reset:
	openocd -f wch-riscv.cfg -c init -c halt -c wlink_reset_resume -c exit