import java.util.Scanner;

abstract class Figure
{
   int dim1;
   int dim2; 
   abstract double area(int dim1,int dim2);
}

class Rectangle extends Figure
{
  Rectangle(int r1,int r2)
  {
      dim1=r1;
      dim2=r2;
  }  
  double area(int dim1,int dim2)
  {
      return (double)(dim1*dim2);
  }
}

class Triangle extends Figure
{
  Triangle(int t1,int t2)
  {
      dim1=t1;
      dim2=t2;
  }  
   double area(int dim1,int dim2)
  {
      return (double)0.5*(dim1*dim2);
  }
}

class Square extends Figure
{
    Square(int s1)
    {
        dim1=dim2=s1;
    }
    double area(int dim1,int dim2)
    {
        return (dim1*dim1);
    }
}

class TestFigure
{
    public static void main(String[] args) 
    {
        
        Scanner sc = new Scanner(System.in);
        Figure f;
        
        System.out.println("Enter Rectangle Dimensions");
        int r1 = sc.nextInt();
        int r2 = sc.nextInt();
        Rectangle r = new Rectangle(r1,r2);
        f=r;
        System.out.println("Rectangle area is " + f.area(r1,r2));
        

        System.out.println("Enter Triangle Dimensions");
        int t1 = sc.nextInt();
        int t2 = sc.nextInt();
        Triangle t = new Triangle(t1,t2);
        f=t;
        System.out.println("Triangle area is " + f.area(t1,t2));
        

        System.out.println("Enter Square Dimension");
        int s1 = sc.nextInt();
        Square s = new Square(s1);
        f=s;
        System.out.println("Square area is "+f.area(s1,s1));
    }

}