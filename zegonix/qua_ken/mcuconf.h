#pragma once

#include_next <mcuconf.h>

/* serial driver configuration */
#undef STM32_SERIAL_USE_USART6
#define STM32_SERIAL_USE_USART6 TRUE

/* system configuration */
#ifdef STM32_ST_USE_TIMER
#undef STM32_ST_USE_TIMER
#endif
#define STM32_ST_USE_TIMER 5

/* led driver configuration */
#ifdef STM32_PWM_USE_TIM2
#undef STM32_PWM_USE_TIM2
#endif
#define STM32_PWM_USE_TIM2 TRUE
