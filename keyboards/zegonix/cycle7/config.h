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

/* clock configuration */
#ifdef STM32_HSECLK
#undef STM32_HSECLK
#endif // STM32_HSECLK
#define STM32_HSECLK           12000000U

#ifdef STM32_HSE_BYPASS
#undef STM32_HSE_BYPASS
#endif // STM32_HSE_BYPASS

/* configuration of indicator led */
#define WS2812_PWM_DRIVER         PWMD2
#define WS2812_PWM_CHANNEL        1
#define WS2812_PWM_PAL_MODE       1
#define WS2812_PWM_DMA_STREAM     STM32_DMA1_STREAM1
#define WS2812_PWM_DMA_CHANNEL    3

#define WS2812_PWM_TARGET_PERIOD  800000
#ifdef WS2812_RGBW
#undef WS2812_RGBW
#endif
#ifdef WS2812_EXTERNAL_PULLUP
#undef WS2812_EXTERNAL_PULLUP
#endif

#ifdef WS2812_PWM_COMPLEMENTARY_OUTPUT
#undef WS2812_PWM_COMPLEMENTARY_OUTPUT
#endif

// configuration of rgb light abstraction layer
#define RGBLIGHT_SLEEP
#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
