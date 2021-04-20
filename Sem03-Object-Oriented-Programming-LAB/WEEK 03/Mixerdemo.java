// To Merge 2 Sorted Arrays

import java.util.*;
import java.io.*;

class Mixer
{
	int arr[];
	public Mixer(int n)
	{
		arr = new int[n];
	}

	void accept()
	{
		System.out.println("Input Sorted");
        Scanner sc = new Scanner(System.in);
        for(int i=0 ; i<arr.length ; i++)
        {
        	arr[i]=sc.nextInt();
        }
    }

    Mixer mix(Mixer A)
    {
    	int n = this.arr.length + A.arr.length;
    	Mixer ob = new Mixer(n);

    	int i=0,j=0,k=0;

    	while(i<this.arr.length && j < A.arr.length)
    	{
    		if(this.arr[i]<A.arr[j])
    		{
    			ob.arr[k]=this.arr[i];
    			i++;
    		}
    		else
    		{
    			ob.arr[k]=A.arr[j];
    			j++;
    		}
    		k++;
    	
    	}


    	while(i<this.arr.length)
    	{
    		ob.arr[k]=this.arr[i];
    		i++;
            k++;
    	}
    	while(j<A.arr.length)
    	{
    		ob.arr[k]=A.arr[j];
    		j++;
            k++;
    	}

    	return ob;

    }


    void display()
    {
    	for (int i= 0 ; i <arr.length ; i++)
    		System.out.println(arr[i] + "\t");
    	System.out.println();

    }

}//Mixer


public class Mixerdemo
{
	public static void main(String[] args) 
	{
		int n=0;
		Scanner sc= new Scanner(System.in);

		//first array
		System.out.println("Input the size of the array  ");
		n=sc.nextInt();
		Mixer ob = new Mixer(n);
		System.out.println("Input elements");
		ob.accept();

        //second array
		System.out.println("Input size");
		n=sc.nextInt();
		Mixer obj = new Mixer(n);
		System.out.println("Input elements");
		obj.accept();

		ob=ob.mix(obj);
		System.out.println("Sorted array is");
		ob.display();
	}
}