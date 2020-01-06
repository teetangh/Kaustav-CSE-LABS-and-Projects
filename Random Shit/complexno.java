import java.util.Scanner;

class complex {
	int r, i;

	void read() {
		Scanner sc = new Scanner(System.in);
		System.out.println("enter the real part");
		r = sc.nextInt();
		System.out.println("enter the imaginary part");
		i = sc.nextInt();
	}

	void display() {
		System.out.print(r + " " + i + "i");
	}

	complex add(complex c2) {
		complex temp = new complex();
		temp.r = r + c2.r;
		temp.i = i + c2.i;
		return (temp);
	}

	complex subtract(complex c2) {
		complex temp = new complex();
		temp.r = r - c2.r;
		temp.i = i - c2.i;
		return (temp);
	}
}

class complexno {
	public static void main(String args[]) {
		complex c1 = new complex();
		complex c2 = new complex();

		System.out.println("Enter the real and imaginary parts of a");
		c1.read();
		System.out.println("Enter the real and imaginary parts of b");
		c2.read();
		System.out.println("your numbers are");
		c1.display();
		c2.display();
		complex c3 = new complex();
		c3 = c1.add(c2);
		System.out.println("addition");
		c3.display();
		complex c4 = new complex();
		c4 = c1.subtract(c2);
		System.out.println("subtraction");
		c4.display();

	}
}
