class Swap <G>
{
	static <G> void swap(G[] a, int i, int j)
	{
        G temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    static <G> void display(G[] a)
    {
        for(G ob : a)
        System.out.print(ob+" ");
        System.out.println();
    }
}
public class SwapDemo
{
	public static void main(String args[])
	{
		String s[] = {"Hello", "This", "OOP", "Is"};
		Swap.swap(s, 2, 3);
		Swap.display(s);
		Integer i[] = {3, 1, 2, 0};
		Swap.swap(i, 0, 3);
		Swap.display(i);
	}
}
