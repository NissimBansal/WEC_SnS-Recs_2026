.DELETE_ON_ERROR:
CC = arm-none-eabi-gcc
FLAGS = -Wall -Wextra -O2 -nostdlib -nostartfiles

compile: Task_0.c
	@$(CC) $(FLAGS) -c Task_0.c -o Task_0.exe

.PHONY: clean
clean:
	@rm Task_0.exe