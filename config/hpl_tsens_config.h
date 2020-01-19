/* Auto-generated config file hpl_tsens_config.h */
#ifndef HPL_TSENS_CONFIG_H
#define HPL_TSENS_CONFIG_H

// <<< Use Configuration Wizard in Context Menu >>>

#include <peripheral_clk_config.h>

// <e> Advanced configurations
// <id> tsens_advanced_settings
#ifndef CONF_TSENS_ADVANCED_SETTINGS
#define CONF_TSENS_ADVANCED_SETTINGS 0
#endif

// <q> Run In Standby
// <i> Indicates whether the Temperature Sensor works in standby mode
// <id> tsens_runstdby
#ifndef CONF_TSENS_RUNSTDBY
#define CONF_TSENS_RUNSTDBY 0
#endif

// <o> Window Monitor Mode
// <i> Indicates which window monitor mode will be used
// <1=>temperature higher than low threshold
// <2=>temperature lower than low threshold
// <3=>temperature in the low and high threshold range
// <4=>temperature out of the low and high threshold range
// <5=>temperature higher than high threshold win hysteresis
// <6=>temperature lower than lower threshold win hysteresis
// <id> tsens_winmode
#ifndef CONF_TSENS_WINMODE
#define CONF_TSENS_WINMODE 4
#endif

// </e>

// <e> Calibration configurations
// <id> tsens_calibration_settings
#ifndef CONF_TSENS_CALIBRATION_SETTINGS
#define CONF_TSENS_CALIBRATION_SETTINGS 0
#endif

// <o> Temperature Calibration <0-63>
// <i> Temperature Calibration value
// <id> tsens_temperature_calibration
#ifndef CONF_TSENS_TCAL
#define CONF_TSENS_TCAL 0
#endif

// <o> Frequency Calibration <0-63>
// <i> Frequency Calibration value
// <id> tsens_frequency_calibration
#ifndef CONF_TSENS_FCAL
#define CONF_TSENS_FCAL 0
#endif

// <o> Gain Calibration <0-16777215>
// <i> Gain value when using a 48MHz as TSENS clock source.
// <id> tsens_gain_calibration
#ifndef CONF_TSENS_GAIN
#define CONF_TSENS_GAIN 960
#endif

// <o> Offset Calibration <0-16777215>
// <i> Overwrite Offset value
// <id> tsens_offset_calibration
#ifndef CONF_TSENS_OFFSET
#define CONF_TSENS_OFFSET 0
#endif

// </e>

#if CONF_TSENS_CALIBRATION_SETTINGS == 0
#define CONF_TSENS_CAL_FCAL ((TSENS_FUSES_FCAL_Msk & (*((uint32_t *)TSENS_FUSES_FCAL_ADDR))) >> TSENS_FUSES_FCAL_Pos)

#define CONF_TSENS_CAL_TCAL ((TSENS_FUSES_TCAL_Msk & (*((uint32_t *)TSENS_FUSES_TCAL_ADDR))) >> TSENS_FUSES_TCAL_Pos)

#define CONF_TSENS_CAL_GAIN_VAL                                                                                        \
	((TSENS_FUSES_GAIN_0_Msk & (*((uint32_t *)TSENS_FUSES_GAIN_0_ADDR))) >> TSENS_FUSES_GAIN_0_Pos)                    \
	    | (((TSENS_FUSES_GAIN_1_Msk & (*((uint32_t *)TSENS_FUSES_GAIN_1_ADDR))) >> TSENS_FUSES_GAIN_1_Pos) << 20)

#define CONF_TSENS_CAL_OFFSET                                                                                          \
	((TSENS_FUSES_OFFSET_Msk & (*((uint32_t *)TSENS_FUSES_OFFSET_ADDR))) >> TSENS_FUSES_OFFSET_Pos)

#else

#define CONF_TSENS_CAL_FCAL CONF_TSENS_FCAL
#define CONF_TSENS_CAL_TCAL CONF_TSENS_TCAL
#define CONF_TSENS_CAL_GAIN_VAL CONF_TSENS_GAIN
#define CONF_TSENS_CAL_OFFSET CONF_TSENS_OFFSET

#endif

#define CONF_TSENS_CAL_GAIN (CONF_TSENS_CAL_GAIN_VAL) * (CONF_GCLK_TSENS_FREQUENCY / 48000000.0f)

// <e> Event Control
// <id> tsens_event_settings
#ifndef CONF_TSENS_EVENT_CONFIG
#define CONF_TSENS_EVENT_CONFIG 0
#endif

// <q> Window Monitor Event Out
// <i> Enables event output on window monitor event (WINEO)
// <id> tsens_wineo
#ifndef CONF_TSENS_WINEO
#define CONF_TSENS_WINEO 0
#endif

// <q> Start Conversion Event Invert Enable
// <i> Inverts Start Conversion event input
// <id> tsens_startinv
#ifndef CONF_TSENS_STARTINV
#define CONF_TSENS_STARTINV 0
#endif

// <q> Start Conversion Event Input Enable
// <i> Enables Start Conversion Event input
// <id> tsens_startei
#ifndef CONF_TSENS_STARTEI
#define CONF_TSENS_STARTEI 0
#endif

// </e>

// <<< end of configuration section >>>

#endif // HPL_TSENS_CONFIG_H
