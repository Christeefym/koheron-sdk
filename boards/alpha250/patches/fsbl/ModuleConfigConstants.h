/** \file ModuleConfigConstants.h
 * \brief Addresses and constants for all module config data stored in module EEPROM.
 * Note that this file is automatically generated from EepromMemoryMaps.xml.
 * \date 07.01.15
 */


#pragma once

#include "StandardIncludes.h"

//-------------------------------------------------------------------------------------------------
// Definitions, typedefs and constants
//-------------------------------------------------------------------------------------------------


#define PRODUCT_FAMILY_CODE_MARS_MX1 0x0320
#define PRODUCT_FAMILY_CODE_MARS_MX2 0x0321
#define PRODUCT_FAMILY_CODE_MERCURY_CA1 0x0322
#define PRODUCT_FAMILY_CODE_MARS_ZX2 0x0329
#define PRODUCT_FAMILY_CODE_MARS_ZX3 0x0323
#define PRODUCT_FAMILY_CODE_MARS_AX3 0x0324
#define PRODUCT_FAMILY_CODE_MERCURY_KX1 0x0325
#define PRODUCT_FAMILY_CODE_MERCURY_SA1 0x0326
#define PRODUCT_FAMILY_CODE_MERCURY_SA2 0x032A
#define PRODUCT_FAMILY_CODE_MERCURY_ZX1 0x0327
#define PRODUCT_FAMILY_CODE_MERCURY_ZX5 0x0328
#define MODULE_INFO_ADDRESS_SERIAL_NUMBER 0x00
#define MODULE_INFO_ADDRESS_PRODUCT_NUMBER 0x04
#define MODULE_INFO_ADDRESS_MAC_ADDRESS 0x10

/// Mask defining the position of the product family code in the 32-bit product number.
#define PRODUCT_FAMILY_CODE_MASK 0xFFFF0000
#define PRODUCT_FAMILY_CODE_BIT_OFFSET 16

/// Mask defining the position of the product subtype in the 32-bit product number.
#define PRODUCT_SUBTYPE_MASK 0x0000FF00
#define PRODUCT_SUBTYPE_BIT_OFFSET 8

/// Mask defining the position of the product revision number in the 32-bit product number.
#define REVISION_NUMBER_MASK 0x000000FF



#define MAX_MODULE_NAME_LENGTH_CHARACTERS 32
#define CONFIGURATION_PROPERTY_NAME_MAXLENGTH_CHARACTERS 64


/// Struct for constituent product number elements.
typedef struct ProductNumberInfo_t
{
    uint16_t productFamilyCode;
    uint8_t productSubtype;
    uint8_t revisionNumber;
} ProductNumberInfo_t;


typedef struct
{
    uint8_t value;
    char meaning[CONFIGURATION_PROPERTY_NAME_MAXLENGTH_CHARACTERS];
} ModulePropertyValueKey_t;


/**
 * \brief Struct used for module config properties.
 *
 * Note that the valueAsStored and value fields are not constant; these values
 * are calculated when the module EEPROM config data is read and parsed using
 * Eeprom_ReadModuleConfig().
 */
typedef struct
{
	/// Description of the configuration property; i.e. "FPGA type"
    const char description[CONFIGURATION_PROPERTY_NAME_MAXLENGTH_CHARACTERS];

    /// The address where the config property is stored in EEPROM
    const uint8_t address;

    /// The length of the stored property, in bits
    const uint8_t lengthBits;

    /// Zero-based start bit of the stored property, in the byte where it's stored
    const uint8_t startBit;

    /// Zero-based end bit of the stored property, in the byte where it's stored
    const uint8_t endBit;

    /// Minimum value for the property
    const uint8_t minValue;

    /// Maximum value for the property
    const uint8_t maxValue;

    /// Resolution for memory sizes; this is zero for other properties
    const uint8_t resolution;

    /// The number of keyed values (i.e. raw values which have corresponding text values)
    const uint8_t keyValueCount;

    /// Pointer to array of keyed values
    const ModulePropertyValueKey_t* pValueKey;

    /// The value of the property, as stored in EEPROM
    uint8_t valueAsStored;

    /// The value of the property, translated when a resolution is present
    uint32_t value;
} ModuleConfigProperty_t;


