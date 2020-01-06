class prob4 extends Thread {
    prob4(String n )
    {
        super(n);
    }

    @Override
    public void run()
    {
        System.out.println("Inside Run " + this.getPriority());
    }

    public static void main(String[] args) {
        prob4 t1 = new prob4("T1");
        t1.setPriority(2);
        
        prob4 t2 = new prob4("T2");
        t2.setPriority(5);
        
        prob4 t3 = new prob4("T3");
        t3.setPriority(1);


        t1.run();
        t2.run();
        t3.run();

    }
}