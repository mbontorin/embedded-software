/*
 * IO_MPS432.h
 *
 *  Created on: 13 de jan de 2019
 *      Author: marco
 */

#ifndef IO_MSP432_H_
#define IO_MSP432_H_

#include "msp.h"
#include "stdint.h"

__attribute__((always_inline)) static inline uint8_t IO_Read_Odd(DIO_PORT_Odd_Interruptable_Type *port,
                                                             uint8_t pin)
{
    return (port->IN & (1 << pin));
}

__attribute__((always_inline)) static inline void IO_Write_Odd(DIO_PORT_Odd_Interruptable_Type *port,
                                                           uint8_t pin,
                                                           uint8_t value)
{
    port->DIR |= (1 << pin);
    value? (port->OUT |= (1 << pin)): (port->OUT &= ~(1 << pin));
}

__attribute__((always_inline)) static inline uint8_t IO_Read_Even(DIO_PORT_Even_Interruptable_Type *port,
                                                             uint8_t pin)
{
    return (port->IN & (1 << pin));
}

__attribute__((always_inline)) static inline void IO_Write_Even(DIO_PORT_Even_Interruptable_Type *port,
                                                           uint8_t pin,
                                                           uint8_t value)
{
    port->DIR |= (1 << pin);
    value? (port->OUT |= (1 << pin)): (port->OUT &= ~(1 << pin));
}

#endif /* IO_MSP432_H_ */
