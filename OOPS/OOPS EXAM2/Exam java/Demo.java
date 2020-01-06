
import p1.Complex;

import java.lang.*;
import java.util.*;

// class ZeroAbsoluteValueException extends Exception 
// { 
//     public ZeroAbsoluteValueException(Complex C) 
//     { 
//         // Call constructor of parent Exception 
//         if(C.real == 0 & C.real == 0)
//         System.out.println("Wrong input");
//     } 
// }

public class Demo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the real and imaginary values separately ");
        int a = sc.nextInt();
        int b = sc.nextInt();

        try {
            Complex C1 = new Complex(a, b);
            System.out.println("Abosulte Value is : ");
            System.out.println(C1.absolutevalueofcomplex(C1));
            
            Complex C2 = new Complex(0, 0);
            System.out.println("Abosulte Value if real and Imaginary vlaues are 0 : ");
            System.out.println(C2.absolutevalueofcomplex(C2));

        } catch (Exception e) {
            // TODO: handle exception
        }

        sc.close();
    }
}
