#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./MMIX_C_LIB.h"

int main(int argc,char **argv){
#define WYDE 16ull
signed long long x,y,z,a,b,t;
unsigned long long  yb,zb,c;
size_t len = (sizeof x/(size_t)2) ;
   if(argv[1]){
 sscanf(argv[1],"%lli_%lli",&y,&z);
 yb = zb = ((~0ull)<<48ull);
 c = 48ull;
 x = 0ll;
     while(len--){
       a = (yb & y) >> c;
       b = (zb & z) >> c;
       if((t = a-b) > 0ll){
	       x |= (t << c); 
       }
       yb >>= WYDE;
       zb >>= WYDE;
	c -=  WYDE;
     }
      
   }else{
fprintf(stderr,"Pass an argument like 5_6\n");
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
