.DELETE_ON_ERROR:
CC = arm-none-eabi-gcc
FLAGS = -Wall -Wextra -O2 -nostdlib -nostartfiles

.PHONY: compile clean flash

compile: Task_0.c
	@$(CC) $(FLAGS) -c Task_0.c -o Task_0.exe

clean:
	@rm -rf Task_0.exe