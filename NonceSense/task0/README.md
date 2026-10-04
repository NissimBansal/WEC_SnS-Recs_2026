## Microcontroller used
STM32F446RE

## Pin Mapping

- GPIO port A pin 5 (or 6th pin) is set as user avaiable LED so I'm using that.

## Register Base Addresses and Offsets Used

- RCC : Base Address = 0x4002_3800. Offsets used-
    1. 0x30 = AHB1 peripheral clock enable register
    2. 0x40 = APB1 peripheral clock enable register

- GPIOA : Base Address = 0x4002_0000. Offsets used-
    1. 0x00 = Port mode register
    2. 0x14 = Port output data register

- TIM2 : Base Address = 0x4000_0000. Offsets used-
    1. 0x00 = Control register 1
    2. 0x10 = Status register
    3. 0x28 = Prescaler
    4. 0x2C = Auto-reload register