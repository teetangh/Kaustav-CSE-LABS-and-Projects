import java.util.*;
import java.io.*;
import java.lang.*;

class Student {
    int regno;
    String name;
    GregorianCalendar doj = new GregorianCalendar();
    short semester;
    float gpa;
    float cgpa;

    Student() {
        System.out.println("Default Constructor");
    }

    Student(String name, short semester, float gpa, float cgpa) {
        System.out.println("Param Constructor");
        // regno
        this.name = name;
        // calendar
        this.semester = semester;
        this.gpa = gpa;
        this.cgpa = cgpa;
    }

    void display() {

        System.out.println("Displaying name " + name);
        System.out.println("Displaying semester " + semester);
        System.out.println("Displaying gpa " + gpa);
        System.out.println("Displaying cgpa " + cgpa);

        // extracting date from Gregorian Calendar
        int tempday = doj.get(Calendar.DATE);
        int tempmonth = doj.get(Calendar.MONTH);
        int tempyear = doj.get(Calendar.YEAR);
        System.out.println("Displaying doj " + tempday + "/" + tempmonth + "/" + tempyear);

        System.out.println("Displaying regno " + regno);
    }

    static void SemAndCgpaSort(Student s[], int n) {
        Student temp[] = new Student[1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                // Descending Semester Sort
                if (s[j].semester < s[j + 1].semester) {
                    temp[0] = s[j];
                    s[j] = s[j + 1];
                    s[j + 1] = temp[0];
                }

                // If semesters are equal then Descending sort according to cgpa
                if (s[j].semester == s[j + 1].semester) {
                    if (s[j].cgpa < s[j + 1].cgpa) {
                        temp[0] = s[j];
                        s[j] = s[j + 1];
                        s[j + 1] = temp[0];
                    }
                }
            }
        }

    }

    static void NameSort(Student s[], int n) {
        Student temp[] = new Student[1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                // Ascending Name Sort
                if ((s[j].name.compareTo(s[j + 1].name)) > 0) {
                    temp[0] = s[j];
                    s[j] = s[j + 1];
                    s[j + 1] = temp[0];
                }

            }
        }
    }

    static void namechararcterchecker(Student s[], String mychar, int n) {

        System.out.println("Inside NAME CHARACTER CHECKER");
        for (int i = 0; i < n; i++) {
            if (s[i].name.contains(mychar))
                s[i].display();
        }
        System.out.println();
    }

    static void namesubstringchecker(Student s[], String mysubstring, int n) {
        System.out.println("Inside NAME SUBSTRING CHECKER");
        for (int i = 0; i < n; i++) {
            if (s[i].name.contains(mysubstring))
                s[i].display();
        }
        System.out.println();

    }

    static void initials(Student s[], int n) {
        System.out.println("Inside INITIALS METHOD");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < s[i].name.length(); j++) {
                char c = s[i].name.charAt(j);
                if (j == 0) {
                    System.out.print(s[i].name.charAt(j));
                    System.out.print(".");
                }
                if (c == ' ' && c != s[i].name.lastIndexOf(" ")) {
                    System.out.print(s[i].name.charAt(j + 1));
                    System.out.print(".");
                }
                if (c == s[i].name.lastIndexOf(" ")) {
                    System.out.print(s[i].name.substring(s[i].name.lastIndexOf(" ") + 1));
                }
            }
            System.out.println();
        }
    }
}

class Test {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Input no of Students");

        int n = sc.nextInt();

        Student s[] = new Student[n];

        for (int i = 0; i < n; i++) {
            s[i] = new Student();
            System.out.println("*****************");
            System.out.println("\n Input details of Student " + (i + 1));

            // Flushing Buffer
            sc.nextLine();

            // Enter details
            System.out.print("\n Input name \t");
            s[i].name = sc.nextLine();
            System.out.print("\n Input Semester \t");
            s[i].semester = sc.nextShort();
            System.out.print("\n Input gpa \t");
            s[i].gpa = sc.nextFloat();
            System.out.print("\n Input cgpa \t");
            s[i].cgpa = sc.nextFloat();

            // Calendar
            System.out.println("\n Enter doj for student " + (i + 1));
            System.out.println("format is year,month day");

            int year = sc.nextInt();
            int month = sc.nextInt();
            int day = sc.nextInt();

            s[i].doj = new GregorianCalendar(year, month, day);

            // OLD regno NOT WORKING
            // String temp1 = String.valueOf(year).substring(2, 4);
            // String temp2 = String.valueOf(i + 1);
            // s[i].regno = Integer.parseInt(String.join(temp1, temp2));

            s[i].regno = (((year % 100) * 100) + (i + 1));
            System.out.println("Reg no is " + s[i].regno + "\n");

            s[i].display();
            System.out.println("*****************");
        }

        // Sorting and Displaying Students
        Student.SemAndCgpaSort(s, n);
        System.out.println("\n AFTER SEM AND CGPA SORTING \n");

        for (int i = 0; i < n; i++) {
            System.out.println();
            s[i].display();
            System.out.println();
        }

        // Sorting and Displaying Students
        Student.NameSort(s, n);
        System.out.println("\n AFTER NAME SORTING \n");

        for (int i = 0; i < n; i++) {
            System.out.println();
            s[i].display();
            System.out.println();
        }

        // REGULAR EXPRESSIONS
        // Flushing Buffer
        System.out.println("Enter ONE Character to check in student name");
        String mychar = sc.nextLine();

        System.out.println("Enter Substring to check in student name");
        String mysubstring = sc.nextLine();

        Student.namechararcterchecker(s, mychar, n);
        Student.namesubstringchecker(s, mysubstring, n);

        Student.initials(s, n);

        sc.close();
    }
}