/**
 * \brief Parse a raw 32-bit product number to its constituent parts.
 *
 * @param productNumber 	32-bit product number
 * @return					Struct containing decoded values
 */
static inline ProductNumberInfo_t ParseProductNumber(uint32_t productNumber)
{
    ProductNumberInfo_t productNumberInfo;

    productNumberInfo.productFamilyCode = (productNumber & PRODUCT_FAMILY_CODE_MASK) >> PRODUCT_FAMILY_CODE_BIT_OFFSET;
    productNumberInfo.productSubtype = (productNumber & PRODUCT_SUBTYPE_MASK) >> PRODUCT_SUBTYPE_BIT_OFFSET;
    productNumberInfo.revisionNumber = productNumber & REVISION_NUMBER_MASK;

    return productNumberInfo;
}

//-------------------------------------------------------------------------------------------------
// Global variables
//-------------------------------------------------------------------------------------------------

/// Pointer to array of configuration properties.
extern ModuleConfigProperty_t* g_pConfigProperties;

//-------------------------------------------------------------------------------------------------
// Mars AX3
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MARS_AX3
extern char MARS_AX3_MODULE_NAME[];
extern ModuleConfigProperty_t MARS_AX3_CONFIG_PROPERTIES[];
extern const ModulePropertyValueKey_t MARS_AX3_FPGA_TYPE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_AX3_TEMPERATURE_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_AX3_POWER_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_AX3_ETHERNET_SPEED_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_AX3_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[];
#define MARS_AX3_MAX_CONFIG_PROPERTY_NAME_LENGTH_CHARACTERS 25
#define MARS_AX3_CONFIG_PROPERTIES_LENGTH_BYTES 4
#define MARS_AX3_CONFIG_PROPERTIES_START_ADDRESS 0x00000008
#define MARS_AX3_PROPERTY_COUNT 10
#define MARS_AX3_CONFIG_PROPERTY_INDEX_FPGA_TYPE 0
#define MARS_AX3_CONFIG_PROPERTY_INDEX_FPGA_SPEED_GRADE 1
#define MARS_AX3_CONFIG_PROPERTY_INDEX_TEMPERATURE_GRADE 2
#define MARS_AX3_CONFIG_PROPERTY_INDEX_POWER_GRADE 3
#define MARS_AX3_CONFIG_PROPERTY_INDEX_ETHERNET_PORT_COUNT 4
#define MARS_AX3_CONFIG_PROPERTY_INDEX_ETHERNET_SPEED 5
#define MARS_AX3_CONFIG_PROPERTY_INDEX_REAL_TIME_CLOCK_EQUIPPED 6
#define MARS_AX3_CONFIG_PROPERTY_INDEX_USB_DEVICE_PORT_COUNT 7
#define MARS_AX3_CONFIG_PROPERTY_INDEX_DDR3_RAM_SIZE_MB 8
#define MARS_AX3_CONFIG_PROPERTY_INDEX_SPI_FLASH_SIZE_MB 9
#endif

//-------------------------------------------------------------------------------------------------
// Mars MX1
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MARS_MX1
extern char MARS_MX1_MODULE_NAME[];
extern ModuleConfigProperty_t MARS_MX1_CONFIG_PROPERTIES[];
extern const ModulePropertyValueKey_t MARS_MX1_FPGA_TYPE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_MX1_TEMPERATURE_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_MX1_POWER_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_MX1_ETHERNET_SPEED_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_MX1_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_MX1_CURRENT_MONITOR_EQUIPPED_VALUE_KEY[];
#define MARS_MX1_MAX_CONFIG_PROPERTY_NAME_LENGTH_CHARACTERS 25
#define MARS_MX1_CONFIG_PROPERTIES_LENGTH_BYTES 4
#define MARS_MX1_CONFIG_PROPERTIES_START_ADDRESS 0x00000008
#define MARS_MX1_PROPERTY_COUNT 11
#define MARS_MX1_CONFIG_PROPERTY_INDEX_FPGA_TYPE 0
#define MARS_MX1_CONFIG_PROPERTY_INDEX_FPGA_SPEED_GRADE 1
#define MARS_MX1_CONFIG_PROPERTY_INDEX_TEMPERATURE_GRADE 2
#define MARS_MX1_CONFIG_PROPERTY_INDEX_POWER_GRADE 3
#define MARS_MX1_CONFIG_PROPERTY_INDEX_ETHERNET_PORT_COUNT 4
#define MARS_MX1_CONFIG_PROPERTY_INDEX_ETHERNET_SPEED 5
#define MARS_MX1_CONFIG_PROPERTY_INDEX_REAL_TIME_CLOCK_EQUIPPED 6
#define MARS_MX1_CONFIG_PROPERTY_INDEX_CURRENT_MONITOR_EQUIPPED 7
#define MARS_MX1_CONFIG_PROPERTY_INDEX_USB_DEVICE_PORT_COUNT 8
#define MARS_MX1_CONFIG_PROPERTY_INDEX_DDR2_RAM_SIZE_MB 9
#define MARS_MX1_CONFIG_PROPERTY_INDEX_SPI_FLASH_SIZE_MB 10
#endif

