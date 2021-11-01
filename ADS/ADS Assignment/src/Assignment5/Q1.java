package Assignment5;

class IntQueue {

    int f = -1, r = -1, maxQueueSize = 100, capacity;
    int[] arr = new int[maxQueueSize];

    public IntQueue(int size) { this.capacity = (size > 0 && size < maxQueueSize) ? size : maxQueueSize; }

    public void enqueue(int x) { if (r < capacity){ if (r == -1) { f++; } arr[++r] = x; } }

    public int dequeue() { return (isEmpty()) ? 0 : arr[f++]; }

    public int front() { return (isEmpty()) ? 0 : arr[f]; }

    public boolean isEmpty() { return ((f == -1 && r == -1) || (f > r)); }

    void displayQueue() { if (!isEmpty()) for (int i = f; i <= r; i++) System.out.println( arr[i]); }
}

public class Q1 {

    public static void main(String[] args) {

        IntQueue iq = new IntQueue(10);

        System.out.println("empty : " + iq.isEmpty());
        System.out.println("front : " + iq.front());
        System.out.println("dequeue : " + iq.dequeue());
        iq.enqueue(10);
        iq.enqueue(11);
        iq.displayQueue();
        System.out.println("empty : " + iq.isEmpty());
        System.out.println("front : " + iq.front());
        System.out.println("empty : " + iq.isEmpty());
        System.out.println("dequeue : " + iq.dequeue());
        System.out.println("front : " + iq.front());
        System.out.println("empty : " + iq.isEmpty());
        System.out.println("dequeue : " + iq.dequeue());
        System.out.println("empty : " + iq.isEmpty());


    }
}
