/*
 * memory.c
 *
 *  Created on: 13 de jan de 2019
 *      Author: marco
 */
#include "memory.h"


void my_memset(uint8_t *array, int size, uint8_t value)
{
    int32_t i;
    for (i=0; i < size; ++i) {
        array[i] = value;
    }
}

void my_memmove(uint8_t *array_src, uint8_t *array_dst, uint32_t size)
{
    int32_t i;
    for (i=0; i < size; ++i) {
        array_dst[i] = array_src[i];
    }
}



