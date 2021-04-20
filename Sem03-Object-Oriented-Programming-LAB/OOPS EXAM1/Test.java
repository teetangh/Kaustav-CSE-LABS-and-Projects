import java.util.*;

class Bicycle
{
  private static int bicyclenumber=0;
  private int id;
  private int speed;
         
  Bicycle(int id,int speed)
  {
    this.id = id;
    this.speed = speed;
    bicyclenumber++;
  }
  
  int getid(Bicycle B)
  {
    return B.id;
  }
  
  int getspeed(Bicycle B)
  {
    return B.speed;
  }
  
  static int gettotal()
  { 
   return bicyclenumber;
  }       
}

class Test
{
  public static void main(String args[])
  {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter Bicycle number");
    int n = sc.nextInt();
    int a,b;
    
    
    Bicycle B[] = new Bicycle[n];
    for(int i=0 ; i<n ; i++)
    {
      System.out.println("Enter Bicycle details id and speed " + (i+1) );
      a=sc.nextInt();
      b=sc.nextInt();
      B[i]=new Bicycle(a,b);
    }
    
    
    for(int i=0 ; i<n ; i++)
    {
      System.out.println("Bicycle Info id and speed " + (i+1));
      System.out.println(B[i].getid(B[i]));
      System.out.println(B[i].getspeed(B[i]));
    }
    
    System.out.println("Total no of Bicycles from static method is");
    System.out.println(Bicycle.gettotal());
    
  }
}
