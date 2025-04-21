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

typedef void (*mbrtu_txcb)(void* priv);
typedef void (*mbrtu_rxcb)(void* priv, uint8_t* buf, int len, int error);
typedef void (*mbrtu_tmrcb)(void* priv);

typedef int (*mbrtu_send_async)(uint8_t* buf, int len, mbrtu_txcb cb);
typedef int (*mbrtu_recv_async)(uint8_t* buf, int len, mbrtu_rxcb cb);
typedef int (*mbrtu_tmr_start)(uint32_t period, mbrtu_tmrcb cb);

struct mbrtu {
    struct mb mb;
    mbrtu_send_async send;
    mbrtu_recv_async  rcv;
    mbrtu_tmr_start   tmr;
};

struct mbrtu_state {
    uint8_t buf[MBRTU_MAX_PDU_SIZE];
};

int
mbrtu_poll(const struct mbrtu, const struct mbrtu_state* state);

#endif /* MODBUS_RTU_H_FF363922_5961_4B3B_B7A7_4FA56794B9CD */
