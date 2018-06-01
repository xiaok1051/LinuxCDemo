#include <stdio.h>
#include <math.h>

int func(int srcInt)
{
    int i = 0;
    int highBit = 0;
    int lowBit = 0;
    
    /*参数判断*/
    if (-9 <= srcInt <= 9)
    {
        printf("srcInt介于-9-9\n");
        return -1;
    }
    
    /*取最低位*/
    lowBit = srcInt % 10;

    /*取最高位*/
    for (i=0; i<=10; i++)
    {
        if (srcInt/(pow(10, i)) == 0)
        {
            break;
        }
    }

    /*最高位*/
    highBit = srcInt % (int)pow(10, i-1);
    
    return srcInt - lowBit + highBit - highBit * pow(10, i-1) + lowBit * pow(10, i-1);
}
