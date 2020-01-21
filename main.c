#include <stdlib.h>
#include <string.h>

#include <atmel_start.h>
#include <atmel_start_pins.h>

struct movavg {
	uint32_t len;
	float * win;
	uint32_t pos;
};

struct movavg* movavg_new();
struct movavg* movavg_new(uint32_t len) {
	struct movavg* win = malloc(sizeof(struct movavg));
	win->len = len;
	win->win = malloc(sizeof(float) * len);
	win->pos = 0;
	memset(win->win, 0, sizeof(float) * len);
	return win;
}

float movavg_push(struct movavg* win, float val);
float movavg_push(struct movavg* win, float val)
{
	win->win[win->pos] = val;
	win->pos = (win->pos + 1) % win->len;

	float total = 0;
	for (int i = 0; i < win->len; i++) {
		total += win->win[i];
	}
	return total / win->len;
}

float max(float a, float b);
float max(float a, float b)
{
	return a > b ? a : b;
}

int main(void)
{
	const uint32_t period = 10000;
	const uint32_t floor = 40;
	const float scale = (0xFFF - floor) / (float)period;

	uint8_t buffer[2];
	struct movavg* win = movavg_new(50);
	float val, duty;


	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	adc_sync_enable_channel(&ADC_0, 0);
	pwm_set_parameters(&PWM_0, period, 0);
	pwm_enable(&PWM_0);

	while (1) {
		adc_sync_read_channel(&ADC_0, 0, buffer, sizeof(buffer));

		val = (int32_t)(((buffer[1] << 8) + buffer[0]) - floor) / scale;
		duty = movavg_push(win, val);

		pwm_set_parameters(&PWM_0, period, (uint32_t)max(duty, 0.0));
		gpio_toggle_pin_level(BLINKER);

		delay_ms(1);
	}
	free(win);
}
