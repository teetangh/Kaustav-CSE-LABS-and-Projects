import java.util.*;

class bank {
	String name;
	String accno;
	int balance;
	String type;
	static int r;
	static {
		r = 5;
	}

	bank(String n, String a, int b, String t) {
		name = n;
		accno = a;
		balance = b;
		type = t;
	}

	void Bank() {
	}

	void withdraw(int w) {
		if (balance - w < 500)
			System.out.print("Insufficient funds");
		else
			balance = balance - w;
	}

	void deposit(int d) {
		balance = balance + d;
	}

	static void display_r() {
		System.out.print("Rate=" + r);
	}

	void display() {
		System.out.print("Account Holder Name:" + name);
		System.out.print("Account Number" + accno);
		System.out.print("Available Balance" + balance);
		System.out.print("Type of Account:" + type);
	}
}

class BankAcc {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		String na, acco, ty;
		int ba, da, wa;
		bank b = new bank();
		System.out.print("Enter the account holders name");
		b.na = sc.nextLine;
		System.out.print("Enter the account number");
		b.acco = sc.nextLine;
		System.out.print("Enter the type of account being used");
		b.ty = sc.nextLine;
		System.out.print("Enter the balance of user");
		b.ba = sc.nextInt;
		System.out.print("Enter amount to deposit");
		b.da = sc.nextInt;
		System.out.print("Enter amount to withdraw");
		b.wa = sc.nextInt;
		System.out.print("Same method called with class name");
		bank.display_r();
	}
}
