class lsearch {
	public static void main(String args[]) {
		int a[] = { 23, 76, 4, 54, 90 };
		int key = 9;
		for (int i = 0; i < a.length; i++) {
			if (key == a[i]) {
				System.out.print("Found at" + (i + 1) + "location");
				return;
			}
		}
		System.out.print("Not Found");
	}
}
