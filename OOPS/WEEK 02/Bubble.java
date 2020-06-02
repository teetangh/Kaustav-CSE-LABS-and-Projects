import java.util.*;

class Bubble
{
  static void assort(int a[],int n)
  {
   for(int i=0 ; i<a.length ; i++) 
   {
    for(int j=0 ; j<a.length-i-1 ; j++) 
     {
       if (a[j]>a[j+1])
        {
         a[j]=a[j]+a[j+1];
         a[j+1]=a[j]-a[j+1];
         a[j]=a[j]-a[j+1];
        }     
     }
   }  
  }

  static void desort(int a[],int n)
  {
   for(int i=0 ; i<a.length ; i++) 
   {
    for(int j=0 ; j<a.length-i-1 ; j++) 
     {
       if (a[j]<a[j+1])
        {
         a[j]=a[j]+a[j+1];
         a[j+1]=a[j]-a[j+1];
         a[j]=a[j]-a[j+1];
        }     
     }
   }  
  }
   
  static void display(int a[],int n)
  {
    for(int i=0; i<n ; i++)
    {
     System.out.println( a[i] + " ");
    }
  }
 
 
  public static void main( String[] args)
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
   System.out.println("The array elements are: ");
   display(a,a.length);
   
   System.out.println("The ascending array elements are: ");
   assort(a,a.length);
   display(a,a.length); 

   System.out.println("The descending array elements are: ");       
   desort(a,a.length);  
   display(a,a.length);
  } 


}
