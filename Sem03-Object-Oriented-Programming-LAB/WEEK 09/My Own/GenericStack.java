class Stack<T> {
    int size;
    int top;
    T arr[];

    Stack(int size) {
        this.size = size;
        top = -1;
        (this.arr) T[] = new Object[size];
    }

    void push(T val) {
        if (top == size - 1)
            System.out.println("Overflow \n");
        else
            arr[++top] = val;
    }

    T pop() {
        if (top == -1) {
            System.out.println("Underflow \n");
            return null;
        } else
            return (arr[top--]);
    }
}

class Employee {

    String emp_name;
    int emp_no;

    Employee(String n, int no) {
        emp_name = n;
        emp_no = no;
    }

}

class Student {

    String name;
    int roll_no;

    Student(String n, int no) {
        name = n;
        roll_no = no;
    }

}

class GenericStack {
    public static void main(String[] args) {
        Stack<Employee> E1 = new Stack<Employee>(10);
        Stack<Student> S1 = new Stack<Student>(10);
        E1.push(new Employee("abc", 123));
        S1.push(new Student("def", 456));
        System.out.println(E1.pop());
        System.out.println(S1.pop());

    }

}
