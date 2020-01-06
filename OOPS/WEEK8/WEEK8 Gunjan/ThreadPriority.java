import java.lang.*;
import java.util.*;

class NewThread extends Thread {
    int pri;

    NewThread(int i) {
        setPriority(i);
        {
            pri = i;
        }
    }

    @Override
    public void run() {
        System.out.println("Priority " + pri + "starts " + this);
        System.out.println("Priority " + pri + "ends " + this);
    }
}

class ThreadPriority {
    public static void main(String[] args) {
        new NewThread(1);
        new NewThread(2);
        new NewThread(3);

    }
}