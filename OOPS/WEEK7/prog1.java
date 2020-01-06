import java.util.*;

class phone {
  String brand;
  int mem;

  phone(String s, int m) {
    brand = s;
    mem = m;
  }

}

interface app {
  void makeaudiocall(String cell);

  void makevideocall(String cell);
}

class basicphone extends phone implements app {

  String number;

  basicphone(String s, int m, String p) {
    super(s, m);
    number = p;

  }

  public void makeaudiocall(String x) {
    System.out.println("In audio call number is  " + x);
  }

  public void makevideocall(String y) {
    System.out.println("In video call number is " + y);
  }
}

class smartphone extends phone implements app {
  String number;

  smartphone(String s, int m, String p) {
    super(s, m);
    number = p;

  }

  public void makeaudiocall(String s) {
    System.out.println("In audio call number is  " + s);
  }

  public void makevideocall(String t) {
    System.out.println("In video call number is " + t);
  }
}

class prog1 {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter brand,memory and number");
    String s = sc.nextLine();
    int m = sc.nextInt();
    sc.nextLine();
    String p = sc.nextLine();
    // phone j;
    app j;
    basicphone b = new basicphone(s, m, p);
    smartphone v = new smartphone(s, m, p);
    System.out.println("Enter 1 for basic 2 for smart");
    int x = sc.nextInt();
    if (x == 1) {
      // j=b;
      b.makeaudiocall(p);
    } else {
      // j=v;
      v.makeaudiocall(p);
    }
  }
}
