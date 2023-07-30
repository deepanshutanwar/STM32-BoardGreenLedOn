/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Deepanshu Tanwar
 * @brief          : Main program body
 ******************************************************************************
 **/

#include <stdint.h>


int main(void)
{
	uint32_t *pClkCtrlReg = (uint32_t*)0x40023830;
	uint32_t *pPortDModeReg = (uint32_t*)0x40020C00;
	uint32_t *pPortDOutReg =(uint32_t*)0x40020C14;

	//1. enable the clock for GPIOD peripheral in the AHB1ENR
	*pClkCtrlReg |= (0x08);

	//2. configure the mode of the IO pin as output
	//a. clear the 24th and 25th bit position (CLEAR)
	*pPortDModeReg &= (0xFCFFFFFF);

	//b. make 24th and 25th bit position as 1 (SET)
	*pPortDModeReg |= (0x01000000);

	//3. SET 12th bit of the output data register to make I/O pin-12 as HIGH
	*pPortDOutReg |= (0x00001000);

	while(1)
	{
		;
	}
}
