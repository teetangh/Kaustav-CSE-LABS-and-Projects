import java.util.*;
abstract class figure
{
    int d1,d2;
    figure(int x,int y)
    {
        d1=x;
        d2=y;
    }
    abstract float area();
}
class rectangle extends figure
{
    rectangle(int x,int y)
    {
        super(x,y);
    }
    float area()
    {
        return d1*d2;
    }
}
class triangle extends figure
{
    triangle(int x,int y)
    {
        super(x,y);
    }
    float area()
    {
        return 0.5f*d1*d2;
    }
}
class square extends figure
{
    square(int x,int y)
    {
        super(x,y);
    }
    float area()
    {
        return d1*d1;
    }
}
class demo3
{
    public static void main(String []args)
    {
        figure ob;
        rectangle r=new rectangle(10,20);
        triangle t=new triangle(10,20);
        square s=new square(10,10);
        ob=r;
        System.out.println("RECTANGLE AREA: "+ob.area());
        ob=t;
        System.out.println("TRIANGLE AREA: "+ob.area());
        ob=s;
        System.out.println("SQUARE AREA: "+ob.area());
    }
}