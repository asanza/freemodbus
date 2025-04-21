/* SPDX-License-Identifier: MIT OR Apache-2.0 */

/*
 * modbus.h
 * (c) 2025 Diego Asanza f.asanza@gmail.com
 */

#ifndef MODBUS_H_E97861DA_3ECA_4C65_BFFC_69EDAFF05CA5
#define MODBUS_H_E97861DA_3ECA_4C65_BFFC_69EDAFF05CA5

#include <stdint.h>

#define MB_FC_READ_COILS                       0x01U
#define MB_FC_READ_DISCRETE_INPUTS             0x02U
#define MB_FC_READ_HOLDING_REGISTERS           0x03U
#define MB_FC_READ_INPUT_REGISTERS             0x04U
#define MB_FC_WRITE_SINGLE_COIL                0x05U
#define MB_FC_WRITE_SINGLE_REGISTER            0x06U
#define MB_FC_READ_EXCEPTION_STATUS            0x07U
#define MB_FC_DIAGNOSTICS                      0x08U
#define MB_FC_GET_COMM_EVT_COUNTER             0x0BU
#define MB_FC_GET_COMM_EVT_LOG                 0x0CU
#define MB_FC_WRITE_MULTIPLE_COILS             0x0FU
#define MB_FC_WRITE_MULTIPLE_REGISTERS         0x10U
#define MB_FC_REPORT_SLAVE_ID                  0x11U
#define MB_FC_READ_FILE_RECORD                 0x14U
#define MB_FC_WRITE_FILE_RECORD                0x15U
#define MB_FC_MASK_WRITE_REGISTER              0x16U
#define MB_FC_READ_WRITE_MULTIPLE_REGISTERS    0x17U
#define MB_FC_READ_FIFO_QUEUE                  0x18U
#define MB_FC_ENCAPSULATED_INTERFACE_TRANSPORT 0x2BU

#define MB_EC_ILLEGAL_FUNCTION                        0x01U
#define MB_EC_ILLEGAL_DATA_ADDRESS                    0x02U
#define MB_EC_ILLEGAL_DATA_VALUE                      0x03U
#define MB_EC_SERVER_DEVICE_FAILURE                   0x04U
#define MB_EC_ACKNOWLEDGE                             0x05U
#define MB_EC_SERVER_DEVICE_BUSY                      0x06U
#define MB_EC_MEMORY_PARITY_ERROR                     0x08U
#define MB_EC_GATEWAY_PATH_UNAVAILABLE                0x0AU
#define MB_EC_GATEWAY_TARGET_DEVICE_FAILED_TO_RESPOND 0x0BU

#define MB_ERROR_NONE      0x00U
#define MB_ERROR_EILLSTATE 0x02U

typedef int (*mb_handler_fn)(uint8_t *buf, uint16_t *len);

struct mb_handler {
    uint8_t       fc;
    mb_handler_fn fn;
};

struct mb {
    uint8_t             id;
    struct mb_handler  *handlers;
    uint8_t             handlers_len;
};

#endif /* MODBUS_H_E97861DA_3ECA_4C65_BFFC_69EDAFF05CA5 */
