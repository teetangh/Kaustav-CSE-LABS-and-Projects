import java.util.*;
import java.text.*;

class movie {
	private String title;
	private String director;
	private Date year;

	public void setTitle(String t) {
		title = t;
	}

	public void setDirector(String dir) {
		director = dir;
	}

	public void setDate(Date yr) {
		year = yr;
	}

	public void compare(movie m) {
		if ((year.compareTo(m.year) == 0) && (director.equals(m.director) == true)) {
			System.out.print("Similarity found");
		} else {
			System.out.println("Non similar");
		}
	}

	public void display() {
		SimpleDateFormat sdf = new SimpleDateFormat("yyyy");
		System.out.println(title + "\n" + director + "\n" + sdf.format(year));
	}
}

class moviedemo {
	public static void main(String args[]) throws ParseException {
		Scanner sc = new Scanner(System.in);
		movie m1 = new movie();
		movie m2 = new movie();
		SimpleDateFormat sdf = new SimpleDateFormat("yyyy");
		String st, sd, date;
		Date d;
		System.out.print("Enter details of first movie");
		st = sc.nextLine();
		sd = sc.nextLine();
		date = sc.nextLine();
		d = sdf.parse(date);
		m1.setTitle(st);
		m1.setDirector(sd);
		m1.setDate(d);
		System.out.print("Enter details of second movie");
		st = sc.nextLine();
		sd = sc.nextLine();
		date = sc.nextLine();
		d = sdf.parse(date);
		m2.setTitle(st);
		m2.setDirector(sd);
		m2.setDate(d);
		m1.compare(m2);
		m1.display();
		m2.display();
	}
}
