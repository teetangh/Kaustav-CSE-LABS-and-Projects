class Gen<T extends Number> 
{
    T arr[];

    Gen(T a[]) 
    {
        arr = a;
    }

    double total() 
    {
        double total = 0;
        for (int i = 0; i < arr.length; i++) 
            total += arr[i].doubleValue();
        return total;
    }

    void sameTotal(Gen<?> gen) 
    {

        if (total() == gen.total()) 
            System.out.println("Totals are same");
        else
            System.out.println("Different totals");
    }
    void display()
    {
        for(int i = 0; i<arr.length; i++)
            System.out.println(arr[i]+"\t");
        System.out.println("\n");
    }
}

public class WildCard 
{

    public static void main(String[] args) 
    {

        Gen<Integer> gen1 = new Gen<Integer>(new Integer[]{10, 20, 30, 40, 50});
        Gen<Integer> gen2 = new Gen<Integer>(new Integer[]{10, 20, 30, 40, 50});
        Gen<Double> gen3 = new Gen<Double>(new Double[]{1.1, 2.2, 3.3, 4.4, 5.5});
        Gen<Float> gen4 = new Gen<Float>(new Float[]{5.2f, 6.4f, 7.8f, 8.6f, 9.2f});

        System.out.println("Array 1: "); gen1.display();
        System.out.println("Array 2: "); gen2.display();
        gen1.sameTotal(gen2);

        System.out.println("Array 1:"); gen1.display();
        System.out.println("Array 3:"); gen3.display();
        gen1.sameTotal(gen3);

        System.out.println("Array 1:"); gen1.display();
        System.out.println("Array 4:"); gen4.display();
        gen1.sameTotal(gen4);
    }
}