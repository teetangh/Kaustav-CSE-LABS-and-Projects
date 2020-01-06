import java.util.*;

class Node<T> {
	
	T data;
	Node<T> next;

	public Node (T data) {
		this.data = data;
		this.next = null;
	}

	@Override
	public String toString () {
		return data.toString();
	}

}

class List<T> {

	Node<T> head;

	public void insertFront (T data) {
		Node<T> temp = new Node<T>(data);
		if (head == null)
			head = temp;
		else {
			temp.next = head;
			head = temp;
		}
	}

	public void insertRear (T data) {
		Node<T> temp = new Node<T>(data);
		if (head == null)
			head = temp;
		else {
			Node<T> curr = head;
			while (curr.next != null)
				curr = curr.next;
			curr.next = temp;
		}
	}

	public T deleteFront () {
		if (head == null)
			return null;
		T data = head.data;
		head = head.next;
		return data;
	}

	public T deleteRear () {
		if (head == null)
			return null;
		Node<T> temp = head;
		Node<T> tpre = head;
		while (temp.next != null) {
			tpre = temp;
			temp = temp.next;
		}
		T data = temp.data;
		tpre.next = null;
		return data;
	}

	@Override
	public String toString () {
		String str = "\t";
		Node<T> temp = head;
		while (temp.next != null) {
			str += temp.data + " -> ";
			temp = temp.next;
		}
		str += temp.data;
		return str;
	}

}

public class QLinkedList<T> {

	public static void main (String [] args) {
		
		Scanner sc = new Scanner(System.in);

		List<Integer> integerList = new List<>();
		List<Double> doubleList = new List<>();
		List<String> stringList = new List<>();

		int lch = 0;
		do {
			System.out.println("1. Integer List\n\t2. Double List\n\t3. String List\n\tChoice: ");
			lch = sc.nextInt();

			int ch;
			do {
				System.out.println("1. Insert Front\n\t2. Insert Rear\n\t3. Delete Front\n\t4. Delete Rear\n\t5. Display\n\tChoice: ");
				ch = sc.nextInt();

				if (ch == 1) {
					System.out.println("Enter item to be inserted: ");
					if (lch == 1)
						integerList.insertFront(sc.nextInt());
					else if (lch == 2)
						doubleList.insertFront(sc.nextDouble());
					else if (lch == 3)
						stringList.insertFront(sc.nextLine());
				}

				else if (ch == 2) {
					System.out.println("Enter item to be inserted: ");
					if (lch == 1)
						integerList.insertRear(sc.nextInt());
					else if (lch == 2)
						doubleList.insertRear(sc.nextDouble());
					else if (lch == 3)
						stringList.insertRear(sc.nextLine());
				}

				else if (ch == 3) {
					Object item = null;
					if (lch == 1)
						item = integerList.deleteFront();
					else if (lch == 2)
						item = doubleList.deleteFront();
					else if (lch == 3)
						item = stringList.deleteFront();
					System.out.println("Deleted item: " + item);
				}

				else if (ch == 4) {
					Object item = null;
					if (lch == 1)
						item = integerList.deleteRear();
					else if (lch == 2)
						item = doubleList.deleteRear();
					else if (lch == 3)
						item = stringList.deleteRear();
					System.out.println("Deleted item: " + item);
				}

				if (lch == 1)
					System.out.println("Integer list: " + integerList);
				else if (lch == 2)
					System.out.println("Double list: " + doubleList);
				else if (lch == 3)
					System.out.println("String list: " + stringList);

			} while (ch >= 1 && ch <= 4);

		} while (lch >= 1 && lch <= 3);

	}

}