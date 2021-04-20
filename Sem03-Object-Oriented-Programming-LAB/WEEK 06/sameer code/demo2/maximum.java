import p1.Max;
import java.util.*;
public class maximum {
    public static void main(String args[])
    {
        Scanner s=new Scanner(System.in);
        int p[]=new int[5];
       /* for(int i=0;i<5;i++)
        {
            p[i]=s.nextInt();
        }*/
        Max b=new Max();
        int o=b.max1(1,2,3);
        System.out.print(o);
     }

    
}
