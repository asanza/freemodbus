/* SPDX-License-Identifier: MIT OR Apache-2.0 */

/*
 * modbus_rtu.h
 * (c) 2025 Diego Asanza f.asanza@gmail.com
 */

#ifndef MODBUS_RTU_H_FF363922_5961_4B3B_B7A7_4FA56794B9CD
#define MODBUS_RTU_H_FF363922_5961_4B3B_B7A7_4FA56794B9CD

#include <stdint.h>

int
mbrtu_on_data_arrived(uint8_t* buf, uint16_t len);

int
mbrtu_poll( void );

#endif /* MODBUS_RTU_H_FF363922_5961_4B3B_B7A7_4FA56794B9CD */
