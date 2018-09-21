
#ifndef OUR_SERVICE_H__
#define OUR_SERVICE_H__

#include <stdint.h>
#include "ble.h"
#include "ble_srv_common.h"
#include "app_error.h"
#include "app_pwm.h"

#define APP_TIMER_PRESCALER             0                                           /**< Value of the RTC1 PRESCALER register. */
#define APP_TIMER_OP_QUEUE_SIZE         4                                           /**< Size of timer operation queues. */

// FROM_SERVICE_TUTORIAL: Defining 16-bit service and 128-bit base UUIDs

#define BLE_UUID_POWERUP_SERVICE  0xF171
#define BLE_UUID_POWERUP_MOTOR    0x0010
#define BLE_UUID_POWERUP_RUDDER   0x0021
#define BLE_UUID_POWERUP_CHARGE   0x0040

#define BLE_UUID_POWERUP_SERVICE_BASE_UUID  {{0x86, 0xC3, 0x81, 0x0E, 0xF1, 0x71, 0x40, 0xD9, 0xA1, 0x17, 0x26, 0xB3, 0x00, 0x76, 0x8C, 0xD6}}
#define BLE_UUID_POWERUP_MOTOR_BASE_UUID    {{0x86, 0xC3, 0x81, 0x0E, 0x00, 0x10, 0x40, 0xD9, 0xA1, 0x17, 0x26, 0xB3, 0x00, 0x76, 0x8C, 0xD6}}
#define BLE_UUID_POWERUP_RUDDER_BASE_UUID   {{0x86, 0xC3, 0x81, 0x0E, 0x00, 0x21, 0x40, 0xD9, 0xA1, 0x17, 0x26, 0xB3, 0x00, 0x76, 0x8C, 0xD6}}
#define BLE_UUID_POWERUP_CHARGER_BASE_UUID  {{0x86, 0xC3, 0x81, 0x0E, 0x00, 0x40, 0x40, 0xD9, 0xA1, 0x17, 0x26, 0xB3, 0x00, 0x76, 0x8C, 0xD6}}


// ALREADY_DONE_FOR_YOU: Defining 16-bit characteristic UUID
#define BLE_UUID_OUR_CHARACTERISTC_UUID          0xBEEF // Just a random, but recognizable value

// This structure contains various status information for our service. 
// The name is based on the naming convention used in Nordics SDKs. 
// 'ble indicates that it is a Bluetooth Low Energy relevant structure and 
// os is short for Our Service). 
typedef struct
{
    uint16_t                    conn_handle;    /**< Handle of the current connection (as provided by the BLE stack, is BLE_CONN_HANDLE_INVALID if not in a connection).*/
    uint16_t                    service_handle; /**< Handle of Our Service (as provided by the BLE stack). */
    // OUR_JOB: Step 2.D, Add handles for the characteristic attributes to our struct
    ble_gatts_char_handles_t    char_handles;
    ble_gatts_char_handles_t    motor_handles;
    ble_gatts_char_handles_t    rudder_handles;
} ble_os_t;

/**@brief Function for handling BLE Stack events related to our service and characteristic.
 *
 * @details Handles all events from the BLE stack of interest to Our Service.
 *
 * @param[in]   p_our_service       Our Service structure.
 * @param[in]   p_ble_evt  Event received from the BLE stack.
 */
void ble_plane_service_on_ble_evt(ble_os_t * p_our_service, ble_evt_t * p_ble_evt);

/**@brief Function for initializing our new service.
 *
 * @param[in]   p_our_service       Pointer to Our Service structure.
 */
void plane_service_init(ble_os_t * p_our_service);
ret_code_t plane_pwm_channel_duty_set(app_pwm_t const * const p_instance,
                                  uint8_t channel, app_pwm_duty_t duty);

#endif  /* _ OUR_SERVICE_H__ */
