/*******************************************************************************
* File Name: Pot.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Pot_H) /* Pins Pot_H */
#define CY_PINS_Pot_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Pot_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} Pot_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Pot_Read(void);
void    Pot_Write(uint8 value);
uint8   Pot_ReadDataReg(void);
#if defined(Pot__PC) || (CY_PSOC4_4200L) 
    void    Pot_SetDriveMode(uint8 mode);
#endif
void    Pot_SetInterruptMode(uint16 position, uint16 mode);
uint8   Pot_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Pot_Sleep(void); 
void Pot_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Pot__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Pot_DRIVE_MODE_BITS        (3)
    #define Pot_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Pot_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Pot_SetDriveMode() function.
         *  @{
         */
        #define Pot_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Pot_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Pot_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Pot_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Pot_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Pot_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Pot_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Pot_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Pot_MASK               Pot__MASK
#define Pot_SHIFT              Pot__SHIFT
#define Pot_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Pot_SetInterruptMode() function.
     *  @{
     */
        #define Pot_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Pot_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Pot_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Pot_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Pot__SIO)
    #define Pot_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Pot__PC) && (CY_PSOC4_4200L)
    #define Pot_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Pot_USBIO_DISABLE              ((uint32)(~Pot_USBIO_ENABLE))
    #define Pot_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Pot_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Pot_USBIO_ENTER_SLEEP          ((uint32)((1u << Pot_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Pot_USBIO_SUSPEND_DEL_SHIFT)))
    #define Pot_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Pot_USBIO_SUSPEND_SHIFT)))
    #define Pot_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Pot_USBIO_SUSPEND_DEL_SHIFT)))
    #define Pot_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Pot__PC)
    /* Port Configuration */
    #define Pot_PC                 (* (reg32 *) Pot__PC)
#endif
/* Pin State */
#define Pot_PS                     (* (reg32 *) Pot__PS)
/* Data Register */
#define Pot_DR                     (* (reg32 *) Pot__DR)
/* Input Buffer Disable Override */
#define Pot_INP_DIS                (* (reg32 *) Pot__PC2)

/* Interrupt configuration Registers */
#define Pot_INTCFG                 (* (reg32 *) Pot__INTCFG)
#define Pot_INTSTAT                (* (reg32 *) Pot__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Pot_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Pot__SIO)
    #define Pot_SIO_REG            (* (reg32 *) Pot__SIO)
#endif /* (Pot__SIO_CFG) */

/* USBIO registers */
#if !defined(Pot__PC) && (CY_PSOC4_4200L)
    #define Pot_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Pot_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Pot_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Pot_DRIVE_MODE_SHIFT       (0x00u)
#define Pot_DRIVE_MODE_MASK        (0x07u << Pot_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Pot_H */


/* [] END OF FILE */
