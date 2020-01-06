//To print a series of Prime numbers

import java.util.*;
import java.io.*;

class Prime {
	static boolean isPrime(int a) {
		int flag = 0;
		for (int i = 2; i <= a; i++) {
			if (a % i == 0)
				flag++;
		}

		if (flag == 1)
			return true;
		else
			return false;

	}

	public static void main(String[] args) {
		int c = 2;
		Scanner sc = new Scanner(System.in);

		System.out.println("Input the limit");
		int n = sc.nextInt();
		// for (int i = 0; i < n; i++) {
		// if (isPrime(c)) {
		// System.out.println(c + " ");
		// }
		// c++;
		// }
		int count = 0;
		while (true) {
			if (isPrime(c)) {
				System.out.println(c + " ");
				count++;
			}
			c++;
			if (count == n)
				break;
		}
	}

}
