import java.util.Scanner;

class Stack<Type> {
	private Type arr[];
	private int top;

	public Stack(int n) {
		top = -1;
		arr = (Type[]) new Object[n];
	}

	public boolean isEmpty() {
		return (top == -1);
	}

	public void push(Type item) {
		if (top == arr.length - 1) {
			System.out.println("Stack overflow.");
			return;
		}
		arr[++top] = item;
	}

	public Type pop() {
		if (top == -1) {
			System.out.println("Stack underflow.");
			return null;
		}
		return arr[top--];
	}

	// @Override
	public String toString() {
		if (top == -1)
			return "STACK IS EMPTY!";
		String str = "";
		for (int i = 0; i <= top; ++i)
			str += "\t" + arr[i];
		return str;
	}

}

class Student {
	private String name;
	private double cgpa;

	public void input() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter student name: ");
		name = sc.nextLine();
		System.out.println("Enter student cgpa: ");
		cgpa = sc.nextDouble();
	}

	// @Override
	public String toString() {
		return "\n| STUDENT\n\t| NAME: " + name + "\n\t| CGPA: " + cgpa + "\n";
	}

}

class Employee {
	private String name;
	private String idno;

	public void input() {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter employee name: ");
		name = sc.nextLine();
		System.out.println("Enter employee id: ");
		idno = sc.nextLine();
	}

	// @Override
	public String toString() {
		return "\n| EMPLOYEE\n\t| NAME: " + name + "\n\t| IDNO: " + idno + "\n";
	}

}

public class GenericStackTest {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		System.out.println("Enter the size of the stacks: ");
		int n = sc.nextInt();
		Stack<Student> sstack = new Stack<>(n);
		Stack<Employee> estack = new Stack<>(n);

		int choice;
		do {
			System.out.print("1. Student\n2. Employee\n Enter choice:");
			choice = sc.nextInt();

			if (choice < 1 || choice > 2) {
				System.out.println("Invalid Choice!");
				System.exit(0);
			}

			int stch;
			do {
				System.out.print("1. Push\n2. Pop\n3. Display\nChoice: ");
				stch = sc.nextInt();

				if (stch == 1) {
					if (choice == 1) {
						Student stud = new Student();
						stud.input();
						sstack.push(stud);
					} else {
						Employee empl = new Employee();
						empl.input();
						estack.push(empl);
					}
				} else if (stch == 2) {
					if (choice == 1) {
						Student stud = sstack.pop();
						if (stud != null)
							System.out.println("Popped: " + stud);
					} else {
						Employee empl = estack.pop();
						if (empl != null)
							System.out.println("Popped: " + empl);
					}
				}
				if (choice == 1) {
					if (!sstack.isEmpty())
						System.out.println("Current Stack: \n" + sstack);
				} else {
					if (!estack.isEmpty())
						System.out.println("Current Stack: \n" + estack);
				}

			} while (stch >= 1 && stch <= 3);

		} while (choice == 1 || choice == 2);

		sc.close();
	}

}