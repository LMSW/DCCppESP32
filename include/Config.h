/**********************************************************************
DCC++ BASE STATION FOR ESP32

COPYRIGHT (c) 2013-2016 Gregg E. Berman
COPYRIGHT (c) 2017 Mike Dunston

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see http://www.gnu.org/licenses
**********************************************************************/

/////////////////////////////////////////////////////////////////////////////////////
//
// DEFINE PORT TO USE FOR JMRI WiFi INTERFACE
//
#define DCCPP_CLIENT_PORT 2560

/////////////////////////////////////////////////////////////////////////////////////
//
// DEFINE HOSTNAME TO USE FOR WiFi CONNECTIONS AND mDNS BROADCASTS
//
#define HOSTNAME "DCCpp32"

/////////////////////////////////////////////////////////////////////////////////////
//
// DEFINE WHICH PINS ARE USED BY MAIN/PROG MOTOR SHIELDS
//
// CURRENT SENSE PIN MAPPINGS:
// ADC1_CHANNEL_0 : 36
// ADC1_CHANNEL_1 : 37 -- NOT USABLE
// ADC1_CHANNEL_2 : 38 -- NOT USABLE
// ADC1_CHANNEL_3 : 39
// ADC1_CHANNEL_4 : 32
// ADC1_CHANNEL_5 : 33
// ADC1_CHANNEL_6 : 34
// ADC1_CHANNEL_7 : 35
//
// MOST ESP32 BOARDS DO NOT EXPOSE GPIO38 so ADC1_CHANNEL_2 MAY NOT BE USABLE.
//
// SUPPORTED MOTORBOARD TYPES:
// ARDUINO_SHIELD : Arduino Motor shield Rev3 based on the L298 chip. Max Output 2A per channel https://store.arduino.cc/usa/arduino-motor-shield-rev3
// POLOLU         : Pololu MC33926 Motor Driver (shield or carrier). Max Output 2.5A per channel https://www.pololu.com/product/1213 / https://www.pololu.com/product/2503
// BTS7960B_5A    : Infineon Technologies BTS 7960 Motor Driver Module. Max Output 5A (43A actual max) https://www.infineon.com/dgdl/bts7960b-pb-final.pdf
// BTS7960B_10A   : Infineon Technologies BTS 7960 Motor Driver Module. Max Output 10A (43A actual max) https://www.infineon.com/dgdl/bts7960b-pb-final.pdf

// MAIN TRACK MOTORBOARD NAME
#define MOTORBOARD_NAME_MAIN "MAIN"
// MAIN TRACK NOTORBOARD ENABLED PIN
#define MOTORBOARD_ENABLE_PIN_MAIN 25
// MAIN TRACK MOTORBOARD CURRENT SENSE ADC PIN
#define MOTORBOARD_CURRENT_SENSE_MAIN ADC1_CHANNEL_0
// MAIN TRACK MOTORBOARD MOTOR_BOARD_TYPE
#define MOTORBOARD_TYPE_MAIN ARDUINO_SHIELD

// PROG TRACK MOTORBOARD NAME
#define MOTORBOARD_NAME_PROG "PROG"
// PROG TRACK NOTORBOARD ENABLED PIN
#define MOTORBOARD_ENABLE_PIN_PROG 23
// PROG TRACK MOTORBOARD CURRENT SENSE ADC PIN
#define MOTORBOARD_CURRENT_SENSE_PROG ADC1_CHANNEL_3
// PROG TRACK MOTORBOARD MOTOR_BOARD_TYPE
#define MOTORBOARD_TYPE_PROG ARDUINO_SHIELD

/////////////////////////////////////////////////////////////////////////////////////
//
// DEFINE WHICH PINS ARE USED FOR DCC SIGNAL GENERATION
//
// OPERATIONS TRACK DCC SIGNAL PIN
#define DCC_SIGNAL_PIN_OPERATIONS 19
// PROGRAMMING TRACK DCC SIGNAL PIN
#define DCC_SIGNAL_PIN_PROGRAMMING 18

