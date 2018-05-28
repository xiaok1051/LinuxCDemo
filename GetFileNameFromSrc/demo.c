#include <stdio.h>
#include <string.h>

int getFileName(char *fileName, const char *srcName)
{
       int len = strlen(srcName);
       int i = 0;
       int j = 0;
       int fileNameLen = 0;
       int flag = 0;

       if(srcName == NULL)
            return -1; 

       for(i=len-1; i>=0; i--)
       {
          if((i==0) || (0 == strncmp((srcName+i), "/", 1)) || (0 == strncmp((srcName+i), "\\", 1)))
               break;
       }

       fileNameLen = len-i;
       flag = i;

       for(j=0; j<fileNameLen; j++)
       {
          if (0 == flag)
            *(fileName+j) = *(srcName+i); 
          else
            *(fileName+j) = *(srcName+i+1); 

          i++;
       }
       fileName[j] = '\0';
       
       return 0;
}

int main()
{
    char fileName[128];
    char srcName[128] = "bootimage/wk/testFile.o";

    getFileName(fileName, srcName);
    printf("fileName = %s\n", fileName);

    return 0;
}
