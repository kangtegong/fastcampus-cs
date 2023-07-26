public class ProducerConsumer {

    private static int sum = 0;

    public static void main(String[] args) {
        System.out.println("초기 합계: " + sum);

        Thread producerThread = new Thread(new Producer());
        Thread consumerThread = new Thread(new Consumer());

        producerThread.start();
        consumerThread.start();

        try {
            producerThread.join();
            consumerThread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("실행 이후 합계: " + sum);
    }

    static class Producer implements Runnable {
        @Override
        public void run() {
            for (int i = 0; i < 100000; i++) {
                sum++;
            }
        }
    }

    static class Consumer implements Runnable {
        @Override
        public void run() {
            for (int i = 0; i < 100000; i++) {
                sum--;
            }
        }
    }
}

