import java.io.*;

class employee {
	String name;
	String common;
	int age;

	void input() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("enter name");
		{
			name = br.readLine();
		}
		System.out.println("enter age");
		{
			common = br.readLine();
			age = Integer.parseInt(common);
		}
	}

	void display() {
		System.out.println("your name and age is:  " + name + " " + "," + " " + age);
	}
}

class bufferedreaderdemo {
	public static void main(String args[]) throws IOException {
		employee e = new employee();
		e.input();
		e.display();
	}
}
