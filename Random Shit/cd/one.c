#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE*fa,*fb;
	int ca,cb;

	fa=fopen("txt.c","r");

	if(fa==NULL)
	{
		printf("Cannot open\n");
		exit(0);
	}

	fb=fopen("txt2.c","w");
	ca=getc(fa);


	while(ca!=EOF)
	{
		if(ca=='\n')
		{
			/*putc(ca,fb);
			cb=getc(fa);
			if(cb='\n')
			{
				do
				{
					ca=' ';
					ca=getc(fa);
				}while(ca=='\n');
			}*/
			ca=' ';
			putc(ca,fb);
		}
		if(ca==' ')
		{
			putc(ca,fb);
			cb=getc(fa);
			if(cb=' ')
			{
				do
				{
					ca=getc(fa);
				}while(ca==' ');
			}
			putc(ca,fb);
		}
		else
			putc(ca,fb);

		ca=getc(fa);
	}

	fclose(fa);
	fclose(fb);

	return 0;

}