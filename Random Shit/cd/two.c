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

		if(ca=='#')
		{
			do
			{
				ca=getc(fa);
			}while(ca!='\n');
		}
		else
		{
			putc(ca,fb);
			ca=getc(fa);
			if(ca!='#')
			{
				while(ca!=EOF)
				{
					putc(ca,fb);
					ca=getc(fa);
				}
				exit(0);
			}
		}

		ca=getc(fa);
	}

	fclose(fa);
	fclose(fb);

	return 0;

}