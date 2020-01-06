import java.util.*;

class Person {
  private String name;
  private String birthdate;

  Person(String name, String birthdate) {
    this.name = name;
    this.birthdate = birthdate;
  }

  String getName() {
    return this.name;
  }

  String getBirthdate() {
    return this.birthdate;
  }
}

class CollegeGraduate extends Person {
  private float gpa;
  private int yearofgrad;

  CollegeGraduate(String name2, String birthdate2, float gpa, int yearofgrad) {
    super(name2, birthdate2);
    this.gpa = gpa;
    this.yearofgrad = yearofgrad;
  }

  float getGpa() {
    return this.gpa;
  }

  int getYearofgrad() {
    return this.yearofgrad;
  }
}

class PersonTest {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter name and birthdate");
    String a = sc.nextLine();
    String b = sc.nextLine();
    Person p = new Person(a, b);
    System.out.println("Name is " + p.getName() + " and " + "Birthdate is " + p.getBirthdate());

    System.out.println("Enter name , birthdate , gpa and Year of Graduation ");
    String c = sc.nextLine();
    String d = sc.nextLine();
    float e = sc.nextFloat();
    int f = sc.nextInt();
    CollegeGraduate g = new CollegeGraduate(c, d, e, f);
    System.out.println("Name is " + g.getName() + " and " + "Birthdate is " + g.getBirthdate());
    System.out.println("Gpa is " + g.getGpa() + " and " + "Year of Graduation is " + g.getYearofgrad());

    sc.close();
  }
}