//-------------------------------------------------------------------------------------------------
// Mars MX2
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MARS_MX2
extern char MARS_MX2_MODULE_NAME[];
extern ModuleConfigProperty_t MARS_MX2_CONFIG_PROPERTIES[];
extern const ModulePropertyValueKey_t MARS_MX2_FPGA_TYPE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_MX2_TEMPERATURE_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_MX2_POWER_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_MX2_ETHERNET_SPEED_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_MX2_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_MX2_CURRENT_MONITOR_EQUIPPED_VALUE_KEY[];
#define MARS_MX2_MAX_CONFIG_PROPERTY_NAME_LENGTH_CHARACTERS 25
#define MARS_MX2_CONFIG_PROPERTIES_LENGTH_BYTES 4
#define MARS_MX2_CONFIG_PROPERTIES_START_ADDRESS 0x00000008
#define MARS_MX2_PROPERTY_COUNT 11
#define MARS_MX2_CONFIG_PROPERTY_INDEX_FPGA_TYPE 0
#define MARS_MX2_CONFIG_PROPERTY_INDEX_FPGA_SPEED_GRADE 1
#define MARS_MX2_CONFIG_PROPERTY_INDEX_TEMPERATURE_GRADE 2
#define MARS_MX2_CONFIG_PROPERTY_INDEX_POWER_GRADE 3
#define MARS_MX2_CONFIG_PROPERTY_INDEX_ETHERNET_PORT_COUNT 4
#define MARS_MX2_CONFIG_PROPERTY_INDEX_ETHERNET_SPEED 5
#define MARS_MX2_CONFIG_PROPERTY_INDEX_REAL_TIME_CLOCK_EQUIPPED 6
#define MARS_MX2_CONFIG_PROPERTY_INDEX_CURRENT_MONITOR_EQUIPPED 7
#define MARS_MX2_CONFIG_PROPERTY_INDEX_USB_DEVICE_PORT_COUNT 8
#define MARS_MX2_CONFIG_PROPERTY_INDEX_DDR2_RAM_SIZE_MB 9
#define MARS_MX2_CONFIG_PROPERTY_INDEX_SPI_FLASH_SIZE_MB 10
#endif

