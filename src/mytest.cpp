#include<iostream>
#include<string.h>
#include <stdlib.h>
#include <numeric> // std::iota

int findUsefullength(char *data, size_t size)
{
    int i=0;
    for(i=0;i<size;i++)
    {
        if(data[i] == '\0')
            break;
    }
    return i;
}

char* resizetoUsefulLength(char *data, int size)
{
    int original_size = findUsefullength(data,size);
    char* res = new char[original_size];
    for(size_t i=0;i<=original_size;i++)
        res[i] = data[i];

    return res;
}

char* floatTochar(float x)
{
	char* buffer = new char[64];
    snprintf(buffer, 64, "%f", x);
    int len = findUsefullength(buffer,64);
    char* res = resizetoUsefulLength(buffer,len);
    return res;
}

char* intTochar(int x)
{
	char* buffer = new char[64];
    snprintf(buffer, 64, "%d", x);
    int len = findUsefullength(buffer,64);
    char* res = resizetoUsefulLength(buffer,len);
    return res;
}

void charprint(char* data)
{
    int i=0;
    while(data[i]!='\0')
    {
        std::cout<<data[i];
        i++;
    }
    std::cout<<"\n";
}

int main()
{
float myFloat = 12.45646;
char* data = floatTochar(myFloat);

for(int i=0;i<10;i++)
    std::cout<<i<<" --> "<<data[i]<<"\n";

char* c;
char* d;
int myvalues = 0;
// char *test = intTochar(myvalues);
// charprint(test);
for(int i=0;i<100;i++)
   {
        const char* first = "INSERT INTO MYVALS (ID,MYVAL) VALUES (";
        const char* mid = ", ";
        const char* last = ");";
        c = intTochar(i);
        d = intTochar(myvalues);
        char *res = new char[200];
        strcpy(res,first);
        strcat(res,c);
        strcat(res, mid);
        strcat(res,d);
        strcat(res,last);
        charprint(res);
        myvalues++;
    }

}