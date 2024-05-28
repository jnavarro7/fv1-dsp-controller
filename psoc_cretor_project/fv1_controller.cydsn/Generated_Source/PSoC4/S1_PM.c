/*******************************************************************************
* File Name: S1.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "S1.h"

static S1_BACKUP_STRUCT  S1_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: S1_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function must be called for SIO and USBIO
*  pins. It is not essential if using GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet S1_SUT.c usage_S1_Sleep_Wakeup
*******************************************************************************/
void S1_Sleep(void)
{
    #if defined(S1__PC)
        S1_backup.pcState = S1_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            S1_backup.usbState = S1_CR1_REG;
            S1_USB_POWER_REG |= S1_USBIO_ENTER_SLEEP;
            S1_CR1_REG &= S1_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(S1__SIO)
        S1_backup.sioState = S1_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        S1_SIO_REG &= (uint32)(~S1_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: S1_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep().
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to S1_Sleep() for an example usage.
*******************************************************************************/
void S1_Wakeup(void)
{
    #if defined(S1__PC)
        S1_PC = S1_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            S1_USB_POWER_REG &= S1_USBIO_EXIT_SLEEP_PH1;
            S1_CR1_REG = S1_backup.usbState;
            S1_USB_POWER_REG &= S1_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(S1__SIO)
        S1_SIO_REG = S1_backup.sioState;
    #endif
}


/* [] END OF FILE */
