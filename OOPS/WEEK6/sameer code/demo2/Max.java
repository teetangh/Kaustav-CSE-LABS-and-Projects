/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package p1;

/**
 *
 * @author sameer admin
 */
public class Max {
   public int max1(int a,int b,int c)
    {
        if(a>b && a>c)
         return a;
        else if(b>c && b>a)
            return b;
        else
            return c;
    }
    public float max1(float a,float b,float c)
    {
        if(a>b && a>c)
         return a;
        else if(b>c && b>a)
            return b;
        else
            return c;
        
    }
   public int max1(int a[])
    {
        int x=a[0];
        for(int i=0;i<a.length;i++)
        {
            if(a[i]>x)
                x=a[i];
        }
        return x;
    }
    public int max1(int a[][])
    {
        int x=a[0][0];
        for(int i=0;i<a.length;i++)
        {
            for(int j=0;j<a[i].length;j++)
            {
                if(x<a[i][j])
                    x=a[i][j];
            }
        }
        return x;
    }
   public void max1()
    {
        System.out.print("Apple");
    }
    
    
}
