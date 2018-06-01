#include <stdio.h>
#include <math.h>

/*交换整数的最高位与最低位
 * 例如123变为321*/
int func(int srcInt)
{
    int i = 0;
    int highBit = 0;
    int lowBit = 0;
    
    /*参数检查*/
    if (-9 <= srcInt && srcInt <= 9)
    {
        printf("-9 <= srcInt <= 9\n");
        return -1;
    }
    
    /*获得最低位*/
    lowBit = srcInt % 10;

    /*获得整数数量级*/
    for (i=0; i<=10; i++)
    {
        if (srcInt/(int)(pow(10, i)) == 0)
        {
            break;
        }
    }

    /*获得最高位*/
    highBit = srcInt / (int)pow(10, i-1);
    
    /*返回转换后的结果*/
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
