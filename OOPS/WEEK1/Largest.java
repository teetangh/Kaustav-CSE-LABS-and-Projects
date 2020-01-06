//To compute Largest of 3 numbers
import java.io.*;
import java.util.*;

class Largest
{
	static int largest(int a, int b, int c)
	{
		if (a>b)
		{
			if(a>c)
				return a;
			else 
				return c;
		}

		else 
		{
			if (b>c)
				return b;
			else 
				return c;
		}
	}



    public static void main(String[] args)
    {
    	Scanner sc =new Scanner(System.in);
    	System.out.println("Input the numbers");

    	int a = sc.nextInt();
    	int b = sc.nextInt();
    	int c = sc.nextInt();

    	System.out.println("Largest="+largest(a,b,c)); 
	}
}