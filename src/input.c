#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

#define MAX_LINE_LENGTH 20
#define MAX_TOKENS 1000

void processLine(FILE *file, rawData_t *rawData, int rawAllocSize) {
    char *token;
    char *tokens[MAX_TOKENS];
    int token_count = 0;
    int actualArraySize = 0;

    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file) != NULL) {
        //Entfernung vom Zeilenende
        line[strcspn(line, "\n")] = '\0';

        //Zeile wird aufgeteilt mithilfe von delimiters
        token_count = 0;
        token = strtok(line, ";");
        printf("%s\n", token);
        while (token != NULL) {
            tokens[token_count] = token;
            token = strtok(NULL, ";");
            token_count++;
            printf("%s\n", token);
        }
        printf("%s\n", token);
        
        
        if(actualArraySize == rawAllocSize-1){
            rawData = realloc(rawData, 20*sizeof(rawData));
            if(rawData == NULL){
                printf("Speicher konnte nicht allokiert werden");
                //return EXIT_FAILURE;
            }
            rawAllocSize += 20;
        }
        else{
            rawData[actualArraySize].sensorID = atoi(tokens[0]);
            rawData[actualArraySize].measureValue = atoi(tokens[1]);
            rawData[actualArraySize].warningLimitLow = atoi(tokens[2]);
            rawData[actualArraySize].warningLimitHigh = atoi(tokens[3]);
            rawData[actualArraySize].alarmLimitLow = atoi(tokens[4]);
            rawData[actualArraySize].alarmLimitHigh = atoi(tokens[5]);
        }
        actualArraySize++;
        
    }

    for (int i = 0; i < actualArraySize; i++){
        printf("%d\n", rawData[i].sensorID);
    }
    
    
}