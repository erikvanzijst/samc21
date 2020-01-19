/**
 * \file
 *
 * \brief Temperature Sensor (Async) functionality declaration.
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

#ifndef HPL_TEMP_ASYNC_H_INCLUDED
#define HPL_TEMP_ASYNC_H_INCLUDED

#include <utils_assert.h>
#include <hpl_irq.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief Temperature Sensor HPL descriptor
 *
 * The Temperature HPL descriptor forward declaration.
 */
struct _temp_async_device;

/**
 * \brief Temperature Sensor callback names
 */
enum _temp_async_callback_type {
	_TEMP_ASYNC_READY, /*!< Temperature measure complete */
	_TEMP_ASYNC_WINDOW /*!< Temperature value reach the window condition */
};
/**
 * \brief Temperature read ready callback type
 *
 * \param[in] dev      The pointer to device instance
 * \param[in] state    Read state, ERR_NONE for read success
 */
typedef void (*_temp_ready_cb_t)(const struct _temp_async_device *const dev, int32_t state);

/**
 * \brief Temperature window callback type
 *
 * \param[in] dev      The pointer to device instance
 */
typedef void (*_temp_window_cb_t)(const struct _temp_async_device *const dev);

/**
 * \brief Temperature callback pointers structure
 */
struct _temp_async_callback {
	_temp_ready_cb_t  ready;  /*!< ready */
	_temp_window_cb_t window; /*!< window condition */
};

struct _temp_async_device {
	void *                      hw;   /*!< Hardware module instance handler */
	struct _temp_async_callback cb;   /*!< Callback handlers */
	struct _irq_descriptor      irq;  /*!< Interrupt descriptor */
	int32_t *                   temp; /*!< Temperature Value pointer */
};

/**
 * \brief              Initialize Temperature Sesnor
 *
 * \param[in]  dev     The pointer to device instance
 * \param[in]  hw      The pointer to hardware instance
 */
int32_t _temp_async_init(struct _temp_async_device *const dev, void *const hw);

/**
 * \brief              Deinitialize Temperature Sesnor
 *
 * \param[in]  dev     The pointer to device instance
 */
int32_t _temp_async_deinit(struct _temp_async_device *const dev);

/**
 * \brief              Enable Temperature Sesnor
 *
 * \param[in]  dev     The pointer to device instance
 */
int32_t _temp_async_enable(struct _temp_async_device *const dev);

/**
 * \brief              Disable Temperature Sesnor
 *
 * \param[in]  dev     The pointer to device instance
 */
int32_t _temp_async_disable(struct _temp_async_device *const dev);

/**
 * \brief              Read Temperature Value
 *
 * \param[in] dev      The pointer to device instance
 * \param[in] temp     Temperature Value (Celsius)
 */
int32_t _temp_async_read(struct _temp_async_device *const dev, int32_t *const temp);

/**
 * \brief              Set temperature window monitor threshold
 *
 * \param[in] dev      The pointer to device instance
 * \param[in] lower    lower temperature value threshold (Celsius)
 * \param[in] upper    upper temperature value threshold (Celsius)
 */
int32_t _temp_async_set_window_monitor(struct _temp_async_device *const dev, const int32_t lower, const int32_t upper);

/**
 * \brief              Start temperature window monitor
 *
 * \param[in] dev      The pointer to device instance
 */
int32_t _temp_async_start_window_monitor(struct _temp_async_device *const dev);

/**
 * \brief              Stop temperature window monitor
 *
 * \param[in] dev      The pointer to device instance
 */
int32_t _temp_async_stop_window_monitor(struct _temp_async_device *const dev);

/**
 * \brief Enable/disable temperature interrupt
 *
 * \param[in] dev      The pointer to device instance
 * \param[in] type     callback type
 * \param[in] state    flag to identy enable or disable releated interrupt
 */
void _temp_async_set_irq_state(struct _temp_async_device *const dev, const enum _temp_async_callback_type type,
                               const bool state);

#ifdef __cplusplus
}
#endif

#endif /* HPL_TEMP_ASYNC_H_INCLUDED */
