#include <stdio.h>
#include "./MMIX_C_LIB.h"
#include <stdlib.h>

unsigned long long mor(long long y,long long z,int i,int j,int c,int ys,int zs){
unsigned long long yc = ((((~0llu/*invert all 64 zeroes to ones*/)<<63llu/*get rid of 63 ones to make "1000..."*/) >> (8llu*c)) >> (unsigned long long)j), zc = ((((~0llu) << 63llu) >> (8llu*i)) >> (unsigned long long)c);

yc &= y;
zc &= z;
yc >>= ys;
zc >>= zs;
   if(c == 7){
     return (yc & zc);
   }else{
     return ((yc & zc) | mor(y,z,i,j,c+1,ys-8,zs-1));
   }
}

int main(int argc,char ** argv){
unsigned long long x,y,z,t;
    if(argv[1]){
 sscanf(argv[1],"%llu_%llu",&y,&z);
  int ys = 63,zs = 63,count = 63;
  int i,j;
  for(i = 0,x = 0llu;i < 8;i++,zs-=8){
	  for(j = 0,ys = 63;j < 8;j++,ys--,count--){
		t = mor(y,z,i,j,0,ys,zs);
		t <<= count;
		x |= t;
	  }
  }
    char command[50] = "./bins ";
    itoa(x,command+7);
    system(command);
 
 }else{
   fprintf(stderr,"Pass an argument like 6_7 to mor\n");
 }
}
