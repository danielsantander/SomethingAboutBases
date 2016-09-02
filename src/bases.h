#ifndef BASES_H
#define BASES_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_NUM 10


typedef struct Base{
    char digit[MAX_NUM];
    int digitValue;
    int lowestBase;
    int hightestBase;
    int baseTenVal;
}Base;


int getNumEntries(char *file);

void LowestBase(Base *userNum);

int GetBaseTen(Base *userNum, int base);

void LetterCase(Base *userNum, int digitIndex);

void GetDigitValue(Base *userName, int digitIndex);


#endif
