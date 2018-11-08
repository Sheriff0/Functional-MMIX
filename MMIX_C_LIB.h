#include <string.h>
void inverseOf(char str[])
{
	unsigned long len = strlen(str);
	unsigned long i;
int inverse[len+1UL];
inverse[len] = '\0';
--len;
for(i = 0UL;len >= 0UL;){
inverse[i] = *(str+len);
if(len == 0UL){
i++;
break;
}else{
len--;
i++;
}
}
len = i;
for(i = 0UL; i < len; i++){
*(str+i) = inverse[i];
  }
}

void itoa(long long n, char s[])   
{       
	long long i, sign;        
	if ((sign = n) < 0ll){             
		n = -n;
	}
	i = 0ll;       
	do {                	
	 s[i++] = n % 10ll + '0';       
	} while ((n /= 10ll) > 0ll);    	 
	if (sign < 0ll){            
            s[i++] = '-';
	}

   s[i] = '\0';       
    inverseOf(s);  
}

