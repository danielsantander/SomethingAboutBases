#include "bases.h"



int main(int argc, char *argv[]){
    
    int numEntries = getNumEntries(argv[1]);
    int i = 0;
    int j = 0;
    int baseTenVal = 0;
    Base userInput[numEntries];
    
    FILE* inputFile = fopen(argv[1], "r");
    FILE* outputFile = fopen(argv[2], "w");
    
    for(i= 0; i<numEntries; i++){
        fscanf(inputFile, "%s", userInput[i].digit);
        LowestBase(&userInput[i]);
        fprintf(outputFile, "%s\n", userInput[i].digit);
        for(j = userInput[i].lowestBase; j<17; j++){
            baseTenVal = GetBaseTen(&userInput[i], j);
            fprintf(outputFile,"base %d => %d\n", j, baseTenVal);
        }
        fprintf(outputFile, "\n\n");
    }
    fclose(outputFile);
    fclose(inputFile);
    return 0;
}