//-------------------------------------------------------------------------------------------------
// Mars ZX2
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MARS_ZX2
extern char MARS_ZX2_MODULE_NAME[];
extern ModuleConfigProperty_t MARS_ZX2_CONFIG_PROPERTIES[];
extern const ModulePropertyValueKey_t MARS_ZX2_SOC_TYPE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_ZX2_TEMPERATURE_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_ZX2_POWER_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_ZX2_ETHERNET_SPEED_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_ZX2_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[];
#define MARS_ZX2_MAX_CONFIG_PROPERTY_NAME_LENGTH_CHARACTERS 25
#define MARS_ZX2_CONFIG_PROPERTIES_LENGTH_BYTES 4
#define MARS_ZX2_CONFIG_PROPERTIES_START_ADDRESS 0x00000008
#define MARS_ZX2_PROPERTY_COUNT 10
#define MARS_ZX2_CONFIG_PROPERTY_INDEX_SOC_TYPE 0
#define MARS_ZX2_CONFIG_PROPERTY_INDEX_SOC_SPEED_GRADE 1
#define MARS_ZX2_CONFIG_PROPERTY_INDEX_TEMPERATURE_GRADE 2
#define MARS_ZX2_CONFIG_PROPERTY_INDEX_POWER_GRADE 3
#define MARS_ZX2_CONFIG_PROPERTY_INDEX_ETHERNET_PORT_COUNT 4
#define MARS_ZX2_CONFIG_PROPERTY_INDEX_ETHERNET_SPEED 5
#define MARS_ZX2_CONFIG_PROPERTY_INDEX_REAL_TIME_CLOCK_EQUIPPED 6
#define MARS_ZX2_CONFIG_PROPERTY_INDEX_USB_DEVICE_PORT_COUNT 7
#define MARS_ZX2_CONFIG_PROPERTY_INDEX_DDR3_RAM_SIZE_MB 8
#define MARS_ZX2_CONFIG_PROPERTY_INDEX_SPI_FLASH_SIZE_MB 9
#endif

//-------------------------------------------------------------------------------------------------
// Mars ZX3
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MARS_ZX3
extern char MARS_ZX3_MODULE_NAME[];
extern ModuleConfigProperty_t MARS_ZX3_CONFIG_PROPERTIES[];
extern const ModulePropertyValueKey_t MARS_ZX3_SOC_TYPE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_ZX3_TEMPERATURE_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_ZX3_POWER_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_ZX3_ETHERNET_SPEED_VALUE_KEY[];
extern const ModulePropertyValueKey_t MARS_ZX3_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[];
#define MARS_ZX3_MAX_CONFIG_PROPERTY_NAME_LENGTH_CHARACTERS 25
#define MARS_ZX3_CONFIG_PROPERTIES_LENGTH_BYTES 5
#define MARS_ZX3_CONFIG_PROPERTIES_START_ADDRESS 0x00000008
#define MARS_ZX3_PROPERTY_COUNT 11
#define MARS_ZX3_CONFIG_PROPERTY_INDEX_SOC_TYPE 0
#define MARS_ZX3_CONFIG_PROPERTY_INDEX_SOC_SPEED_GRADE 1
#define MARS_ZX3_CONFIG_PROPERTY_INDEX_TEMPERATURE_GRADE 2
#define MARS_ZX3_CONFIG_PROPERTY_INDEX_POWER_GRADE 3
#define MARS_ZX3_CONFIG_PROPERTY_INDEX_ETHERNET_PORT_COUNT 4
#define MARS_ZX3_CONFIG_PROPERTY_INDEX_ETHERNET_SPEED 5
#define MARS_ZX3_CONFIG_PROPERTY_INDEX_REAL_TIME_CLOCK_EQUIPPED 6
#define MARS_ZX3_CONFIG_PROPERTY_INDEX_USB_DEVICE_PORT_COUNT 7
#define MARS_ZX3_CONFIG_PROPERTY_INDEX_DDR3_RAM_SIZE_MB 8
#define MARS_ZX3_CONFIG_PROPERTY_INDEX_SPI_FLASH_SIZE_MB 9
#define MARS_ZX3_CONFIG_PROPERTY_INDEX_NAND_FLASH_SIZE_MB 10
#endif

