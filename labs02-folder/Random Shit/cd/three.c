#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int isKeyword(char* str) 
{ 
    if (!strcmp(str, "auto") || !strcmp(str, "default")  
        || !strcmp(str, "signed") || !strcmp(str, "enum")  
        ||!strcmp(str, "extern") || !strcmp(str, "for")  
        || !strcmp(str, "register") || !strcmp(str, "if")  
        || !strcmp(str, "else")  || !strcmp(str, "int") 
        || !strcmp(str, "while") || !strcmp(str, "do") 
        || !strcmp(str, "break") || !strcmp(str, "continue")  
        || !strcmp(str, "double") || !strcmp(str, "float") 
        || !strcmp(str, "return") || !strcmp(str, "char") 
        || !strcmp(str, "case") || !strcmp(str, "const") 
        || !strcmp(str, "sizeof") || !strcmp(str, "long") 
        || !strcmp(str, "short") || !strcmp(str, "typedef") 
        || !strcmp(str, "switch") || !strcmp(str, "unsigned") 
        || !strcmp(str, "void") || !strcmp(str, "static") 
        || !strcmp(str, "struct") || !strcmp(str, "goto") 
        || !strcmp(str, "union") || !strcmp(str, "volatile")) 
        return (1); 
    return (0); 
} 
void substring(char s[], char sub[], int p, int l) {
   int c = 0;
   
   while (c < l) {
      sub[c] = s[p+c-1];
      c++;
   }
   sub[c] = '\0';
}
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

	char buf[15];
 
 	int c=getc(fa);
    while(fscanf(fa, "%s", buf)!= EOF )
    {
    	if(r=='\n')
    	{
    		rowno++;
    		colno=1;
    	}
    	if(buf[0]=='"')
    		continue;
    	if(buf[0]=='/')
    		continue;
    	/*if(buf[0]=='{'||buf[0]=='}')
    	{
    		for(int i=0;i<strlen(buf);i++)
    		{
    			if(buf[i]!='{' && buf[i]=)
    			{
    				a=i;
    				break;    				
    			}	
    		}
    		for(int i=1;i<)
    	}

    	char temp[10];
    				substring(buf, temp, a, b);
    				if(isKeyword(temp))
    	 			{
    					for(int i=0;i<strlen(buf);i++)
    						buf[i]=buf[i]-32;

            			printf("%s\n",&buf);
    				}
    				break;*/
    	if(isKeyword(buf))
    	{
    		for(int i=0;i<strlen(buf);i++)
    			buf[i]=buf[i]-32;

            printf("%s row:%d col:%d\n",&buf,rowno,colno);
    	}
    	colno++;
    }

	fclose(fa);
	fclose(fb);

	return 0;

}


	

    