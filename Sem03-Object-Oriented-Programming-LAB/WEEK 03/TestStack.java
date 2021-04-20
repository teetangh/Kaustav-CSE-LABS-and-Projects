import java.util.*;

class Stack {
  int stck[] = new int[10];
  int top;

  // Initialize top
  Stack() {
    top = -1;
  }

  void push(int item) {
    if (top == 9)
      System.out.println("Stack is full");
    else
      stck[++top] = item;
  }

  int pop() {
    if (top == -1) {
      System.out.println("Stack is empty");
      return 0;
    } else
      return stck[top--];
  }

  void display() {
    for (int i = 0; i < 10; i++) {
      System.out.print(stck[i] + "\t");
    }
    System.out.println();
  }
}

class TestStack {
  public static void main(String args[]) {
    Scanner sc = new Scanner(System.in);

    Stack mystack1 = new Stack();

    int t;
    // Push some numbers into the stack
    for (int i = 0; i < 10; i++) {
      t = sc.nextInt();
      mystack1.push(t);
    }
    System.out.println("Stack in myStack1:");
    mystack1.display();

    for (int i = 0; i < 10; i++) {
      System.out.println(mystack1.pop());
    }
    sc.close();
  }
}
