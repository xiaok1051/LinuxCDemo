#include <stdio.h>
#include <math.h>

/*交换整数的最高位最低位*/
int func(int srcInt)
{
    int i = 0;
    int highBit = 0;
    int lowBit = 0;
    
    /*靠靠*/
    if (-9 <= srcInt && srcInt <= 9)
    {
        printf("-9 <= srcInt <= 9\n");
        return -1;
    }
    
    /*靠靠*/
    lowBit = srcInt % 10;

    /*靠靠*/
    for (i=0; i<=10; i++)
    {
        if (srcInt/(int)(pow(10, i)) == 0)
        {
            break;
        }
    }

    /*靠?/
    highBit = srcInt / (int)pow(10, i-1);
    
    return srcInt - lowBit + highBit - highBit * (int)pow(10, i-1) + lowBit * (int)pow(10, i-1);
}

int main()
{
	int srcInt = -13;
	int defInt = 0;

	defInt = func(srcInt);
	printf("defInt = %d\n", defInt);

	return 0;
}