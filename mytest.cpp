#include<iostream>
#include<string.h>
#include <stdlib.h>

int main()
{
    int myvalues = 0;
for(int i=0;i<100;i++)
   {
      
      std::string last = "INSERT INTO MYVALS (ID,MYVAL) " \
      "VALUES (";
      char c[5],d;
      iota(i,c,10);
      char d = '0'+myvalues;
      std::string last1 = last + c + ", " + d + "); ";

      //  + "); "

      std::cout<<"result ---> "<<last1<<"\n";
myvalues++;
}
}