
#pragma once
#include_next <mcuconf.h>

/* clock configuration */
#ifdef STM32_PLLM_VALUE
#undef STM32_PLLM_VALUE
#endif
#define STM32_PLLM_VALUE 6

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
