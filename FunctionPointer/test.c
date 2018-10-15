#include<stdio.h>
/** @brief Dummy class used for illustration purposes. Doing something with it.
	@file test.c	
    Detailed description follows here.
    @author Sumendranath
    @date Oct 2018
    */
typedef int (*func) (int);

int funct0(int);
int funct1(int);
int funct2(int);
int funct3(int);

/** My function doing something...
    @param param1 first parameter
    @param param2 second parameter
    @return value return value
*/

int funct0(int i)
{
   funct1(78);
   printf("Hello printed in function pointer 0\n");
}


/** My function doing something...
    @param param1 first parameter
    @param param2 second parameter
    @return value return value
*/
int funct1(int i)
{
   funct2(23);
   printf("Hello printed in function pointer 1\n");
}


/** My function doing something...
    @param param1 first parameter
    @param param2 second parameter
    @return value return value
*/

int funct2(int i)
{
   printf("Hello printed in function pointer 2\n");
}


/** My function doing something...
    @param param1 first parameter
    @param param2 second parameter
    @return value return value
*/

int funct3(int i)
{
   printf("Hello printed in function pointer 3\n");
}


/** My function doing something...
    @param param1 first parameter
    @param param2 second parameter
    @return value return value
*/
int main()
{
   func fp[4]={funct0, funct1, funct2, funct3};
   int i;/*!< Detailed description after the member */
   //fp = {funct0, funct1, funct2, funct3};
   for(i=0;i<4;i++)
   {
      fp[i](i);
   }   
   if(i==4)
   {
      funct3(9);
   } 
}
