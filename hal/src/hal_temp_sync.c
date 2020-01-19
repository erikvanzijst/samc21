/**
 * \file
 *
 * \brief Temperature Sensor (Sync) functionality implementation.
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
#include <hal_temp_sync.h>
#include <utils_assert.h>

#define DRIVER_VERSION 0x00000001u

/**
 * \brief              Initialize Temperature Descriptor
 */
int32_t temp_sync_init(struct temp_sync_descriptor *const descr, void *const hw)
{
	ASSERT(descr && hw);
	return _temp_sync_init(&descr->dev, hw);
}

/**
 * \brief              Deinitialize Temperature Descriptor
 */
int32_t temp_sync_deinit(struct temp_sync_descriptor *const descr)
{
	ASSERT(descr);
	return _temp_sync_deinit(&descr->dev);
}

/**
 * \brief              Enable AES
 */
int32_t temp_sync_enable(struct temp_sync_descriptor *const descr)
{
	ASSERT(descr);
	return _temp_sync_enable(&descr->dev);
}

/**
 * \brief              Disable AES
 */
int32_t temp_sync_disable(struct temp_sync_descriptor *const descr)
{
	ASSERT(descr);
	return _temp_sync_disable(&descr->dev);
}

/**
 * \brief              Read Temperature Value
 */
int32_t temp_sync_read(struct temp_sync_descriptor *const descr, int32_t *const temp)
{
	ASSERT(descr && temp);
	return _temp_sync_read(&descr->dev, temp);
}

/**
 * \brief Retrieve the current driver version
 */
uint32_t temp_sync_get_version(void)
{
	return DRIVER_VERSION;
}