//-------------------------------------------------------------------------------------------------
// Mercury CA1
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_CA1
extern char MERCURY_CA1_MODULE_NAME[];
extern ModuleConfigProperty_t MERCURY_CA1_CONFIG_PROPERTIES[];
extern const ModulePropertyValueKey_t MERCURY_CA1_FPGA_TYPE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_CA1_TEMPERATURE_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_CA1_POWER_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_CA1_ETHERNET_SPEED_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_CA1_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_CA1_CURRENT_MONITOR_EQUIPPED_VALUE_KEY[];
#define MERCURY_CA1_MAX_CONFIG_PROPERTY_NAME_LENGTH_CHARACTERS 25
#define MERCURY_CA1_CONFIG_PROPERTIES_LENGTH_BYTES 4
#define MERCURY_CA1_CONFIG_PROPERTIES_START_ADDRESS 0x00000008
#define MERCURY_CA1_PROPERTY_COUNT 11
#define MERCURY_CA1_CONFIG_PROPERTY_INDEX_FPGA_TYPE 0
#define MERCURY_CA1_CONFIG_PROPERTY_INDEX_FPGA_SPEED_GRADE 1
#define MERCURY_CA1_CONFIG_PROPERTY_INDEX_TEMPERATURE_GRADE 2
#define MERCURY_CA1_CONFIG_PROPERTY_INDEX_POWER_GRADE 3
#define MERCURY_CA1_CONFIG_PROPERTY_INDEX_ETHERNET_PORT_COUNT 4
#define MERCURY_CA1_CONFIG_PROPERTY_INDEX_ETHERNET_SPEED 5
#define MERCURY_CA1_CONFIG_PROPERTY_INDEX_REAL_TIME_CLOCK_EQUIPPED 6
#define MERCURY_CA1_CONFIG_PROPERTY_INDEX_CURRENT_MONITOR_EQUIPPED 7
#define MERCURY_CA1_CONFIG_PROPERTY_INDEX_USB_DEVICE_PORT_COUNT 8
#define MERCURY_CA1_CONFIG_PROPERTY_INDEX_DDR2_RAM_SIZE_MB 9
#define MERCURY_CA1_CONFIG_PROPERTY_INDEX_SPI_FLASH_SIZE_MB 10
#endif

//-------------------------------------------------------------------------------------------------
// Mercury KX1
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_KX1
extern char MERCURY_KX1_MODULE_NAME[];
extern ModuleConfigProperty_t MERCURY_KX1_CONFIG_PROPERTIES[];
extern const ModulePropertyValueKey_t MERCURY_KX1_FPGA_TYPE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_KX1_TEMPERATURE_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_KX1_POWER_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_KX1_ETHERNET_SPEED_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_KX1_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[];
#define MERCURY_KX1_MAX_CONFIG_PROPERTY_NAME_LENGTH_CHARACTERS 29
#define MERCURY_KX1_CONFIG_PROPERTIES_LENGTH_BYTES 5
#define MERCURY_KX1_CONFIG_PROPERTIES_START_ADDRESS 0x00000008
#define MERCURY_KX1_PROPERTY_COUNT 11
#define MERCURY_KX1_CONFIG_PROPERTY_INDEX_FPGA_TYPE 0
#define MERCURY_KX1_CONFIG_PROPERTY_INDEX_FPGA_SPEED_GRADE 1
#define MERCURY_KX1_CONFIG_PROPERTY_INDEX_TEMPERATURE_GRADE 2
#define MERCURY_KX1_CONFIG_PROPERTY_INDEX_POWER_GRADE 3
#define MERCURY_KX1_CONFIG_PROPERTY_INDEX_ETHERNET_PORT_COUNT 4
#define MERCURY_KX1_CONFIG_PROPERTY_INDEX_ETHERNET_SPEED 5
#define MERCURY_KX1_CONFIG_PROPERTY_INDEX_REAL_TIME_CLOCK_EQUIPPED 6
#define MERCURY_KX1_CONFIG_PROPERTY_INDEX_USB_DEVICE_PORT_COUNT 7
#define MERCURY_KX1_CONFIG_PROPERTY_INDEX_DDR3_RAM_SIZE_MB 8
#define MERCURY_KX1_CONFIG_PROPERTY_INDEX_SPI_FLASH_SIZE_MB 9
#define MERCURY_KX1_CONFIG_PROPERTY_INDEX_SECONDARY_DDR3_RAM_SIZE_MB 10
#endif

