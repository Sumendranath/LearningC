#include<stdio.h>

typedef int (*func) (int);


int funct0(int);
int funct0(int i)
{
   printf("Hello printed in function pointer 0\n");
}

int funct1(int);
int funct1(int i)
{
   printf("Hello printed in function pointer 1\n");
}
int funct2(int);
int funct2(int i)
{
   printf("Hello printed in function pointer 2\n");
}
int funct3(int);
int funct3(int i)
{
   printf("Hello printed in function pointer 3\n");
}

int main()
{
   func fp[4]={funct0, funct1, funct2, funct3};
   int i;
   //fp = {funct0, funct1, funct2, funct3};
   for(i=0;i<4;i++)
   {
      fp[i](i);
   }   
}
