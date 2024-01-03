#ifndef HEADER
#define HEADER

typedef unsigned char char_t;

//Struct in welchem die Rohdaten der Datei gespeichert werden
typedef struct{
        char_t sensorID;
        short measureValue;
        short warningLimitLow;
        short warningLimitHigh;
        short alarmLimitLow;
        short alarmLimitHigh;
    }rawData_t;

//Struct in welchem die Counter gespeichert werden
typedef struct{
    short counterWarningLow;
    short counterWarningHigh;
    short counterAlarmLow;
    short counterAlarmHigh;
}counter_t;

//Struct in welchem die Werte eines Sensors gespeichert werden 
typedef struct{
    char_t sensorID;
    short measureValueFirst;
    short measureValueSecond;
    short valueCounter;
    counter_t general;
    counter_t median;
    counter_t average;
}sensorValue_t;

void processLine(FILE*, rawData_t*, int);

#endif