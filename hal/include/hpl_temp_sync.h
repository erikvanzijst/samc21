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

#ifndef HPL_TEMP_SYNC_H_INCLUDED
#define HPL_TEMP_SYNC_H_INCLUDED

#include <utils_assert.h>

#ifdef __cplusplus
extern "C" {
#endif

struct _temp_sync_device {
	void *hw; /*!< Hardware module instance handler */
};

/**
 * \brief              Initialize Temperature Sesnor
 *
 * \param[in]  dev     The pointer to device instance
 * \param[in]  hw      The pointer to hardware instance
 */
int32_t _temp_sync_init(struct _temp_sync_device *const dev, void *const hw);

/**
 * \brief              Deinitialize Temperature Sesnor
 *
 * \param[in]  dev     The pointer to device instance
 */
int32_t _temp_sync_deinit(struct _temp_sync_device *const dev);

/**
 * \brief              Enable Temperature Sesnor
 *
 * \param[in]  dev     The pointer to device instance
 */
int32_t _temp_sync_enable(struct _temp_sync_device *const dev);

/**
 * \brief              Disable Temperature Sesnor
 *
 * \param[in]  dev     The pointer to device instance
 */
int32_t _temp_sync_disable(struct _temp_sync_device *const dev);

/**
 * \brief              Read Temperature Value
 *
 * \param[in] dev      The pointer to device instance
 * \param[in] temp     Temperature Value (Celsius)
 */
int32_t _temp_sync_read(struct _temp_sync_device *const dev, int32_t *const temp);

#ifdef __cplusplus
}
#endif

#endif /* HPL_TEMP_SYNC_H_INCLUDED */
