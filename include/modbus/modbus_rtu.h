/* SPDX-License-Identifier: MIT OR Apache-2.0 */

/*
 * modbus_rtu.h
 * (c) 2025 Diego Asanza f.asanza@gmail.com
 */

#ifndef MODBUS_RTU_H_FF363922_5961_4B3B_B7A7_4FA56794B9CD
#define MODBUS_RTU_H_FF363922_5961_4B3B_B7A7_4FA56794B9CD

#include <stdint.h>
#include <modbus/modbus.h>

#define MBRTU_MAX_PDU_SIZE 256

struct mbrtu_state {
    uint8_t buf[MBRTU_MAX_PDU_SIZE];
};

int
mbrtu_poll(const struct mb, const struct mbrtu_state* state);

#endif /* MODBUS_RTU_H_FF363922_5961_4B3B_B7A7_4FA56794B9CD */
