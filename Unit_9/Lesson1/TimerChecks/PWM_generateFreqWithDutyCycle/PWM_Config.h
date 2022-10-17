/**
* @file PWM_Config.h
* @author Mohamed Abd El-Naby (mahameda.naby@gmail.com) 
* @brief 
* @version 0.1
* @date 2022-10-15
*
*/
#ifndef PWM_CONFIG_H 
#define PWM_CONFIG_H 





/******************************************************************************
* Includes
*******************************************************************************/




/******************************************************************************
* Preprocessor Constants
 *******************************************************************************/




/******************************************************************************
* Typedefs
*******************************************************************************/

/**
 * @brief This Enum Used to Select Modes of operation 
 * 
 */
typedef enum
{
    PWM0_PHASE_CORRECT                  = 0x08 , 
    PWM0_FAST_MODE                      = 0x48 , 
    PWM1_PHASE_FREQ_CORRECT             = 0b1001 , 
    PWM1_FAST_MODE_10_BIT               = 0b0111 ,
    PWM2_FAST_MODE                      = 0x48   
}PWM_ModeOfOperation ; 


/*

*   OC0 PB3
*   OC2 PD7
*   OC1A PD5
*   OC1B PD4

*/
typedef enum
{
    /*      TIMER 0     */ 
    PWM0_PB3_FM_NON_INVERTING           = 0x20 ,
    PWM0_PB3_FM_INVERTING               = 0x30 ,
    PWM0_PB3_PC_CLR_AT_COMP             = 0x20 ,
    PWM0_PB3_PC_SET_AT_COMP             = 0x30 ,
    /*      TIMER 1     */ 
    PWM1_PD5_FM_NON_INVERTING           = 0x80 ,
    PWM1_PD5_FM_INVERTING               = 0xC0 , 
    PWM1_PD4_FM_NON_INVERTING           = 0x20 ,
    PWM1_PD4_FM_INVERTING               = 0x30 ,
	PWM1_PD5_PFC_CLR_AT_COMP			= 0x80 , 
	PWM1_PD5_PFC_SET_AT_COMP			= 0xC0 , 
	PWM1_PD4_PFC_CLR_AT_COMP			= 0x20 , 
	PWM1_PD4_PFC_SET_AT_COMP			= 0x30 ,
    /*      TIMER 2     */
    PWM2_PD7_FM_NON_INVERTING           = 0x20 ,
    PWM2_PD7_FM_INVERTING               = 0x30
}PWM_OC_Pin ;




/**
 * @brief This Enum used to Select Timer Module 
 * 
 */

typedef enum
{
    TIMER0 , 
    TIMER1 , 
    TIMER2 

}TimerSelection_t ;

typedef enum
{
    TIMER0_DISABLE                    ,
    TIMER0_CLK_OVR_1                  ,
    TIMER0_CLK_OVR_8                  ,
    TIMER0_CLK_OVR_64                 ,
    TIMER0_CLK_OVR_256                ,
    TIMER0_CLK_OVR_1024               ,
    /*  Timer   1   */
    TIMER1_DISABLE  = 0x0             ,
    TIMER1_CLK_OVR_1                  ,
    TIMER1_CLK_OVR_8                  ,
    TIMER1_CLK_OVR_64                 ,
    TIMER1_CLK_OVR_256                ,
    TIMER1_CLK_OVR_1024               ,
    /*  Timer 2 */
    TIMER2_DISABLE  = 0x0             ,
    TIMER2_CLK_OVR_1                  ,
    TIMER2_CLK_OVR_8                  ,
    TIMER2_CLK_OVR_32                 ,
    TIMER2_CLK_OVR_64                 ,
    TIMER2_CLK_OVR_128                ,
    TIMER2_CLK_OVR_256                ,
    TIMER2_CLK_OVR_1024               
}PWM_TimerPrescaler ; 


typedef struct
{
    TimerSelection_t    TimerNumber ; 
    PWM_ModeOfOperation PWM_MOP ;
    PWM_TimerPrescaler  TimerPrescaler  ; 
}PWM_config_t;


/**
 * @brief This Macro Used to EN/Disable Anti Glitch For Timer1 Only 
 * @details If ANTI-GLITCH is Enabled Then OCR1A(PD5) is Researved For Buffering 
 *          If ANTI-GLITCH is Disabled you have freedom to use OCR1B(PD4)
 * 
 */
#define TIM1_ANTI_GLITCH    ANTI_GLITCH_ENABLE 


/******************************************************************************
* Configuration Constants
*******************************************************************************/




#endif
/************************************* End of File ******************************************/