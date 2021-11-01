package Assignment5;

class CircularQueue {

    int f = -1, r = -1, maxQueueSize = 100, capacity;
    int[] arr = new int[maxQueueSize];

    public CircularQueue(int size) { this.capacity = (size > 0 && size < maxQueueSize) ? size : maxQueueSize; }

    public void enqueue(int x) {
        if (r == -1) r = ++f;
        else if(isFull()) return;
        else r = (r+1) % capacity;
        arr[r] = x;
    }

    public int dequeue() {
        int val = (f == -1) ? 0 : arr[f];
        if (isEmpty()) return 0;
        arr[f] = 0;
        if (f == r) { f = -1; r = -1; }
        else f = (f+1) % capacity;
        return val;
    }

    public int front() { return (isEmpty()) ? 0 : arr[f]; }

    public boolean isEmpty() { return (f == -1 && r == -1); }

    public boolean isFull() { return ((r == capacity-1) && (f == 0) || f - r == 1); }

    void displayQueue() { if (!isEmpty()) for (int j : arr) System.out.println(j); }
}

public class Q2 {

    public static void main(String[] args) {

        CircularQueue cq = new CircularQueue(3);

        System.out.println("empty : " + cq.isEmpty());
        cq.enqueue(10);
        cq.enqueue(20);
        cq.enqueue(30);
        cq.enqueue(40);
        System.out.println("dequeue : " + cq.dequeue());
        cq.enqueue(70);
        cq.enqueue(80);
        System.out.println("empty : " + cq.isEmpty());
        System.out.println("front : " + cq.front());
        System.out.println("dequeue : " + cq.dequeue());
        System.out.println("empty : " + cq.isEmpty());
        System.out.println("front : " + cq.front());
        System.out.println("empty : " + cq.isEmpty());
        System.out.println("dequeue : " + cq.dequeue());
        System.out.println("front : " + cq.front());
        System.out.println("empty : " + cq.isEmpty());
        System.out.println("dequeue : " + cq.dequeue());
        System.out.println("empty : " + cq.isEmpty());

    }
}