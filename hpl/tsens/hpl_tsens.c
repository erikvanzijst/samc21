/**
 * \file
 *
 * \brief Temperature Sensor functionality Implemention.
 *
 * Copyright (c) 2016-2018 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 *
 */
#include <compiler.h>
#include <utils_assert.h>
#include <hpl_temp_sync.h>
#include <hpl_temp_async.h>
#include <hpl_tsens_config.h>

/*!< Pointer to hpl device */
static struct _temp_async_device *_tsens_dev = NULL;

static inline int32_t _temp_init_calibration(void *const hw);
static inline void    _temp_enable(void *const hw);
static inline void    _temp_disable(void *const hw);
static inline void    _tsens_read_temp(void *hw, int32_t *temp);
static inline void    _temp_event_control_init(void *const hw);

/**
 * \brief              Initialize Temperature Sensor
 */
int32_t _temp_sync_init(struct _temp_sync_device *const dev, void *const hw)
{
	if (_temp_init_calibration(hw)) {
		return ERR_DENIED;
	}
	dev->hw = hw;
	hri_tsens_write_CTRLA_reg(hw, CONF_TSENS_RUNSTDBY << TSENS_CTRLA_RUNSTDBY_Pos);
	hri_tsens_write_CTRLC_reg(hw, 0);

	_temp_event_control_init(hw);

	return ERR_NONE;
}

/**
 * \brief              DeInitialize Temperature Sensor
 */
int32_t _temp_sync_deinit(struct _temp_sync_device *const dev)
{
	hri_tsens_set_CTRLA_SWRST_bit(dev->hw);
	dev->hw = NULL;
	return ERR_NONE;
}
/**
 * \brief              Initialize Temperature Sensor
 */
int32_t _temp_async_init(struct _temp_async_device *const dev, void *const hw)
{
	if (_temp_init_calibration(hw)) {
		return ERR_DENIED;
	}
	dev->hw = hw;
	hri_tsens_write_CTRLA_reg(hw, CONF_TSENS_RUNSTDBY << TSENS_CTRLA_RUNSTDBY_Pos);
	hri_tsens_write_CTRLC_reg(hw, TSENS_CTRLC_WINMODE(CONF_TSENS_WINMODE));

	/* Init IRQ */
	_tsens_dev = dev;
	NVIC_DisableIRQ(TSENS_IRQn);
	NVIC_ClearPendingIRQ(TSENS_IRQn);
	NVIC_EnableIRQ(TSENS_IRQn);

	_temp_event_control_init(hw);

	return ERR_NONE;
}

/**
 * \brief              DeInitialize Temperature Sensor
 */
int32_t _temp_async_deinit(struct _temp_async_device *const dev)
{
	NVIC_DisableIRQ(TSENS_IRQn);
	hri_tsens_set_CTRLA_SWRST_bit(dev->hw);
	dev->hw = NULL;
	return ERR_NONE;
}

/**
 * \brief              Enable Temperature Sensor
 */
int32_t _temp_sync_enable(struct _temp_sync_device *const dev)
{
	_temp_enable(dev->hw);
	return ERR_NONE;
}

/**
 * \brief              Disable Temperature Sensor
 */
int32_t _temp_sync_disable(struct _temp_sync_device *const dev)
{
	_temp_disable(dev->hw);
	return ERR_NONE;
}

/**
 * \brief              Enable Temperature Sensor
 */
int32_t _temp_async_enable(struct _temp_async_device *const dev)
{
	_temp_enable(dev->hw);
	return ERR_NONE;
}

/**
 * \brief              Disable Temperature Sensor
 */
int32_t _temp_async_disable(struct _temp_async_device *const dev)
{
	_temp_disable(dev->hw);
	return ERR_NONE;
}

/**
 * \brief              Read Temperature Value
 */
int32_t _temp_sync_read(struct _temp_sync_device *const dev, int32_t *const temp)
{
	hri_tsens_wait_for_sync(dev->hw, TSENS_SYNCBUSY_ENABLE);
	hri_tsens_write_CTRLB_reg(dev->hw, TSENS_CTRLB_START);
	while (!hri_tsens_get_interrupt_RESRDY_bit(dev->hw)) {
		if (hri_tsens_get_interrupt_OVF_bit(dev->hw)) {
			hri_tsens_clear_interrupt_OVF_bit(dev->hw);
			return ERR_OVERFLOW;
		}
	}

	_tsens_read_temp(dev->hw, temp);
	hri_tsens_clear_interrupt_RESRDY_bit(dev->hw);

	return ERR_NONE;
}

/**
 * \brief              Read Temperature Value
 */
int32_t _temp_async_read(struct _temp_async_device *const dev, int32_t *const temp)
{
	if (dev->temp) {
		return ERR_BUSY;
	}
	hri_tsens_write_CTRLB_reg(dev->hw, TSENS_CTRLB_START);
	dev->temp = temp;
	return ERR_NONE;
}

/**
 * \brief              Set temperature window monitor threshold
 */
