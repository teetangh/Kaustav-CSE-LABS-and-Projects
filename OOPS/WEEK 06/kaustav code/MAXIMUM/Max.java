import p1.Maximum;

class Max
{
 public static void main(String args[])
 {
    Maximum ob=new Maximun();
    int w = ob.max(1,2,3);
    System.out.println("Maximum integer" + w);
    
    float x = ob.max(1.1,2.2,3.3);
    System.out.println("MAXIMUM FLOAT " + x);
    
    double a[] ={1.1,2.2,3.3,4.4,5.5};
    double y=ob.max(a);
    System.out.println("MAXIMUM DOUBLE IN ARRAY " + y);
    
    double b[][] = {{11.1,22.2,33.3},{44.4,55.5,66.6}};
    double z=ob.max(b);
    System.out.println("MAXIMUM DOUBLE IN MATRIX " + z); 
 }
}
