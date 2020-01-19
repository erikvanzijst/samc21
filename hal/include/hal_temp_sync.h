/**
 * \file
 *
 * \brief Temperature Sensor (Sync) functionality declaration.
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

#ifndef HAL_TEMP_SYNC_H_INCLUDED
#define HAL_TEMP_SYNC_H_INCLUDED

#include <hpl_temp_sync.h>
#include <utils_assert.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \addtogroup doc_driver_hal_temperature_sync
 *
 * @{
 */

struct temp_sync_descriptor {
	struct _temp_sync_device dev; /*!< Temperature Sensor HPL device descriptor */
};

/**
 * \brief              Initialize Temperature Sensor Descriptor
 *
 * \param[in] desc     Temperature Sensor Descriptor to be initialized
 * \param[in] hw       The pointer to the hardware instance
 */
int32_t temp_sync_init(struct temp_sync_descriptor *const descr, void *const hw);

/**
 * \brief              Deinitialize Temperature Sensor Descriptor
 *
 * \param[in] desc     Temperature Sensor Descriptor to be deinitialized
 */
int32_t temp_sync_deinit(struct temp_sync_descriptor *const descr);

/**
 * \brief              Enable Temperature Sensor
 *
 * \param[in] desc     Temperature Sensor Descriptor
 */
int32_t temp_sync_enable(struct temp_sync_descriptor *const descr);

/**
 * \brief              Disable Temperature Sensor
 *
 * \param[in] desc     Temperature Sensor Descriptor
 */
int32_t temp_sync_disable(struct temp_sync_descriptor *const descr);

/**
 * \brief              Read Temperature Value
 *
 * \param[in] desc     Temperature Sensor Descriptor
 * \param[in] temp     Temperature Value (Celsius)
 */
int32_t temp_sync_read(struct temp_sync_descriptor *const descr, int32_t *const temp);

/**
 * \brief Retrieve the current driver version
 *
 * \return Current driver version.
 */
uint32_t temp_sync_get_version(void);

/**@}*/

#ifdef __cplusplus
}
#endif

#endif /* HAL_TEMP_SYNC_H_INCLUDED */
