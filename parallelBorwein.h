#ifndef _PARALLELBORWEIN_H_
#define _PARALLELBORWEIN_H_

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "utils.h"


typedef struct{
	int start;
	int end;
	long double result;
}borweinStruct;

void parallelBorwein();

void *borweinItself(void *ptr);

#endif