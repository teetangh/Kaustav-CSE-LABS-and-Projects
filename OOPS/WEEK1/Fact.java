//To compute the factorial of a number

import java.util.*;

class Fact
{
	public static int fact(int a)
	{
		int f =1;
		for(int i=2;i<=a;i++)
		{
			f=f*i;
		}
		return f;
	}

	public static void main(String args[])
	{
        Scanner sc = new Scanner(System.in);
        System.out.println("Input n and r");
        int n =sc.nextInt();
        int r = sc.nextInt();
        int nr = n-r;
        n=fact(n);
        r=fact(r);
        nr=fact(nr);

        double ncr= (n/(r*nr))*1.0;
        System.out.println("nCr" + ncr);
	}
}
