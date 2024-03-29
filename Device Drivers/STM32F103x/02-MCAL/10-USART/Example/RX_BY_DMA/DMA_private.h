/**
* @file DMA_private.h
* @author Mohamed Abd El-Naby (mahameda.naby@gmail.com) 
* @brief 
* @version 0.1
* @date 2022-11-07
*
*/
#ifndef DMA_PRIVATE_H 
#define DMA_PRIVATE_H 





/******************************************************************************
* Includes
*******************************************************************************/




/******************************************************************************
* Preprocessor Constants
 *******************************************************************************/




/******************************************************************************
* Configuration Constants
*******************************************************************************/


/******************************************************************************
* Typedefs
*******************************************************************************/

typedef struct{

	volatile u32 CCR       ;
	volatile u32 CNDTR     ;
	volatile u32 CPAR      ;
	volatile u32 CMAR      ;
	volatile u32 RESERVED  ;

}DMACHANNEL;

typedef struct{

	volatile u32 ISR       ;
	volatile u32 IFCR      ;
	DMACHANNEL CHANNEL[7]  ;

}DMA_t;




/******************************************************************************
* Macros
*******************************************************************************/

#define DMA_BASE_ADDRESS    0x40020000

#define DMA ( ( volatile DMA_t * ) DMA_BASE_ADDRESS )


/******************************************************************************
* Variables
*******************************************************************************/




/******************************************************************************
* Module Variable Definitions
*******************************************************************************/




/******************************************************************************
* Private Function Prototypes
*******************************************************************************/




#endif
/************************************* End of File ******************************************/