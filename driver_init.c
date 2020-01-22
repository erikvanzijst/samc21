/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <peripheral_clk_config.h>
#include <utils.h>
#include <hal_init.h>

#include <hpl_adc_base.h>
#include <hpl_rtc_base.h>

struct timer_descriptor TIMER_0;

struct adc_sync_descriptor ADC_0;

struct pwm_descriptor PWM_0;

struct temp_sync_descriptor TEMPERATURE_SENSOR_0;

void ADC_0_PORT_init(void)
{

	// Disable digital pin circuitry
	gpio_set_pin_direction(ANALOG_IN, GPIO_DIRECTION_OFF);

	gpio_set_pin_function(ANALOG_IN, PINMUX_PA02B_ADC0_AIN0);

	// Disable digital pin circuitry
	gpio_set_pin_direction(ADC_NEG, GPIO_DIRECTION_OFF);

	gpio_set_pin_function(ADC_NEG, PINMUX_PA05B_ADC0_AIN5);

	// Disable digital pin circuitry
	gpio_set_pin_direction(ADC_POS, GPIO_DIRECTION_OFF);

	gpio_set_pin_function(ADC_POS, PINMUX_PA03B_ADC0_VREFP);
}

void ADC_0_CLOCK_init(void)
{
	hri_mclk_set_APBCMASK_ADC0_bit(MCLK);
	hri_gclk_write_PCHCTRL_reg(GCLK, ADC0_GCLK_ID, CONF_GCLK_ADC0_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
}

void ADC_0_init(void)
{
	ADC_0_CLOCK_init();
	ADC_0_PORT_init();
	adc_sync_init(&ADC_0, ADC0, _adc_get_adc_sync());
}

/**
 * \brief Timer initialization function
 *
 * Enables Timer peripheral, clocks and initializes Timer driver
 */
static void TIMER_0_init(void)
{
	hri_mclk_set_APBAMASK_RTC_bit(MCLK);
	timer_init(&TIMER_0, RTC, _rtc_get_timer());
}

void delay_driver_init(void)
{
	delay_init(SysTick);
}

void PWM_0_PORT_init(void)
{

	gpio_set_pin_function(LED, PINMUX_PA15E_TC4_WO1);
}

void PWM_0_CLOCK_init(void)
{
	hri_mclk_set_APBCMASK_TC4_bit(MCLK);
	hri_gclk_write_PCHCTRL_reg(GCLK, TC4_GCLK_ID, CONF_GCLK_TC4_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
}

void PWM_0_init(void)
{
	PWM_0_CLOCK_init();
	PWM_0_PORT_init();
	pwm_init(&PWM_0, TC4, _tc_get_pwm());
}

void TEMPERATURE_SENSOR_0_CLOCK_init(void)
{
	hri_mclk_set_APBAMASK_TSENS_bit(MCLK);

	hri_gclk_write_PCHCTRL_reg(GCLK, TSENS_GCLK_ID, CONF_GCLK_TSENS_SRC | (1 << GCLK_PCHCTRL_CHEN_Pos));
}

void TEMPERATURE_SENSOR_0_init(void)
{
	TEMPERATURE_SENSOR_0_CLOCK_init();
	temp_sync_init(&TEMPERATURE_SENSOR_0, TSENS);
}

void system_init(void)
{
	init_mcu();

	ADC_0_init();

	TIMER_0_init();

	delay_driver_init();

	PWM_0_init();

	TEMPERATURE_SENSOR_0_init();
}
