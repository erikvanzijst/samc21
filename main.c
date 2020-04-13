#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <atmel_start.h>
#include <atmel_start_pins.h>
#include <utils.h>

#include "win.h"

int main(void)
{
    struct io_descriptor *io;

    const uint32_t period = 10000;
    const uint32_t floor = 20;
    const float scale = (0xFFF - floor) / (float)period;

    uint8_t buffer[2];
    struct dwin* win = dwin_new(100);
    float val;
    uint32_t duty;

    char buf[100];
    uint16_t buflen;

    /* Initializes MCU, drivers and middleware */
    atmel_start_init();
    adc_sync_enable_channel(&ADC_0, 0);
    pwm_set_parameters(&PWM_0, period, 0);
    pwm_enable(&PWM_0);
    usart_sync_get_io_descriptor(&USART_0, &io);
    usart_sync_enable(&USART_0);

    while (1) {
        adc_sync_read_channel(&ADC_0, 0, buffer, sizeof(buffer));

        val = (int32_t)(((buffer[1] << 8) + buffer[0]) - floor) / scale;
        duty = (uint32_t)max(dwin_push(win, val), 0.0);
        buflen = sprintf(buf, "ADC: %5d, Period: %ld, duty cycle: %5ld\r\n", ((buffer[1] << 8) + buffer[0]), period, duty);

        pwm_set_parameters(&PWM_0, period, duty);
        delay_ms(1);
        io_write(io, (uint8_t *)buf, buflen);

    }
    dwin_free(win);
}
