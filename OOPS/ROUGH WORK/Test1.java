import java.util.Calendar;
import java.util.Formatter;
import java.util.GregorianCalendar;

class Test1 {
    public static void main(String[] args) {
        GregorianCalendar mydate = new GregorianCalendar(2019, 6, 7);
        int year = mydate.get(Calendar.YEAR);
        System.out.println(year);
        int month = mydate.get(Calendar.MONTH);
        System.out.println(month);

        Formatter fmt = new Formatter();
        fmt.format("%t D", mydate);
        System.out.println("Date is " + fmt);
    }
}