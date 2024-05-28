/*******************************************************************************
* File Name: main.c
*
* Version: 2.00
*
* Description:
*  JNFX DSP controller, PWM and status
*  mode) component.
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation. All rights reserved.
* This software is owned by Cypress Semiconductor Corporation and is protected
* by and subject to worldwide patent and copyright laws and treaties.
* Therefore, you may use this software only as provided in the license agreement
* accompanying the software package from which you obtained this software.
* CYPRESS AND ITS SUPPLIERS MAKE NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* WITH REGARD TO THIS SOFTWARE, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*******************************************************************************/

#include <project.h>

#define BRIGHTNESS_DECREASE         (100u)

uint16 curPos;


/*******************************************************************************
* Define Interrupt service routine and allocate an vector to the Interrupt
********************************************************************************/
CY_ISR(InterruptHandler)
{
	/* Clear TC Inerrupt */
//   	PWM_ClearInterrupt(PWM_INTR_MASK_TC);
    
	/* Increment the Compare for LED brighrness decrease */ 
//    PWM_WriteCompare(PWM_ReadCompare() + BRIGHTNESS_DECREASE);
}

int main()
{   
    #if (CY_PSOC4_4000)
        CySysWdtDisable();
    #endif /* (CY_PSOC4_4000) */
    
    CyDelay(50u);
    
    /* Enable the global interrupt */
    CyGlobalIntEnable;
 
    /* Enable the Interrupt component connected to interrupt */
//    TC_ISR_StartEx(InterruptHandler);

    D3_Write(! D3_Read() );
    CyDelay( 50 );
    D3_Write(! D3_Read() );
    CyDelay( 100 );
    D4_Write(! D4_Read() );
    CyDelay( 50 );
    D4_Write(! D4_Read() );
    CyDelay( 50 );
    D5_Write(! D5_Read() );
    CyDelay( 50 );
    D5_Write(! D5_Read() );
    CyDelay( 50 );
    D5_Write(! D5_Read() );
    CyDelay( 50 );
    D5_Write(! D5_Read() );
    CyDelay( 50 );
    D4_Write(! D4_Read() );
    CyDelay( 50 );
    D4_Write(! D4_Read() );
    CyDelay( 50 );
    D3_Write(! D3_Read() );
    CyDelay( 50 );
    D3_Write(! D3_Read() );
    CyDelay( 50 );
    
    
    
	/* Start the components */
//    PWM_Start();                //Start PWM
//    PWM_1_Start();              //Start PWM_1
    ADC_Start();                //Starts the ADC
    ADC_StartConvert();         //ADC runs in "free running mode"
    int PotVal;                 //analog value from ADC
    
    for(;;)
    {
        CyDelay(50);
        PotVal = ADC_GetResult16(0);            //Get analog value from channel 0
        CyDelay(50);
        if (PotVal > 1700) {
            D3_Write(1);
            D4_Write(1);
            D5_Write(1);
            S0_Write(0);
            S1_Write(1);
            S2_Write(1);
            CyDelay(100);                
//            PWM_WritePeriod(200);
//            PWM_WriteCompare(100);
            LED_GREEN_Write(0);
            CyDelay(250);
            LED_GREEN_Write(1);
            CyDelay(250);
            LED_GREEN_Write(0);
            CyDelay(250);
            LED_GREEN_Write(1);
            CyDelay(250);
            LED_GREEN_Write(0);
            CyDelay(250);
            LED_GREEN_Write(1);
            while(PotVal > 1700){
                PotVal = ADC_GetResult16(0);
                CyDelay(500);
            }
        }
        if (PotVal > 800 && PotVal < 1699) {
            D3_Write(1);
            D4_Write(1);
            D5_Write(0);
            S0_Write(1);     
            S1_Write(0);
            S2_Write(0);
            CyDelay(100);
//            PWM_WritePeriod(240);
//            PWM_WriteCompare(120);
            LED_GREEN_Write(0);
            CyDelay(250);
            LED_GREEN_Write(1);
            CyDelay(250);
            LED_GREEN_Write(0);
            CyDelay(250);
            LED_GREEN_Write(1);
            CyDelay(250);
            while(PotVal > 800 && PotVal < 1699) {
                PotVal = ADC_GetResult16(0);
                CyDelay(550);
            }
        }
        if (PotVal < 799){
            D3_Write(1);
            D4_Write(0);
            D5_Write(0);
            S0_Write(0);     
            S1_Write(0);
            S2_Write(0);
            CyDelay(100);
//            PWM_WritePeriod(300);
//            PWM_WriteCompare(199);
            LED_GREEN_Write(0);
            CyDelay(250);
            LED_GREEN_Write(1);
            CyDelay(250);
            while(PotVal < 799){
                PotVal = ADC_GetResult16(0);
                CyDelay(550);
        }
        }
        
    }
}


/* [] END OF FILE */