/////////////////////////////////////////////////////////////////////////////////////
//
// DEFINE THE CURRENT SENSE ATTENUATION. THIS IS USED BY THE ADC SYSTEM TO SCALE
// THE CURRENT SENSE VALUES BASED ON THE MOTOR SHIELD.
//
// SUPPORTED VALUES: ADC_ATTEN_DB_11, ADC_ATTEN_DB_6, ADC_ATTEN_DB_2_5, ADC_ATTEN_DB_0
//
// IF LEFT UNDEFINED ADC_ATTEN_DB_11 WILL BE USED.

//#define ADC_CURRENT_ATTENUATION ADC_ATTEN_DB_11

/////////////////////////////////////////////////////////////////////////////////////
//
// DEFINE WiFi Parameters
//
#define WIFI_SSID ""
#define WIFI_PASSWORD ""

/////////////////////////////////////////////////////////////////////////////////////
//
// DEFINE STATIC IP ADDRESS DETAILS OR LEAVE COMMENTED FOR DHCP
//

//#define WIFI_STATIC_IP_ADDRESS "192.168.0.115"
//#define WIFI_STATIC_IP_GATEWAY "192.168.0.1"
//#define WIFI_STATIC_IP_SUBNET "255.255.255.0"

// WIFI_STATIC_IP_DNS is optional, if not defined the value below will be used
// automatically. This is a Google provided DNS server.
//#define WIFI_STATIC_IP_DNS "8.8.8.8"

/////////////////////////////////////////////////////////////////////////////////////
//
// DEFINE WHICH PINS ARE USED FOR S88 INTERFACE
//
// NOTE: The S88 Bus will require a data pin in addition to the above pins that
// are common to all S88 Busses.
//

//#define S88_ENABLED true
//#define S88_CLOCK_PIN 17
//#define S88_RESET_PIN 16
//#define S88_LOAD_PIN 27

// S88 sensors are dynamically assigned based on the BUS ID * S88_MAX_SENSORS_PER_BUS + S88_FIRST_SENSOR
// This define allows shifting the S88 Sensors to start at a default value, you
// can start them at zero or as below S88_MAX_SENSORS_PER_BUS (default).
// S88_MAX_SENSORS_PER_BUS is defined as 512.
//#define S88_FIRST_SENSOR S88_MAX_SENSORS_PER_BUS

/////////////////////////////////////////////////////////////////////////////////////
//
// DEFINE INFO SCREEN Parameters
//
// BOTH OLED AND LCD SCREENS ARE SUPPORTED

// For the Heltec or TTGO boards the below checks will automatically enable the OLED
// and configure it for use. To use this setup be sure to select the correct board
// type in platformio.ini:
// Heltec: heltec_wifi_kit_32 or heltec_wifi_lora_32
// TTGO: ttgo-lora32-v1
// D-duino-32: d-duino-32 (if available, if not use block below)
#if defined(OLED_SDA) && defined(OLED_SCL)
#define INFO_SCREEN_OLED true
#define OLED_CHIPSET SH1306
#define INFO_SCREEN_OLED_I2C_ADDRESS 0x3C
#define INFO_SCREEN_SDA_PIN OLED_SDA
#define INFO_SCREEN_SCL_PIN OLED_SCL
#ifdef OLED_RST
#define INFO_SCREEN_RESET_PIN OLED_RST
#endif
#else
// For the D-duino-32/WeMos (LilyGo) OLED board the following
// settings should be used if d-duino-32 is not available in platformio.ini
//#define INFO_SCREEN_OLED true
//#define OLED_CHIPSET SH1306
//#define INFO_SCREEN_OLED_I2C_ADDRESS 0x3C
//#define INFO_SCREEN_SDA_PIN 5
//#define INFO_SCREEN_SCL_PIN 4

// If the ESP32 board does not use standard SDA/SCL pins as defined in pins_arduino.h
// uncomment the next two lines and define the pins that need to be used instead.
//#define INFO_SCREEN_SDA_PIN 23
//#define INFO_SCREEN_SCL_PIN 22

// If the OLED screen requires a reset pulse on startup, uncomment the following line
// to enable the reset pulse support.
//#define INFO_SCREEN_RESET_PIN 15

