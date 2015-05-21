/*
 * @brief NXP LPCXpresso 11U37H board file
 *
 * @note
 * Copyright(C) NXP Semiconductors, 2013
 * All rights reserved.
 *
 * @par
 * Software that is described herein is for illustrative purposes only
 * which provides customers with programming information regarding the
 * LPC products.  This software is supplied "AS IS" without any warranties of
 * any kind, and NXP Semiconductors and its licensor disclaim any and
 * all warranties, express or implied, including all implied warranties of
 * merchantability, fitness for a particular purpose and non-infringement of
 * intellectual property rights.  NXP Semiconductors assumes no responsibility
 * or liability for the use of the software, conveys no license or rights under any
 * patent, copyright, mask work right, or any other intellectual property rights in
 * or to any products. NXP Semiconductors reserves the right to make changes
 * in the software without notification. NXP Semiconductors also makes no
 * representation or warranty that such application will be suitable for the
 * specified use without further testing or modification.
 *
 * @par
 * Permission to use, copy, modify, and distribute this software and its
 * documentation is hereby granted, under NXP Semiconductors' and its
 * licensor's relevant copyrights in the software, without fee, provided that it
 * is used in conjunction with NXP Semiconductors microcontrollers.  This
 * copyright, permission, and disclaimer notice must appear in all copies of
 * this code.
 */

#include "board.h"
#include "retarget.h"

/*****************************************************************************
 * Private types/enumerations/variables
 ****************************************************************************/
#define SetBit(port, bit) port|= (1<<bit)
#define ClearBit(port, bit) port&= ~(1<<bit)
#define BUTTONS_ENCA_GPIO_PORT_NUM			0
#define BUTTONS_ENCA_GPIO_BIT_NUM			6
#define BUTTONS_ENCB_GPIO_PORT_NUM			0
#define BUTTONS_ENCB_GPIO_BIT_NUM			7
#define BUTTONS_ENCC_GPIO_PORT_NUM			0
#define BUTTONS_ENCC_GPIO_BIT_NUM			1
#define RIGHT_SPIN 							0x01
#define LEFT_SPIN 							0xff

/*****************************************************************************
 * Public types/enumerations/variables
 ****************************************************************************/

/* System oscillator rate and clock rate on the CLKIN pin */
const uint32_t OscRateIn = 12000000;
const uint32_t ExtRateIn = 0;
volatile uint8_t bufEnc = 0; //encoder buffer

/*****************************************************************************
 * Private functions
 ****************************************************************************/

/*****************************************************************************
 * Public functions
 ****************************************************************************/

/* Set up and initialize all required blocks and functions related to the
   board hardware */
void Board_Init(void)
{
	/* Initialize GPIO */
	Chip_GPIO_Init(LPC_GPIO);
}

/* Initialize buttons on the board */
void Board_Buttons_Init(void)
{
	//enable pull-ups
	Chip_IOCON_PinMuxSet(LPC_IOCON, BUTTONS_ENCA_GPIO_PORT_NUM, BUTTONS_ENCA_GPIO_BIT_NUM,
					(IOCON_FUNC0 | IOCON_MODE_PULLUP | IOCON_DIGMODE_EN));
	Chip_IOCON_PinMuxSet(LPC_IOCON, BUTTONS_ENCB_GPIO_PORT_NUM, BUTTONS_ENCB_GPIO_BIT_NUM,
					(IOCON_FUNC0 | IOCON_MODE_PULLUP | IOCON_DIGMODE_EN));
	Chip_IOCON_PinMuxSet(LPC_IOCON, BUTTONS_ENCC_GPIO_PORT_NUM, BUTTONS_ENCC_GPIO_BIT_NUM,
				(IOCON_FUNC0 | IOCON_MODE_PULLUP | IOCON_DIGMODE_EN));

	//set as input pins
	Chip_GPIO_SetPinDIRInput(LPC_GPIO, BUTTONS_ENCA_GPIO_PORT_NUM, BUTTONS_ENCA_GPIO_BIT_NUM);
	Chip_GPIO_SetPinDIRInput(LPC_GPIO, BUTTONS_ENCB_GPIO_PORT_NUM, BUTTONS_ENCB_GPIO_BIT_NUM);
	Chip_GPIO_SetPinDIRInput(LPC_GPIO, BUTTONS_ENCC_GPIO_PORT_NUM, BUTTONS_ENCC_GPIO_BIT_NUM);
}

/* Get button status */
uint32_t Buttons_GetStatus(void)
{
	uint8_t ret = NO_BUTTON_PRESSED;

	uint8_t encodeState = Buttons_GetStateEncoder();

	if (encodeState == RIGHT_SPIN)
	{
		ret |= BUTTONS_RIGHT;
	}

	if (encodeState == LEFT_SPIN)
	{
		ret |= BUTTONS_LEFT;
	}

	if (!Chip_GPIO_GetPinState(LPC_GPIO, BUTTONS_ENCC_GPIO_PORT_NUM, BUTTONS_ENCC_GPIO_BIT_NUM))
	{
		ret |= BUTTONS_ENCC;
	}

	return ret;
}

/* poll button status */
void Poll_Buttons(void)
{
	static uint8_t stateEnc;
	uint8_t tmp;
	uint8_t currentState = 0;

	//check state of pins
	if (!Chip_GPIO_GetPinState(LPC_GPIO, BUTTONS_ENCA_GPIO_PORT_NUM, BUTTONS_ENCA_GPIO_BIT_NUM))
	{
		SetBit(currentState,0);
	}
	else
	{
		tmp = 0;
	}

	if (!Chip_GPIO_GetPinState(LPC_GPIO, BUTTONS_ENCB_GPIO_PORT_NUM, BUTTONS_ENCB_GPIO_BIT_NUM))
	{
		SetBit(currentState,1);
	}
	else
	{
		tmp = 0;
	}

	tmp = stateEnc;
	if (currentState == (tmp & 0x03)) return; // 00000011b

	tmp = (tmp<<2)|currentState;
	stateEnc = tmp;

	tmp = (tmp & 0x0F);

	if(tmp == 0x0B) bufEnc = LEFT_SPIN;
	if(tmp == 0x0D) bufEnc = LEFT_SPIN;
	if(tmp == 0x04) bufEnc = LEFT_SPIN;
	if(tmp == 0x02) bufEnc = LEFT_SPIN;

	if(tmp == 0x01) bufEnc = RIGHT_SPIN;
	if(tmp == 0x07) bufEnc = RIGHT_SPIN;
	if(tmp == 0x0E) bufEnc = RIGHT_SPIN;
	if(tmp == 0x08) bufEnc = RIGHT_SPIN;

	//if (tmp == 0xE1) bufEnc = LEFT_SPIN; //11100001b
	//if (tmp == 0xD2) bufEnc = RIGHT_SPIN; //11010010b
	return;
}

uint8_t Buttons_GetStateEncoder(void)
{
	uint8_t tmp = bufEnc;
	bufEnc = 0;
	return tmp;
}
