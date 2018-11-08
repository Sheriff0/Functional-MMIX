#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./MMIX_C_LIB.h"

int main(int argc,char **argv){
long long x,y,z;
   if(argv[1]){
 sscanf(argv[1],"%lli_%lli",&y,&z);
 z = ~z;
 x = (y & z);
   }else{
fprintf(stderr,"Pass an argument like 5\\6\n");
   return 0;
   }
   if(argv[2]){
    printf("%lli\n",x);
   }else{
   char command[20] = "./bins ";
 itoa(x,command+7);
    system(command);
   }
 return 0;
}
