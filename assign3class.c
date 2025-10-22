#include <stdio.h>
void main(){
int c=0;
int a=0;
	scanf("%d", &a);
	
	for(int i=1; i<=a; i++) {
		c=0;
		for(int j=1; j<=i; j++) {
			
			if(i%j == 0)
				c++;
		}
	if(c==2)
		printf("%d ", i);
	}
	
	
}