//-------------------------------------------------------------------------------------------------
// Mercury SA1
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_SA1
extern char MERCURY_SA1_MODULE_NAME[];
extern ModuleConfigProperty_t MERCURY_SA1_CONFIG_PROPERTIES[];
extern const ModulePropertyValueKey_t MERCURY_SA1_SOC_TYPE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_SA1_TEMPERATURE_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_SA1_POWER_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_SA1_ETHERNET_SPEED_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_SA1_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[];
#define MERCURY_SA1_MAX_CONFIG_PROPERTY_NAME_LENGTH_CHARACTERS 25
#define MERCURY_SA1_CONFIG_PROPERTIES_LENGTH_BYTES 4
#define MERCURY_SA1_CONFIG_PROPERTIES_START_ADDRESS 0x00000008
#define MERCURY_SA1_PROPERTY_COUNT 10
#define MERCURY_SA1_CONFIG_PROPERTY_INDEX_SOC_TYPE 0
#define MERCURY_SA1_CONFIG_PROPERTY_INDEX_SOC_SPEED_GRADE 1
#define MERCURY_SA1_CONFIG_PROPERTY_INDEX_TEMPERATURE_GRADE 2
#define MERCURY_SA1_CONFIG_PROPERTY_INDEX_POWER_GRADE 3
#define MERCURY_SA1_CONFIG_PROPERTY_INDEX_ETHERNET_PORT_COUNT 4
#define MERCURY_SA1_CONFIG_PROPERTY_INDEX_ETHERNET_SPEED 5
#define MERCURY_SA1_CONFIG_PROPERTY_INDEX_REAL_TIME_CLOCK_EQUIPPED 6
#define MERCURY_SA1_CONFIG_PROPERTY_INDEX_USB_PORT_COUNT 7
#define MERCURY_SA1_CONFIG_PROPERTY_INDEX_DDR3L_RAM_SIZE_MB 8
#define MERCURY_SA1_CONFIG_PROPERTY_INDEX_SPI_FLASH_SIZE_MB 9
#endif

//-------------------------------------------------------------------------------------------------
// Mercury SA2
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_SA2
extern char MERCURY_SA2_MODULE_NAME[];
extern ModuleConfigProperty_t MERCURY_SA2_CONFIG_PROPERTIES[];
extern const ModulePropertyValueKey_t MERCURY_SA2_SOC_TYPE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_SA2_TEMPERATURE_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_SA2_POWER_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_SA2_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[];
#define MERCURY_SA2_MAX_CONFIG_PROPERTY_NAME_LENGTH_CHARACTERS 28
#define MERCURY_SA2_CONFIG_PROPERTIES_LENGTH_BYTES 4
#define MERCURY_SA2_CONFIG_PROPERTIES_START_ADDRESS 0x00000008
#define MERCURY_SA2_PROPERTY_COUNT 11
#define MERCURY_SA2_CONFIG_PROPERTY_INDEX_SOC_TYPE 0
#define MERCURY_SA2_CONFIG_PROPERTY_INDEX_SOC_SPEED_GRADE 1
#define MERCURY_SA2_CONFIG_PROPERTY_INDEX_TEMPERATURE_GRADE 2
#define MERCURY_SA2_CONFIG_PROPERTY_INDEX_POWER_GRADE 3
#define MERCURY_SA2_CONFIG_PROPERTY_INDEX_FAST_ETHERNET_PORT_COUNT 4
#define MERCURY_SA2_CONFIG_PROPERTY_INDEX_GIGABIT_ETHERNET_PORT_COUNT 5
#define MERCURY_SA2_CONFIG_PROPERTY_INDEX_REAL_TIME_CLOCK_EQUIPPED 6
#define MERCURY_SA2_CONFIG_PROPERTY_INDEX_USB_2_0_PORT_COUNT 7
#define MERCURY_SA2_CONFIG_PROPERTY_INDEX_USB_3_0_PORT_COUNT 8
#define MERCURY_SA2_CONFIG_PROPERTY_INDEX_DDR3L_RAM_SIZE_MB 9
#define MERCURY_SA2_CONFIG_PROPERTY_INDEX_SPI_FLASH_SIZE_MB 10
#endif

