/*******************************************************************************
* File Name: Pot.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Pot_ALIASES_H) /* Pins Pot_ALIASES_H */
#define CY_PINS_Pot_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Pot_0			(Pot__0__PC)
#define Pot_0_PS		(Pot__0__PS)
#define Pot_0_PC		(Pot__0__PC)
#define Pot_0_DR		(Pot__0__DR)
#define Pot_0_SHIFT	(Pot__0__SHIFT)
#define Pot_0_INTR	((uint16)((uint16)0x0003u << (Pot__0__SHIFT*2u)))

#define Pot_INTR_ALL	 ((uint16)(Pot_0_INTR))


#endif /* End Pins Pot_ALIASES_H */


/* [] END OF FILE */
