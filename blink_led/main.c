/*****************************************************************************
*
* Copyright (C) 2013 - 2017 Texas Instruments Incorporated - http://www.ti.com/
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions
* are met:
*
* * Redistributions of source code must retain the above copyright
*   notice, this list of conditions and the following disclaimer.
*
* * Redistributions in binary form must reproduce the above copyright
*   notice, this list of conditions and the following disclaimer in the
*   documentation and/or other materials provided with the
*   distribution.
*
* * Neither the name of Texas Instruments Incorporated nor the names of
*   its contributors may be used to endorse or promote products derived
*   from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
* A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
* OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
* THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
******************************************************************************
*
* MSP432 empty main.c template
*
******************************************************************************/
#include "IO_MSP432.h"
#include "memory.h"

#define PIN_LED1_RED 0
#define PIN_LED2_BLUE 2
#define PIN_BUTTON1 1
#define PIN_BUTTON2 4


#define ARRAY_MAX (16)
#define MEMMOVE_LEN (8)
#define DELAY_LEN (100000)

uint8_t array_src[ARRAY_MAX];

uint8_t array_dst[ARRAY_MAX];

void blink_led_forever();

int main(void)
{
    int32_t i;

    WDT_A->CTL =  WDT_A_CTL_PW | WDT_A_CTL_HOLD;

    uint32_t result;
    __ASM volatile ("MRS %0, apsr" : "=r" (result));

    for (i=0; i < ARRAY_MAX; ++i)
    {
        array_src[i] = i;
    }
    my_memset(array_dst, ARRAY_MAX, 0xff);

    __NOP();

    my_memmove(array_src, array_dst, MEMMOVE_LEN);

    __NOP();

    blink_led_forever();

    return 0;
}

void blink_led_forever()
{
    int32_t i;
    //uint8_t *p1_dir = (uint8_t *) 0x40004c04;
    //uint8_t *p1_out = (uint8_t *) 0x40004c02;


    //*(p1_dir) |= 0x01;
    //P1->DIR |= BIT0;
    //P2->DIR |= BIT0;

    //P1->OUT |= BIT0;
    //P2->OUT |= BIT0;

    volatile uint8_t bt1 = (1 << PIN_BUTTON1);
    volatile uint8_t bt1_old = bt1;
    volatile uint8_t bt2 = (1 << PIN_BUTTON2);
    volatile uint8_t bt2_old = bt2;
    volatile uint8_t value = BIT0;
    while (1)
    {
        if (bt1 != bt1_old) {
            if (!bt1) {
                value = IO_Read_Odd(P1, PIN_LED1_RED);
                value ^= BIT0;
                IO_Write_Odd(P1, PIN_LED1_RED, value);
            }
            bt1_old = bt1;
        }
        if (bt2 != bt2_old) {
            if (!bt2) {
                value = IO_Read_Even(P2, PIN_LED2_BLUE);
                value ^= BIT2;
                IO_Write_Even(P2, PIN_LED2_BLUE, value);
            }
            bt2_old = bt2;
        }

        //*(p1_out) ^= 0x01;
        //P1->OUT ^= BIT0;

        for (i=DELAY_LEN; i>0; i--);

        bt1 = IO_Read_Odd(P1, PIN_BUTTON1);
        bt2 = IO_Read_Odd(P1, PIN_BUTTON2);

        //value ^= BIT0;
    }
}
