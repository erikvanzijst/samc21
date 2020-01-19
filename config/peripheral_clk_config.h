/* Auto-generated config file peripheral_clk_config.h */
#ifndef PERIPHERAL_CLK_CONFIG_H
#define PERIPHERAL_CLK_CONFIG_H

// <<< Use Configuration Wizard in Context Menu >>>

// <y> ADC Clock Source
// <id> adc_gclk_selection

// <GCLK_PCHCTRL_GEN_GCLK0_Val"> Generic clock generator 0

// <GCLK_PCHCTRL_GEN_GCLK1_Val"> Generic clock generator 1

// <GCLK_PCHCTRL_GEN_GCLK2_Val"> Generic clock generator 2

// <GCLK_PCHCTRL_GEN_GCLK3_Val"> Generic clock generator 3

// <GCLK_PCHCTRL_GEN_GCLK4_Val"> Generic clock generator 4

// <GCLK_PCHCTRL_GEN_GCLK5_Val"> Generic clock generator 5

// <GCLK_PCHCTRL_GEN_GCLK6_Val"> Generic clock generator 6

// <GCLK_PCHCTRL_GEN_GCLK7_Val"> Generic clock generator 7

// <i> Select the clock source for ADC.
#ifndef CONF_GCLK_ADC0_SRC
#define CONF_GCLK_ADC0_SRC GCLK_PCHCTRL_GEN_GCLK0_Val
#endif

/**
 * \def CONF_GCLK_ADC0_FREQUENCY
 * \brief ADC0's Clock frequency
 */
#ifndef CONF_GCLK_ADC0_FREQUENCY
#define CONF_GCLK_ADC0_FREQUENCY 4000000
#endif

/**
 * \def CONF_CPU_FREQUENCY
 * \brief CPU's Clock frequency
 */
#ifndef CONF_CPU_FREQUENCY
#define CONF_CPU_FREQUENCY 4000000
#endif

// <y> RTC Clock Source
// <id> rtc_clk_selection
// <RTC_CLOCK_SOURCE"> RTC source
// <i> Select the clock source for RTC.
#ifndef CONF_GCLK_RTC_SRC
#define CONF_GCLK_RTC_SRC RTC_CLOCK_SOURCE
#endif

/**
 * \def CONF_GCLK_RTC_FREQUENCY
 * \brief RTC's Clock frequency
 */
#ifndef CONF_GCLK_RTC_FREQUENCY
#define CONF_GCLK_RTC_FREQUENCY 32768
#endif

// <y> TC Clock Source
// <id> tc_gclk_selection

// <GCLK_PCHCTRL_GEN_GCLK0_Val"> Generic clock generator 0

// <GCLK_PCHCTRL_GEN_GCLK1_Val"> Generic clock generator 1

// <GCLK_PCHCTRL_GEN_GCLK2_Val"> Generic clock generator 2

// <GCLK_PCHCTRL_GEN_GCLK3_Val"> Generic clock generator 3

// <GCLK_PCHCTRL_GEN_GCLK4_Val"> Generic clock generator 4

// <GCLK_PCHCTRL_GEN_GCLK5_Val"> Generic clock generator 5

// <GCLK_PCHCTRL_GEN_GCLK6_Val"> Generic clock generator 6

// <GCLK_PCHCTRL_GEN_GCLK7_Val"> Generic clock generator 7

// <i> Select the clock source for TC.
#ifndef CONF_GCLK_TC0_SRC
#define CONF_GCLK_TC0_SRC GCLK_PCHCTRL_GEN_GCLK0_Val
#endif

/**
 * \def CONF_GCLK_TC0_FREQUENCY
 * \brief TC0's Clock frequency
 */
#ifndef CONF_GCLK_TC0_FREQUENCY
#define CONF_GCLK_TC0_FREQUENCY 4000000
#endif

// <y> TC Clock Source
// <id> tc_gclk_selection

// <GCLK_PCHCTRL_GEN_GCLK0_Val"> Generic clock generator 0

// <GCLK_PCHCTRL_GEN_GCLK1_Val"> Generic clock generator 1

// <GCLK_PCHCTRL_GEN_GCLK2_Val"> Generic clock generator 2

// <GCLK_PCHCTRL_GEN_GCLK3_Val"> Generic clock generator 3

// <GCLK_PCHCTRL_GEN_GCLK4_Val"> Generic clock generator 4

// <GCLK_PCHCTRL_GEN_GCLK5_Val"> Generic clock generator 5

// <GCLK_PCHCTRL_GEN_GCLK6_Val"> Generic clock generator 6

// <GCLK_PCHCTRL_GEN_GCLK7_Val"> Generic clock generator 7

// <i> Select the clock source for TC.
#ifndef CONF_GCLK_TC1_SRC
#define CONF_GCLK_TC1_SRC GCLK_PCHCTRL_GEN_GCLK0_Val
#endif

/**
 * \def CONF_GCLK_TC1_FREQUENCY
 * \brief TC1's Clock frequency
 */
#ifndef CONF_GCLK_TC1_FREQUENCY
#define CONF_GCLK_TC1_FREQUENCY 4000000
#endif

// <y> TSENS Clock Source
// <id> tsens_gclk_selection

// <GCLK_PCHCTRL_GEN_GCLK0_Val"> Generic clock generator 0

// <GCLK_PCHCTRL_GEN_GCLK1_Val"> Generic clock generator 1

// <GCLK_PCHCTRL_GEN_GCLK2_Val"> Generic clock generator 2

// <GCLK_PCHCTRL_GEN_GCLK3_Val"> Generic clock generator 3

// <GCLK_PCHCTRL_GEN_GCLK4_Val"> Generic clock generator 4

// <GCLK_PCHCTRL_GEN_GCLK5_Val"> Generic clock generator 5

// <GCLK_PCHCTRL_GEN_GCLK6_Val"> Generic clock generator 6

// <GCLK_PCHCTRL_GEN_GCLK7_Val"> Generic clock generator 7

// <i> Select the clock source for TSENS.
#ifndef CONF_GCLK_TSENS_SRC
#define CONF_GCLK_TSENS_SRC GCLK_PCHCTRL_GEN_GCLK0_Val
#endif

/**
 * \def CONF_GCLK_TSENS_FREQUENCY
 * \brief TSENS's Clock frequency
 */
#ifndef CONF_GCLK_TSENS_FREQUENCY
#define CONF_GCLK_TSENS_FREQUENCY 4000000
#endif

// <<< end of configuration section >>>

#endif // PERIPHERAL_CLK_CONFIG_H
