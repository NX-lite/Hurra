/*
 * Board header for Waveshare RP2350-USB-A.
 *
 * Key specs from Waveshare schematic:
 *   - RP2350A (QFN-60, 30 GPIO)
 *   - 2 MB QSPI flash (W25Q16JVUXIQ)
 *   - USB-C on native USB controller
 *   - USB-A host routed to PIO USB: DATA+ = GPIO12, DATA- = GPIO13
 *   - WS2812B RGB LED data on GPIO16
 *   - USB-A VBUS tied to VSYS, no GPIO-controlled power switch
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

// -----------------------------------------------------
// NOTE: THIS HEADER IS ALSO INCLUDED BY ASSEMBLER SO
//       SHOULD ONLY CONSIST OF PREPROCESSOR DIRECTIVES
// -----------------------------------------------------

#ifndef _BOARDS_WAVESHARE_RP2350_USB_A_H
#define _BOARDS_WAVESHARE_RP2350_USB_A_H

pico_board_cmake_set(PICO_PLATFORM, rp2350)

#ifndef PICO_XOSC_STARTUP_DELAY_MULTIPLIER
#define PICO_XOSC_STARTUP_DELAY_MULTIPLIER 64
#endif

#define WAVESHARE_RP2350_USB_A

// Waveshare RP2350-USB-A uses RP2350A.
#define PICO_RP2350A 1

// USB-A host connector through PIO USB.
#define WAVESHARE_RP2350_USB_A_USB_HOST_DP_PIN 12
#define WAVESHARE_RP2350_USB_A_USB_HOST_DM_PIN 13
#define WAVESHARE_RP2350_USB_A_USB_HOST_5V_PIN 255

// Board RGB LED.
#define WAVESHARE_RP2350_USB_A_NEOPIXEL_PIN 16

// --- UART ---
#ifndef PICO_DEFAULT_UART
#define PICO_DEFAULT_UART 0
#endif
#ifndef PICO_DEFAULT_UART_TX_PIN
#define PICO_DEFAULT_UART_TX_PIN 0
#endif
#ifndef PICO_DEFAULT_UART_RX_PIN
#define PICO_DEFAULT_UART_RX_PIN 1
#endif

// No separate visible single-color LED is present. Use a harmless exposed GPIO
// so existing status LED code can remain enabled without sharing the WS2812 pin.
#ifndef PICO_DEFAULT_LED_PIN
#define PICO_DEFAULT_LED_PIN 25
#endif

#ifndef PICO_DEFAULT_WS2812_PIN
#define PICO_DEFAULT_WS2812_PIN WAVESHARE_RP2350_USB_A_NEOPIXEL_PIN
#endif

// --- PIO USB ---
#define PICO_DEFAULT_PIO_USB_DP_PIN WAVESHARE_RP2350_USB_A_USB_HOST_DP_PIN

// --- FLASH ---
// Winbond W25Q16JVUXIQ (2 MB)
#define PICO_BOOT_STAGE2_CHOOSE_W25Q080 1

#ifndef PICO_FLASH_SPI_CLKDIV
#define PICO_FLASH_SPI_CLKDIV 2
#endif

pico_board_cmake_set_default(PICO_FLASH_SIZE_BYTES, (2 * 1024 * 1024))
#ifndef PICO_FLASH_SIZE_BYTES
#define PICO_FLASH_SIZE_BYTES (2 * 1024 * 1024)
#endif

pico_board_cmake_set_default(PICO_RP2350_A2_SUPPORTED, 1)
#ifndef PICO_RP2350_A2_SUPPORTED
#define PICO_RP2350_A2_SUPPORTED 1
#endif

#endif
