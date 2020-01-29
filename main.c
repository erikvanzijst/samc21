#include <stdlib.h>
#include <string.h>

#include <atmel_start.h>
#include <atmel_start_pins.h>
#include <utils.h>

#include "win.h"

int main(void)
{
    const uint32_t period = 10000;
    const uint32_t floor = 20;
    const float scale = (0xFFF - floor) / (float)period;

    uint8_t buffer[2];
    struct dwin* win = dwin_new(100);
    float val;

    /* Initializes MCU, drivers and middleware */
    atmel_start_init();
    adc_sync_enable_channel(&ADC_0, 0);
    pwm_set_parameters(&PWM_0, period, 0);
    pwm_enable(&PWM_0);

    while (1) {
        adc_sync_read_channel(&ADC_0, 0, buffer, sizeof(buffer));

        val = (int32_t)(((buffer[1] << 8) + buffer[0]) - floor) / scale;

        pwm_set_parameters(&PWM_0, period, (uint32_t)max(dwin_push(win, val), 0.0));
        delay_ms(1);
    }
    dwin_free(win);
}
