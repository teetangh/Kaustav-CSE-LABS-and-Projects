import java.util.*;

class Mixer {

  int A[] = new int[10];
  int B[] = new int[10];
  int C[] = new int[22];

  void accept() {
    Scanner sc = new Scanner(System.in);
    System.out.println("Please enter the elements in A");
    for (int i = 0; i < 10; i++) {
      A[i] = sc.nextInt();
      C[i] = A[i];
    }

    System.out.println("Please enter the elements in B");
    for (int i = 0; i < 10; i++) {
      B[i] = sc.nextInt();
      C[9 + i] = B[i];
    }
    sc.close();
  }

  Mixer mix(Mixer M) {
    for (int i = 0; i < (M.C.length); i++) {
      for (int j = 0; j < ((M.C.length) - i - 1); j++) {
        if (C[j] > C[j + 1]) {
          int temp;
          temp = C[j];
          C[j] = C[j + 1];
          C[j + 1] = temp;
        }
      }
    }
    return this;
  }

  void display() {
    System.out.println("The elements in C");
    for (int i = 0; i < 20; i++) {
      System.out.println(C[i] + "\t");
    }
  }

}

class MyMix {

  public static void main(String args[]) {
    Mixer M = new Mixer();
    M.accept();
    M.mix(M);
    M.display();
  }
}
