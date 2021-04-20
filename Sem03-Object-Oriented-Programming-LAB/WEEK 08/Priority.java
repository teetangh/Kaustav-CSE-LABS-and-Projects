class Priority extends Thread {
    Priority(String n )
    {
        super(n);
    }

    @Override
    public void run()
    {
        System.out.println("Inside Run " + this.getPriority());
    }

    public static void main(String[] args) {
        Priority t1 = new Priority("T1");
        t1.setPriority(1);
        
        Priority t2 = new Priority("T2");
        t2.setPriority(5);
        
        Priority t3 = new Priority("T3");
        t3.setPriority(2);


        t1.run();
        t2.run();
        t3.run();

    }
}