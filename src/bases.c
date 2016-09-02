#include "bases.h"


int getNumEntries(char *file){
    FILE* inputFile = fopen(file, "r");
    int numEntries = 0;
    while(!feof(inputFile)){
        if(fgetc(inputFile) == '\n'){
            numEntries++;
        }
    }
    fclose(inputFile);
    return numEntries;
}

void LowestBase(Base *userNum){
    
    userNum->lowestBase = 0;
    int i = 0;
    for(i = 0; userNum->digit[i] != '\0'; i++){
        if( ((userNum->digit[i] - '0' >= 0) && (userNum->digit[i] - '0' <= 9) ) && (userNum->digit[i] - '0' >= userNum->lowestBase) ){
            userNum->lowestBase = userNum->digit[i] - '0';
        }else{
            LetterCase(userNum, i);
        }
    }
    userNum->lowestBase = userNum->lowestBase + 1;
}

int GetBaseTen(Base *userNum, int base){
    int i = 0;
    int digitSize = strlen(userNum->digit);
    int startingPower = digitSize - 1;
    int baseTenVal = 0;
    for (i = 0; i < digitSize; i++){
        GetDigitValue(userNum, i);
        baseTenVal = baseTenVal + ( (userNum->digitValue * pow(base, startingPower)) );
        startingPower--;
    }
    return baseTenVal;
}

void LetterCase(Base *userNum, int digitIndex){
    switch (userNum->digit[digitIndex]) {
        case 'a' | 'A':
            userNum->digitValue = 10;
            userNum->lowestBase = (userNum->lowestBase < 10) ? 10 : userNum->lowestBase;
            break;
        case 'b' | 'B':
            userNum->digitValue = 11;
            userNum->lowestBase = (userNum->lowestBase < 11) ? 11 : userNum->lowestBase;
            break;
        case 'c' | 'C':
            userNum->digitValue = 12;
            userNum->lowestBase = (userNum->lowestBase < 12) ? 12 : userNum->lowestBase;
            break;
        case 'd' | 'D':
            userNum->digitValue = 13;
            userNum->lowestBase = (userNum->lowestBase < 13) ? 13 : userNum->lowestBase;
            break;
        case 'e' | 'E':
            userNum->digitValue = 14;
            userNum->lowestBase = (userNum->lowestBase < 14) ? 14 : userNum->lowestBase;
            break;
        case 'f' | 'F':
            userNum->digitValue = 15;
            userNum->lowestBase = (userNum->lowestBase < 15) ? 15 : userNum->lowestBase;
            break;
        default:
            break;
    }
}

void GetDigitValue(Base *userName, int digitIndex){
    
    userName->digitValue = 0;
    
    if( (userName->digit[digitIndex] - '0' >= 0) && (userName->digit[digitIndex] - '0' <= 9) ){
        userName->digitValue = (int)userName->digit[digitIndex] - '0';
    }else{
        LetterCase(userName, digitIndex);
    }
}