int32_t _temp_async_set_window_monitor(struct _temp_async_device *const dev, const int32_t lower, const int32_t upper)
{
	bool enable;

	enable = hri_tsens_get_CTRLA_ENABLE_bit(dev->hw);
	if (enable) {
		hri_tsens_clear_CTRLA_ENABLE_bit(dev->hw);
		hri_tsens_wait_for_sync(dev->hw, TSENS_SYNCBUSY_ENABLE);
	}
	hri_tsens_write_WINLT_reg(dev->hw, lower);
	hri_tsens_write_WINUT_reg(dev->hw, upper);
	if (enable) {
		hri_tsens_set_CTRLA_ENABLE_bit(dev->hw);
	}
	return ERR_NONE;
}

/**
 * \brief              Start temperature window monitor
 */
int32_t _temp_async_start_window_monitor(struct _temp_async_device *const dev)
{
	hri_tsens_clear_CTRLA_ENABLE_bit(dev->hw);
	hri_tsens_wait_for_sync(dev->hw, TSENS_SYNCBUSY_ENABLE);
	hri_tsens_set_CTRLC_WINMODE_bf(dev->hw, CONF_TSENS_WINMODE);
	hri_tsens_set_CTRLC_FREERUN_bit(dev->hw);
	hri_tsens_set_CTRLA_ENABLE_bit(dev->hw);

	return ERR_NONE;
}

/**
 * \brief              Stop temperature window monitor
 */
int32_t _temp_async_stop_window_monitor(struct _temp_async_device *const dev)
{
	hri_tsens_clear_CTRLA_ENABLE_bit(dev->hw);
	hri_tsens_wait_for_sync(dev->hw, TSENS_SYNCBUSY_ENABLE);
	hri_tsens_write_CTRLC_reg(dev->hw, 0);

	return ERR_NONE;
}

/**
 * \brief Enable/disable temperature interrupt
 */
void _temp_async_set_irq_state(struct _temp_async_device *const dev, const enum _temp_async_callback_type type,
                               const bool state)
{
	if (type == _TEMP_ASYNC_READY) {
		hri_tsens_write_INTEN_RESRDY_bit(dev->hw, state);
		hri_tsens_write_INTEN_OVF_bit(dev->hw, state);
	} else if (type == _TEMP_ASYNC_WINDOW) {
		hri_tsens_write_INTEN_WINMON_bit(dev->hw, state);
	}
}

/**
 * Initialize TSENS calibration
 *
 * \param[in] dev      The pointer to device instance
 */
static inline int32_t _temp_init_calibration(void *const hw)
{
	if (!hri_tsens_is_syncing(hw, TSENS_SYNCBUSY_SWRST)) {
		if (hri_tsens_get_CTRLA_reg(hw, TSENS_CTRLA_ENABLE)) {
			hri_tsens_clear_CTRLA_ENABLE_bit(hw);
			hri_tsens_wait_for_sync(hw, TSENS_SYNCBUSY_ENABLE);
		}
		hri_tsens_write_CTRLA_reg(hw, TSENS_CTRLA_SWRST);
	}
	hri_tsens_wait_for_sync(hw, TSENS_SYNCBUSY_SWRST);

	hri_tsens_write_CAL_reg(hw, TSENS_CAL_TCAL(CONF_TSENS_CAL_TCAL) | TSENS_CAL_FCAL(CONF_TSENS_CAL_FCAL));
	hri_tsens_write_GAIN_reg(hw, CONF_TSENS_CAL_GAIN);
	hri_tsens_write_OFFSET_reg(hw, CONF_TSENS_CAL_OFFSET);

	return ERR_NONE;
}

/**
 * Enable Temperature Sensor
 *
 * \param[in] hw  The pointer to hardware instance
 */
static inline void _temp_enable(void *const hw)
{
	hri_tsens_set_CTRLA_ENABLE_bit(hw);
}

/**
 * Disable Temperature Sensor
 *
 * \param[in] hw  The pointer to hardware instance
 */
static inline void _temp_disable(void *const hw)
{
	hri_tsens_clear_CTRLA_ENABLE_bit(hw);
}

/**
 * Read temperature from VALUE register and convert to int32_t
 *
 * \param[in] hw  The pointer to hardware instance
 * \param[in] temp  The pointer to temperature value
 */
static inline void _tsens_read_temp(void *hw, int32_t *temp)
{
	*temp = hri_tsens_read_VALUE_VALUE_bf(hw);

	/* Convert temp to int32, since VALUE from register is 24 bits singed */
	if (*temp & 0x00800000) {
		*temp |= ~TSENS_VALUE_MASK;
	}
}

/**
 * \brief              Initialize Temperature Sensor Event Control
 */
static inline void _temp_event_control_init(void *const hw)
{
#if CONF_TSENS_EVENT_CONFIG == 1
	hri_tsens_write_EVCTRL_reg(hw,
	                           (CONF_TSENS_WINEO << TSENS_EVCTRL_WINEO_Pos)
	                               | (CONF_TSENS_STARTINV << TSENS_EVCTRL_STARTINV_Pos)
	                               | (CONF_TSENS_STARTEI << TSENS_EVCTRL_STARTEI_Pos));
#endif
}
