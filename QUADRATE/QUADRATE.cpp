#include<stdio.h>

int main(){
	int t, xcount, a, b, c, bs=1, cs=1;
	char eq[35];
	scanf("%i", &t);
	while(t-->0){
		scanf("%s", eq);
		xcount=0;
		a=0; b=0; c=0; bs=0; cs=0;
		for(int i=0; eq[i]!='='; i++){
			if(eq[i]=='x')
				xcount++;
			else if(xcount==0 && eq[i]!='*'){
				a=a*10+(eq[i]-'0');
			}
			else if(xcount==2)
			{
				if(eq[i]=='-')
					bs=-1;
				else if(eq[i]=='+')
					bs=1;
				else if(eq[i]!='*')
					b=b*10+(eq[i]-'0');
			}
			else if(xcount==3){
				if(eq[i]=='-')
					cs=-1;
				else if(eq[i]=='+')
					cs=1;
				else
					c=c*10+(eq[i]-'0');
			}

		}
		c=c*cs;
		if(b==0)
			b=bs;
		else 
			b=b*bs;
		if(xcount==2){
			b=0;
			xcount=0;
			cs=0;
			c=0;
			for(int i=0; eq[i]!='='; i++)
			{

				if(eq[i]=='x')
					xcount++;
				else if(xcount==2)
				{
					if(eq[i]=='+')
						cs=1;
					else if(eq[i]=='-')
						cs=-1;
					else 
						c=c*10+(eq[i]-'0');
				}
			}
			c=c*cs;
		}
		if(a==0) a=1;
		//printf("a=%i b=%i c=%i\n", a, b, c);
		int D=(b*b)-(4*a*c);
		if(D>0)
			printf("Distinct real roots.\n");
		else if(D<0)
			printf("Imaginary roots.\n");
		else 
			printf("Equal roots.\n");
	}
}