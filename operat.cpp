#include "operat.h"

double mathresult(operati calculate)
{
    double res;
    switch (calculate.operationID){
    case 1:
        res = calculate.num1 + calculate.num2;
        break;
    case 2:
        res = calculate.num1 - calculate.num2;
        break;
    case 3:
        res = calculate.num1 / calculate.num2;
        break;
    case 4:
        res = calculate.num1 * calculate.num2;
        break;
    }
    calculate.operationID = 0;
    return res;
}
