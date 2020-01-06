import java.util.*;

class Person {
    private String na;
    private String p;

    Person(String n, String d) {
        na = n;
        p = d;
    }

    String getna() {
        return na;
    }

    String getd() {
        return p;
    }
}

class CollegeGraduate extends Person {
    private double gpa;
    private int yog;

    CollegeGraduate(String n, String d, double g, int y) {
        super(n, d);
        gpa = g;
        yog = y;
    }

    double getg() {
        return gpa;
    }

    int gety() {
        return yog;
    }
}

class demo1 {
    public static void main(String[] args) {
        CollegeGraduate obj = new CollegeGraduate("Sameer Rastogi", "29/03/2000", 9.7, 2022);
        System.out.println("Name: " + obj.getna());
        System.out.println("Date of birth: " + obj.getd());
        System.out.println("GPA: " + obj.getg());
        System.out.println("Year of graduation: " + obj.gety());
    }
}
