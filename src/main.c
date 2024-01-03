#include <stdio.h>
#include <stdlib.h>
#include "header.h"

#define RAWARRAYSIZE 100;

int main(){
    int rawAllocArraySize = RAWARRAYSIZE;
    rawData_t *measureValues = (rawData_t*) calloc(rawAllocArraySize, sizeof(rawData_t)); //Rohdaten der Datei je Zeile
    FILE *inputFile;

    inputFile = fopen("C:\\Users\\phili\\Desktop\\Studium\\Semester_1\\PI1\\Praktikum\\Termin3\\PI1-Project\\processData.txt", "r");

    if(inputFile == NULL){
        printf("Datei konnte nicht geoefnnet werden");
        return EXIT_FAILURE;
    }
    processLine(inputFile, measureValues, rawAllocArraySize);

    fclose(inputFile);
    free(measureValues);
    return 0;
}
