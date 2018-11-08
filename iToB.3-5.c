#include <stdio.h>
#include "../c/chap1.util.h"
char * itob(unsigned long long int n,unsigned long long int b, char s[]){
#define GETALPHA 39U
	unsigned int i = 0U;
	do{
	s[i++] = ((n % b) > 9ull)? (n % b) + '0' + GETALPHA : (n % b) + '0';
	}while((n /= b) > 0ull);

	s[i] = '\0';
	inverseOf(s);
	return s;
}

int main(){
#define BLOC 2000
unsigned long long int n, b;
char s[BLOC];
scanf("%llu %llu", &n,&b);
printf("%s\n", itob(n, b, s));
}