//-------------------------------------------------------------------------------------------------
// Mercury ZX1
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_ZX1
extern char MERCURY_ZX1_MODULE_NAME[];
extern ModuleConfigProperty_t MERCURY_ZX1_CONFIG_PROPERTIES[];
extern const ModulePropertyValueKey_t MERCURY_ZX1_SOC_TYPE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_ZX1_TEMPERATURE_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_ZX1_POWER_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_ZX1_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[];
#define MERCURY_ZX1_MAX_CONFIG_PROPERTY_NAME_LENGTH_CHARACTERS 28
#define MERCURY_ZX1_CONFIG_PROPERTIES_LENGTH_BYTES 5
#define MERCURY_ZX1_CONFIG_PROPERTIES_START_ADDRESS 0x00000008
#define MERCURY_ZX1_PROPERTY_COUNT 12
#define MERCURY_ZX1_CONFIG_PROPERTY_INDEX_SOC_TYPE 0
#define MERCURY_ZX1_CONFIG_PROPERTY_INDEX_SOC_SPEED_GRADE 1
#define MERCURY_ZX1_CONFIG_PROPERTY_INDEX_TEMPERATURE_GRADE 2
#define MERCURY_ZX1_CONFIG_PROPERTY_INDEX_POWER_GRADE 3
#define MERCURY_ZX1_CONFIG_PROPERTY_INDEX_GIGABIT_ETHERNET_PORT_COUNT 4
#define MERCURY_ZX1_CONFIG_PROPERTY_INDEX_FAST_ETHERNET_PORT_COUNT 5
#define MERCURY_ZX1_CONFIG_PROPERTY_INDEX_REAL_TIME_CLOCK_EQUIPPED 6
#define MERCURY_ZX1_CONFIG_PROPERTY_INDEX_USB_DEVICE_PORT_COUNT 7
#define MERCURY_ZX1_CONFIG_PROPERTY_INDEX_DDR3L_RAM_PS_SIZE_MB 8
#define MERCURY_ZX1_CONFIG_PROPERTY_INDEX_DDR3L_RAM_PL_SIZE_MB 9
#define MERCURY_ZX1_CONFIG_PROPERTY_INDEX_SPI_FLASH_SIZE_MB 10
#define MERCURY_ZX1_CONFIG_PROPERTY_INDEX_NAND_FLASH_SIZE_MB 11
#endif

//-------------------------------------------------------------------------------------------------
// Mercury ZX5
//-------------------------------------------------------------------------------------------------

#if TARGET_MODULE == MERCURY_ZX5
extern char MERCURY_ZX5_MODULE_NAME[];
extern ModuleConfigProperty_t MERCURY_ZX5_CONFIG_PROPERTIES[];
extern const ModulePropertyValueKey_t MERCURY_ZX5_SOC_TYPE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_ZX5_TEMPERATURE_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_ZX5_POWER_GRADE_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_ZX5_ETHERNET_SPEED_VALUE_KEY[];
extern const ModulePropertyValueKey_t MERCURY_ZX5_REAL_TIME_CLOCK_EQUIPPED_VALUE_KEY[];
#define MERCURY_ZX5_MAX_CONFIG_PROPERTY_NAME_LENGTH_CHARACTERS 25
#define MERCURY_ZX5_CONFIG_PROPERTIES_LENGTH_BYTES 5
#define MERCURY_ZX5_CONFIG_PROPERTIES_START_ADDRESS 0x00000008
#define MERCURY_ZX5_PROPERTY_COUNT 11
#define MERCURY_ZX5_CONFIG_PROPERTY_INDEX_SOC_TYPE 0
#define MERCURY_ZX5_CONFIG_PROPERTY_INDEX_SOC_SPEED_GRADE 1
#define MERCURY_ZX5_CONFIG_PROPERTY_INDEX_TEMPERATURE_GRADE 2
#define MERCURY_ZX5_CONFIG_PROPERTY_INDEX_POWER_GRADE 3
#define MERCURY_ZX5_CONFIG_PROPERTY_INDEX_ETHERNET_PORT_COUNT 4
#define MERCURY_ZX5_CONFIG_PROPERTY_INDEX_ETHERNET_SPEED 5
#define MERCURY_ZX5_CONFIG_PROPERTY_INDEX_REAL_TIME_CLOCK_EQUIPPED 6
#define MERCURY_ZX5_CONFIG_PROPERTY_INDEX_USB_DEVICE_PORT_COUNT 7
#define MERCURY_ZX5_CONFIG_PROPERTY_INDEX_DDR3L_RAM_SIZE_MB 8
#define MERCURY_ZX5_CONFIG_PROPERTY_INDEX_SPI_FLASH_SIZE_MB 9
#define MERCURY_ZX5_CONFIG_PROPERTY_INDEX_NAND_FLASH_SIZE_MB 10
#endif

