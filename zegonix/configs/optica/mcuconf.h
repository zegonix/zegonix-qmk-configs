#pragma once

#include_next <mcuconf.h>

#undef STM32_PLLXTPRE
#define STM32_PLLXTPRE STM32_PLLXTPRE_DIV2

