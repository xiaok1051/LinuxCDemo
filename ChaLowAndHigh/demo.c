#include <stdio.h>
#include <math.h>

int func(int srcInt)
{
    int i = 0;
    int highBit = 0;
    int lowBit = 0;
    
    /*�����ж�*/
    if (-9 <= srcInt <= 9)
    {
        printf("srcInt����-9-9\n");
        return -1;
    }
    
    /*ȡ���λ*/
    lowBit = srcInt % 10;

    /*ȡ���λ*/
    for (i=0; i<=10; i++)
    {
        if (srcInt/(pow(10, i)) == 0)
        {
            break;
        }
    }

    /*���λ*/
    highBit = srcInt % (int)pow(10, i-1);
    
    return srcInt - lowBit + highBit - highBit * pow(10, i-1) + lowBit * pow(10, i-1);
}