// OLED SCREEN PARAMETERS
//#define INFO_SCREEN_OLED true
// OLED SUPPORTED CHIPSETS: SH1106, SH1306
//#define OLED_CHIPSET SH1106
//#define INFO_SCREEN_OLED_I2C_ADDRESS 0x3C
//#define INFO_SCREEN_OLED_VERTICAL_FLIP false
//#define INFO_SCREEN_OLED_LINES 5

// LCD SCREEN PARAMETERS
//#define INFO_SCREEN_LCD true
//#define INFO_SCREEN_LCD_I2C_ADDRESS 0x27
//#define INFO_SCREEN_LCD_LINES 4
//#define INFO_SCREEN_LCD_COLUMNS 20
#endif

/////////////////////////////////////////////////////////////////////////////////////
//
// Remote Sensors are enabled by default, the following parameters can be used
// to control their behavior.

//#define SCAN_REMOTE_SENSORS_ON_STARTUP true
//#define REMOTE_SENSORS_PREFIX "sensor"
//#define REMOTE_SENSORS_DECAY 60000
//#define REMOTE_SENSORS_FIRST_SENSOR 100

/////////////////////////////////////////////////////////////////////////////////////
//
// The following pins are considered reserved pins by Espressif and should not
// be used by applications:
// GPIO6, GPIO7, GPIO8, GPIO9, GPIO10, GPIO11 -- used by flash
// GPIO0, GPIO2, GPIO5, GPIO12, GPIO15 -- used as bootstrap pins
//
// details of these usages can be found in section 2.2 of:
// https://www.espressif.com/sites/default/files/documentation/esp-wroom-32_datasheet_en.pdf
//
// uncomment the following define to allow these pins to be used for sensors or
// outputs.

//#define ALLOW_USAGE_OF_RESTRICTED_GPIO_PINS


/////////////////////////////////////////////////////////////////////////////////////
//
// The HC12 is a radio receiver that was previously used by some throttles to
// wirelessly send packet data to the base station. Uncomment the define below
// to enable this functionality.

//#define HC12_RADIO_ENABLED true
//#define HC12_RADIO_BAUD 19200
//#define HC12_UART_NUM 1
//#define HC12_RX_PIN 16
//#define HC12_TX_PIN 17

/////////////////////////////////////////////////////////////////////////////////////
//
// The Nextion is an interface to the base station that provides a connected
// throttle, turnout control, programming track and general base station status.

//#define NEXTION_ENABLED true
//#define NEXTION_UART_NUM 2
//#define NEXTION_UART_BAUD 115200
//#define NEXTION_RX_PIN 14
//#define NEXTION_TX_PIN 27

/////////////////////////////////////////////////////////////////////////////////////
//
// Define the pins for an SD Card Module. This is used as part of the Locomotive
// Roster and dynamic configuration support.
//

//#define SD_CARD_ENABLED true
// if SD_CARD_USE_FSPI is enabled the MOSI, MISO and CLK pins are shared with
// the built in flash, only the SS pin is required to be defined. All others are
// defined as:
// SD_CARD_MOSI_PIN: SD1 (8)
// SD_CARD_MISO_PIN: SD0 (7)
// SD_CARD_CLK_PIN: CLK (6)
//#define SD_CARD_USE_FSPI true

// The SD_CARD_SS_PIN should be connected to the SD Card breakout module CS or
// SS pin, whichever is available
//#define SD_CARD_SS_PIN 5
//#define SD_CARD_MOSI_PIN 8
//#define SD_CARD_MISO_PIN 7
//#define SD_CARD_CLK_PIN 6

/////////////////////////////////////////////////////////////////////////////////////
//
// The LocoNet interface allows using many of the available LocoNet sensors, throttles,
// accessories, etc with this base station. It is still under active development, if
// you find a device that does not work please let us know.
//

//#define LOCONET_ENABLED true
//#define LOCONET_RX_PIN 16
//#define LOCONET_TX_PIN 17
//#define LOCONET_UART 1

/////////////////////////////////////////////////////////////////////////////////////