import java.util.Scanner;
class symMat
{public static void main(String args[])
 {Scanner sc=new Scanner(System.in);
	int r1,c1,i,j;
	System.out.println("Enter the order of the first matrix");
        r1=sc.nextInt();
	c1=sc.nextInt();
 int a[][]=new int[r1][c1];
System.out.println("Enter the elements of the first matrix");
for(i=0;i<r1;i++)
 {for(j=0;j<c1;j++)
  {a[i][j]=sc.nextInt();
  }
 }
if(r1!=c1)
	{System.out.println("Not sym");
	return;}
for(i=0;i<r1;i++)
 {for(j=0;j<c1;j++)
  {if(a[i][j]!=a[j][i])
	{System.out.print("Not sym");
	 return;}
	}
     }
System.out.print("Is sym");
}
}
