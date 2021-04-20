import java.util.*;

class Linearsearch
{

   static void search(int a[],int n,int key)
   {
    for(int i=0 ; i<n ; i++)
     {
       if(a[i]==key)
       {
        System.out.println("Key"+ key +" found at " + (i+1));
       }
     }
   }
   public static void main(String args[])
   {
	   System.out.println(" Input the length ");
	   Scanner sc = new Scanner(System.in);
	   int n= sc.nextInt();
	   int a[]=new int[n];
	   System.out.println(" Input the array elements");
	   for (int i=0; i<n ; i ++)
	   {
	     a[i]=sc.nextInt();
	   }  
          System.out.println(" Input the key to be found ");
          int key= sc.nextInt();
          search(a,n,key);
   } 
}
