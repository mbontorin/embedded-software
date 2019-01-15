/*
 * memory.h
 *
 *  Created on: 13 de jan de 2019
 *      Author: marco
 */

#ifndef MEMORY_H_
#define MEMORY_H_

#include "stdint.h"

void my_memset(uint8_t *array, int size, uint8_t value);

void my_memmove(uint8_t *array_src, uint8_t *array_dst, uint32_t size);


#endif /* MEMORY_H_ */
