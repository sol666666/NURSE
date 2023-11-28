#include <main.h>
#include <Nurse.h>
#include "user_mb_app.h"
#include "mbport.h"
extern TIM_HandleTypeDef htim14;
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim16;

extern UCHAR    ucSDiscInBuf[S_DISCRETE_INPUT_NDISCRETES/8];

extern eMBEventType eQueuedEvent;
unsigned char Chair_Motor; //LSB => M1OnOff, M1Dir, M2OnOff, M2Dir, END En, END Dis, POS En, POS Dis <= MSB

unsigned char Unit_Perif1; //bit0 = Light, bit1 = Light, bit2 = Suction, bit3 = Bowl, 
extern BOOL Chair_status;
BOOL Chair_Update, Glass_st, Bowl_st, Suction_st, Suction_Toggle, Suction_update, Light_update, END_update, POS_update,
SW_Up, SW_Down, SW_Left, SW_Right;
unsigned char light, light_st, sel_st, Doctor = 0, S_Keys = 1, S1_st, S2_st, S3_st, S1_Func, S2_Func, S3_Func, S_timer;
uint8_t END_flag, END_st, POS_flag, POS_st, repeat;

void Chair_Functions (void)
{
	ucSDiscInBuf[0] = Chair_Motor;
	if(!Up() && Down() && Left() && Right())
	{
		SW_Up = TRUE;
	}
	if(Up())
	{
		SW_Up = FALSE;
	}
	if(Up() && !Down() && Left() && Right())
	{
		SW_Down = TRUE;
	}
	if(Down())
	{
		SW_Down = FALSE;
	}
	if(Up() && Down() && !Left() && Right())
	{
		SW_Left = TRUE;
	}
	if(Left())
	{
		SW_Left = FALSE;
	}
	if(Up() && Down() && Left() && !Right())
	{
		SW_Right = TRUE;
	}
	if(Right())
	{
		SW_Right = FALSE;
	}
	if(SW_Up == TRUE)
	{
		Chair_Motor = 0x01;
	}
	if(Up() && Down())
	{
		Chair_Motor &= 0xFC;
	}
	if(SW_Down == TRUE)
	{
		Chair_Motor = 0x03;
	}
	if(SW_Left == TRUE)
	{
		Chair_Motor = 0x04;
	}
	if(Left() && Right())
	{
		Chair_Motor &= 0xF3;
	}
	if(SW_Right == TRUE)
	{
		Chair_Motor = 0x0C;
	}
	if(!End() && Left() && Right() && Up() && Down())
	{
		Chair_Motor = 0x10;
	}
	if(!Position() && Left() && Right() && Up() && Down())
	{
		Chair_Motor = 0x40;
	}
	if(End() && Position())
	{
		if(eQueuedEvent == EV_FRAME_SENT)
		{
			Chair_Motor &= 0x0F;				
		}
	}
}

void Unit_Light(void)
{
	ucSDiscInBuf[1] = Unit_Perif1;
	
	if(!Light())
	{
		light_st = 1;
	}
	if(light_st == 1)
	{
		if(Light())
		{
			Unit_Perif1 ^= 0x01;
			light_st = 0;
		}
	}
	/* Suction Procedure */
	if(!Suction() && Suction_st == FALSE)
	{
		Suction_st = TRUE;
		BEEP(&htim16, 1, 1);
	}
	if(Suction_st == TRUE)
	{
		if(Suction())
		{			
			Unit_Perif1 ^= 0x10; // Suction bit toggle
			Suction_st = FALSE;
		}
	}
	/* Glass Procedure */
	if(!Glass() && Glass_st == FALSE)
	{
		Glass_st = TRUE;
		BEEP(&htim1, 1, 1);
	}
	if(Glass_st == TRUE)
	{		
		if(Glass())
		{						
			Unit_Perif1 ^= 0x04; // glass bit toggle
			Glass_st = FALSE;
		}
	}
	/* Bowl Procedure */
	if(!Bowl() && Bowl_st == FALSE)
	{
		Bowl_st = TRUE;
		BEEP(&htim1, 1, 1);
	}
	if(Bowl_st == TRUE)
	{		
		if(Bowl())
		{
			Unit_Perif1 ^= 0x08; // bowl bit toggle
			Bowl_st = FALSE;
		}
	}
}



