#include <stdio.h>
#include <string.h>
int main(int argc, char **argv){
char size;

unsigned long long int copyBit = ~((~0ull) >> 1ull), printableBit, x;
size_t bitLen = 8;

     if(argv[1]){
	sscanf(argv[1],"%llu",&x);
     }else{
	fprintf(stderr,"Please pass an integer to bins(e.g bins 34 -w).\n");
	return 0;
     }
  if(argv[2]){
  switch (argv[2][1]){
     case 'b' : case 'B' : {
		        bitLen = 1;
			break;
			   }
     case 'w' : case 'W' : {
			bitLen = 2;		     
			break;
			   }
     case 't' : case 'T' : {
		        bitLen = 4;
			break;
			   }
     case 'o' : case 'O' : {
		        bitLen = 8;
			break;
			   }
     default : {
	    break;
	       }

  }
}

  bitLen = (bitLen * (size_t)8);
copyBit >>= (((sizeof x) * (size_t)8) - bitLen);

int count = 1;
  while(bitLen--){
   printableBit = (copyBit & x);
   printableBit >>= (unsigned long long int) bitLen;
      printf(((count%8) == 0)? "%llu\n" : "%llu", printableBit);
   copyBit >>= 1llu;
   count++;
  }
  if(argv[3] && strcmp(argv[3],"noline") == 0){
  ;
  }else{
   putchar('\n');
  }
  return 0;
}
