// SPDX-License-Identifier: GPL-2.0+
/*
 * Ralink / Mediatek RT288x/RT3xxx/MT76xx built-in hardware watchdog timer
 *
 * Copyright (C) 2018 Stefan Roese <sr@denx.de>
 *
 * Based on the Linux driver version which is:
 *   Copyright (C) 2011 Gabor Juhos <juhosg@openwrt.org>
 *   Copyright (C) 2013 John Crispin <blogic@openwrt.org>
 */

#include <common.h>
#include <dm.h>
#include <wdt.h>
#include <linux/io.h>
#include <asm-generic/gpio.h>

// GPIO pin = GPIO_WATCHDOG
// Timeout = CONFIG_AT91_HW_WDT_TIMEOUT seconds

void hw_watchdog_reset(void) 
{     
      gpio_set_value(GPIO_WATCHDOG, 0); 
	  mdelay(1000 * CONFIG_AT91_HW_WDT_TIMEOUT);
      gpio_set_value(GPIO_WATCHDOG, 1);
	  mdelay(1000 * CONFIG_AT91_HW_WDT_TIMEOUT);
} 
