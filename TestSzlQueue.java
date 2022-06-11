public class TestSzlQueue {
    private static final MyBlockingQueue queue = new MyBlockingQueue();
    public static void main(String[] args) {
        //生产者 每秒生产1个
        Thread producer = new Thread(() -> {
            int num = 0;
            while (true) {
                try {
                    System.out.println("生产了:" + num);
                    queue.put(num++);
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });
        producer.start();
        //消费者 每秒消费1个
        Thread customer = new Thread(() -> {
            while (true) {
                try {
                    int product = queue.take();
                    System.out.println("消费了:" + product);
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });
        customer.start();
    }
}
//基于循环队列实现阻塞队列
class MyBlockingQueue {
    //初始化循环队列
    private int[] elements= new int[10];

    //队头指针
    private int head;

    //队尾指针
    private int tail;

    //元素个数
    private int size;

    //专门的锁对象
    private final Object locker = new Object();


    //队头出元素,如果队列为空则阻塞
    public Integer take() throws InterruptedException {
        //循环队列为空,需要阻塞线程,直到循环队列入元素后才通知线程继续执行该操作
        synchronized (locker) {
            if (size==0) {
                locker.wait();
            }

            int ret = elements[head++];
            if (head >= elements.length) {
                head = 0;
            }
            size--;
            //循环队列出元素后,队列就不为满了,可以通知线程继续进行入队操作
            locker.notify();
            return ret;
        }
    }
    //队尾入元素,如果队列满了,就阻塞
    public void put(int index) throws InterruptedException {
        //循环队列如果满了,则需要使线程阻塞,直到循环队列出元素后才通知线程继续执行该操作
        synchronized (locker) {
            if (size == elements.length) {
                locker.wait();
            }
            elements[tail++] = index;
            if (tail >= elements.length) {
                tail = 0;
            }
            size++;
            //循环队列入元素后,队列就不为空了,然后就通知通知线程继续进行出队操作
            locker.notify();
        }
    }
}


