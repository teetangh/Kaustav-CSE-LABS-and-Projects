interface IntStack {
    void push(int item);

    int pop();
}

class DynamicStack implements IntStack {
    public int stck[];
    public int tos;

    DynamicStack(int size) {
        stck = new int[size];
        tos = -1;
    }

    public void push(int item) {
        if (tos == stck.length - 1) {
            System.out.println("Stack was full and new Created");
            int temp[] = new int[stck.length * 2];
            for (int i = 0; i < stck.length * 2; i++)
                temp[i] = stck[i];
            stck = temp;
            stck[++tos] = item;
        } else
            stck[++tos] = item;
    }

    public int pop() {
        if (tos < 0) {
            System.out.println("Stack underflow");
            return (0);
        } else
            return stck[tos--];
    }

}

class DynamicStackDemo {

    public static void main(String[] args) {
        DynamicStack mystack1 = new DynamicStack(5);
        DynamicStack mystack2 = new DynamicStack(8);

        for (int i = 0; i < 12; i++)
            mystack1.push(i);
        for (int i = 0; i < 2 * mystack2.stck.length; i++)
            mystack2.push(i);

        for (int i = 0; i < 20; i++)
            System.out.print(mystack1.pop() + "\t");
        System.out.println();
        for (int i = 0; i < mystack2.stck.length; i++)
            System.out.print(mystack2.pop() + "\t");
        // mystack2.pop();

    }
}
