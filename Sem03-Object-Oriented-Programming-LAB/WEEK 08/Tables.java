class NewThread extends Thread {
    int x;
    Multi m;

    NewThread(Multi ob, int n) {
        super("DEMO THREAD");
        m = ob;
        x = n;
        start();

    }

    @Override
    public void run() {
        m.multi(x);
    }
}

class Multi {
    synchronized void multi(int n )
    {
        System.out.println("Table of :" + n);
        for(int i=1;i<10;i++)
        {
            System.out.println(n+"*"+i+"="+(n*i));
        }
        System.out.println("===========");
    }
}

class Tables
{
    public static void main(String[] args) {
        Multi m = new  Multi();
        NewThread ob1 = new NewThread(m, 5);
        NewThread ob2 = new NewThread(m, 7);
    }
}