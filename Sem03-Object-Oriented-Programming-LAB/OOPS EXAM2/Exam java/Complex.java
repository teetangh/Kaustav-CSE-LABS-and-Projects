package p1;

import java.lang.*;
import java.util.*;

class MyException extends Exception {
    public MyException(Complex C) {
        // Call constructor of paren t Exception
        if (C.real == 0 & C.real == 0)
            System.out.println("Wrong input");
    }
}

public class Complex {
    public int real;
    public int img;

    public Complex(int real, int img) {
        this.real = real;
        this.img = img;
    }

    public double absolutevalueofcomplex(Complex C) throws MyException {
        try {
            if (C.real == 0 & C.img == 0)
                throw new MyException(C);
        } catch (Exception e) {
            System.out.println("Caught");
        } finally {
            return Math.sqrt((C.real * C.real) + (C.img * C.img));
        }
    }

}