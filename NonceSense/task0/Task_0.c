#include <stdint.h>

#define RCC 0x40023800 /* start of RCC registers*/
#define GPIOA 0x40020000 /* start of GPIO port A registers*/
#define TIM2 0x40000000 /* start of TIMER2 registers*/

void init(void)
{
	/* Enabling clocks for peripherals */
	*((volatile uint32_t*)(RCC + 0x30)) |= (1 << 0); /* Clock enable for GPIOA */
	*((volatile uint32_t*)(RCC + 0x40)) |= (1 << 0); /* Clock enable for TIM2 */

	/* Setting GPIO port A pin 5 settings */ 
	*((volatile uint32_t*)(GPIOA)) |= (1 << 10); /* Setting MODER5 to output */
	*((volatile uint32_t*)(GPIOA)) &= ~(1 << 11); /* Setting MODER5 to output */

	/* Setting prescalar and auto-reload for TIM2 */
	*((volatile uint32_t*)(TIM2 + 0x28)) = 399; /* Prescalar */
	*((volatile uint32_t*)(TIM2 + 0x2C)) = 19999; /* Auto-reload */
	/* This gives frequency = 1Hz considering APB1, on which TIM2 sits, recieves 8MHz clock */
}

int main()
{
	init();

	*((volatile uint32_t*)(TIM2)) |= (1 << 0); /* Starts counter */

	while(1)
	{
		while(!(*((volatile uint32_t*)(TIM2 + 0x10)) & (1 << 0))); // Check 0th bit of status register
		*((volatile uint32_t*)(TIM2 + 0x10)) &= ~(1 << 0); /* Resets the flag */
		*((volatile uint32_t*)(GPIOA + 0x14)) ^= (1 << 5); /* Toggles LED between ON & OFF */
	}
}
