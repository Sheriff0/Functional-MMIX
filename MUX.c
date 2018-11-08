#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./MMIX_C_LIB.h"

int main(int argc,char **argv){
long long x,y,z,mask;
unsigned long long  mc,t;
size_t len = (sizeof x * 8);
   if(argv[1]){
 sscanf(argv[1],"%lli_%lli_%lli",&y,&z,&mask);
 mc = ~(((~0llu)>>1llu));
 x = 0ll;
     while(len--){
       t = mc & mask;
	if((t >> (unsigned long long)len)){
	t = y & mc;
	x |= t;
	}else{
	 t = z & mc;
	 x |= t;
	}
	mc >>= 1llu;
     }
      
   }else{
fprintf(stderr,"Pass an argument like 5_6_5\n");
   return 0;
   }

   if(argv[2]){
    printf("%lli\n",x);
   }else{
   char command[50] = "./bins ";
    itoa(x,command+7);
    system(command);
   }
 return 0;
}
