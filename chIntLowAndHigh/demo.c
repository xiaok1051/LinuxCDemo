#include <stdio.h>
#include <math.h>

/*�������������λ�����λ
 * ����123��Ϊ321*/
int func(int srcInt)
{
    int i = 0;
    int highBit = 0;
    int lowBit = 0;
    
    /*�������*/
    if (-9 <= srcInt && srcInt <= 9)
    {
        printf("-9 <= srcInt <= 9\n");
        return -1;
    }
    
    /*������λ*/
    lowBit = srcInt % 10;

    /*�������������*/
    for (i=0; i<=10; i++)
    {
        if (srcInt/(int)(pow(10, i)) == 0)
        {
            break;
        }
    }

    /*������λ*/
    highBit = srcInt / (int)pow(10, i-1);
    
    /*����ת����Ľ��*/
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
