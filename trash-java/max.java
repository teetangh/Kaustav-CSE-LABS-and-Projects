
public class max {
	public void maximum(float p, float q, float r) {
		if (p > q && p > r) {
			System.out.println(p + ":is the largest");
		}
		if (q > p && q > r) {
			System.out.println(q + ":is the largest");
		}

		if (r > q && r > p) {
			System.out.println(r + ":is the largest");
		}
	}

	public void maxarr(int a[][]) {
		int i, j, max;
		max = a[0][0];
		for (i = 0; i < a.length; i++) {
			for (j = 0; j < a[i].length; j++) {
				if (a[i][j] > max) {
					max = a[i][j];
				}

			}
		}
		System.out.println(max + ":is the largest");

	}

}
