public class MultiThreadExample {
    public static void main(String[] args) {
        Thread thread1 = new Thread(new FooRunnable());
        Thread thread2 = new Thread(new BarRunnable());
        Thread thread3 = new Thread(new BazRunnable());

        thread1.start();
        thread2.start();
        thread3.start();

        try {
            thread1.join();
            thread2.join();
            thread3.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class FooRunnable implements Runnable {
    @Override
    public void run() {
        System.out.println("foo executed");
    }
}

class BarRunnable implements Runnable {
    @Override
    public void run() {
        System.out.println("bar executed");
    }
}

class BazRunnable implements Runnable {
    @Override
    public void run() {
        System.out.println("baz executed");
    }
}

