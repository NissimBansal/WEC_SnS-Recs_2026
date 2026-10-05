.DELETE_ON_ERROR:
CC = arm-none-eabi-gcc
FLAGS = -Wall -Wextra -O2 -nostdlib -nostartfiles -mcpu=cortex-m4 -mthumb

.PHONY: compile clean flash

compile: Task_0.c
	@$(CC) $(FLAGS) -T linker.ld startup.c Task_0.c -o Task_0.elf

flash:
	@openocd -f interface/stlink.cfg -f target/stm32f4x.cfg -c "program Task_0.elf verify reset exit"

clean:
	@rm -rf Task_0.exe Task_0.elf