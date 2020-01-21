#include <atmel_start.h>
#include <atmel_start_pins.h>

uint32_t min(uint32_t a, uint32_t b);

uint32_t min(uint32_t a, uint32_t b)
{
	return a > b ? b : a;
}

int main(void)
{
	const uint32_t period = 10000;
	const float scale = 0x3FF / (float)period;
	uint8_t buffer[2];
	uint32_t val;
	uint32_t duty = 0;

	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	adc_sync_enable_channel(&ADC_0, 0);
	pwm_set_parameters(&PWM_0, period, period / 2);
	pwm_enable(&PWM_0);

	while (1) {
		adc_sync_read_channel(&ADC_0, 0, buffer, sizeof(buffer));

		val = (buffer[1] << 8) + buffer[0];
		duty = min((uint32_t)((float)val / scale), period);
		pwm_set_parameters(&PWM_0, period, duty);

		gpio_toggle_pin_level(BLINKER);

		delay_ms(1);
	}
}
