import java.util.*;

class InsertDel {
  static void insert(int a[], int n, int key, int pos1) {
    for (int i = n; i >= pos1 - 1; i--) {
      a[i] = a[i - 1];
    }
    a[pos1 - 1] = key;
    System.out.println(" Displaying the array elements from insert method");
    for (int i = 0; i < n + 1; i++) {
      System.out.println(a[i]);
    }

  }

  static void delete(int a[], int n, int pos2) {
    for (int i = pos2 - 1; i < n; i++) {
      a[i] = a[i + 1];
    }
    System.out.println(" Displaying the array elements from delete");
    for (int i = 0; i < n; i++) {
      System.out.println(a[i]);
    }

  }

  public static void main(String[] args) {
    System.out.println(" Input the length ");
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int a[] = new int[n + 1];
    System.out.println(" Input the array elements");
    for (int i = 0; i < n; i++) {
      a[i] = sc.nextInt();
    }
    System.out.println(" Input the key and position1 to be inserted ");
    int key = sc.nextInt();
    int pos1 = sc.nextInt();

    insert(a, n, key, pos1);

    System.out.println(" Input position2 to be deleted ");
    int pos2 = sc.nextInt();

    delete(a, n, pos2);
  }

}
