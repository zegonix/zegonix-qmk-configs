// Copyright 2024 zegonix (@zegonix)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
#define NO_ACTION_ONESHOT

/* split settings */
#define	SPLIT_HAND_PIN_LOW_IS_LEFT
#define SERIAL_USART_FULL_DUPLEX     // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN      C6  // USART TX pin
#define SERIAL_USART_RX_PIN      C7  // USART RX pin
#define SERIAL_USART_DRIVER      SD6 // Select UART Driver for interface 6
#define SERIAL_USART_TX_PAL_MODE 8   // USART6 is Alternate Function 8 on C6/7
#define SERIAL_USART_RX_PAL_MODE 8

