import java.util.*;

class Matrixsum
{
  static void sum(int a[][],int b[][], int m , int n )
  {
   int c[][] = new int[m][n];	
   for(int i=0 ; i<m ; i++) 
   {
    for(int j=0 ; j<n ; j++) 
     {
       c[i][j]= a[i][j]+b[i][j];
       System.out.print(c[i][j]+" ");  
     }
    System.out.println();
   }  
   
  }
  public static void main (String []args )
  {
   System.out.println(" Input the dimensions of the 1st matrix");
   Scanner sc = new Scanner(System.in);
   int m= sc.nextInt();
   int n= sc.nextInt();

   System.out.println(" Input the dimensions of the 2nd matrix");
   int p= sc.nextInt();
   int q= sc.nextInt();

   if(m!=p || n!=q)
   {
    System.out.println("Invalid Matrix dimensions");
   }
   else
   {
   	System.out.println(" Input the elements of the 1st matrix");
        int a[][] = new int[m][n];	
   	for(int i=0 ; i<m ; i++) 
   	{
   	 for(int j=0 ; j<n ; j++) 
	    	 {
	    	   a[i][j]= sc.nextInt();
	    	 }
    	}  
        System.out.println(" Input the elements of the 2nd matrix");
   	int b[][] = new int[p][q];	
   	for(int i=0 ; i<p ; i++) 
   	{
    	for(int j=0 ; j<q ; j++) 
	     	{
	      	   b[i][j]= sc.nextInt();
	     	}
    	}
     sum(a,b,m,n); 
   }
   
   sc.close();
  }
}
