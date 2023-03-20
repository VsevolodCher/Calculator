#ifndef OPERAT_H
#define OPERAT_H
#define PLUS 1;
#define MINUS 2;
#define DEL 3;
#define MULT 4;

typedef struct Operati{
    int operationID;
    double num1;
    double num2;
}operati;

double mathresult(operati calculate);

#endif // OPERAT_H
