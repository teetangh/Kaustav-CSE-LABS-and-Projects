import java.util.*;

class Quadroots {
	public static void main(String[] args) {
		System.out.println("ax2+bx+c");
		System.out.println("Enter a,b,c");

		Scanner sc = new Scanner(System.in);

		float a = sc.nextFloat();
		float b = sc.nextFloat();
		float c = sc.nextFloat();
		float d;

		int flag;

		double root1, root2, n1, n2, n3;

		d = (b * b) - (4 * a * c);

		// Switch Flag

		if (d > 0)
			flag = 1;
		else if (d == 0)
			flag = 2;
		else
			flag = 3;

		switch (flag) {
		case 1:
			root1 = ((-b + Math.sqrt(d)) / (2 * a));
			root2 = ((-b - Math.sqrt(d)) / (2 * a));

			System.out.println("Root 1: " + root1);
			System.out.println("Root 2: " + root2);
			break;

		case 2:
			root1 = (-b) / (2 * a);
			root2 = root1;

			System.out.println("Root 1: " + root1);
			System.out.println("Root 2: " + root2);
			break;

		case 3:
			n1 = (-b) / (2 * a);
			double x = -d;
			n2 = Math.sqrt(x);
			n3 = n2 / (2 * a);

			System.out.println("Root 1: " + n1 + " +i " + n3);
			System.out.println("Root 1: " + n1 + " -i " + n3);
			break;

		}

	}
}