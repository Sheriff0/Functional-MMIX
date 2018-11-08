#include <stdio.h>
//#include "../chap1.util.h"
unsigned long long int iFromX(char str[]);
int main(){
int c, i;
unsigned long long int i0;
char str[2000];
   scanf("%s",str);  
   i0 = iFromX(str);
   printf("%llu\n", i0);
}

unsigned long long int iFromX(char str[]){
unsigned long long int m, hex;
int i,i2, xtract[1000];
i = i2 = 0;
hex = m = 0ull;

while((i2 = str[i]) != '\0'){
if((i2 >= '0' && i2 <= '9') || (i2 == 'x' || i2 == 'X') || (i2 >= 'a' && i2 <= 'f') || (i2 >= 'A' && i2 <= 'F')){
xtract[m] = i2;
m++;
}
i++;
}
i = --m; 
 for(m = 1ull;i >= 0;m*=16ull, i--){
	if(xtract[i] >= 'a' && xtract[i] <= 'f'){
	  hex += ((unsigned long long int) ((xtract[i] - 'a') + 10) *m);
	}else if(xtract[i] >= 'A' && xtract[i] <= 'F'){

	hex += ((unsigned long long int)((xtract[i] - 'A') + 10) *m);

	}else if(xtract[i] >= '0' && xtract[i]<= '9'){
	  hex += ((unsigned long long int) (xtract[i] - '0') * m);
	}else{
	  break;
	}
 }
 return hex;
}

/*void sFromI(int n, char str[]){
int i = 0;
do{
str[i] = n %10 + '0';
i++;
}while((n /= 10) > 0);
str[i] = NULL;
inverseOf(str);
}*/
