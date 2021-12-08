package Assignment8;

class MaxHeap {

    private final int[] Heap;
    private int size;

    public MaxHeap(int size) {
        this.size = 0;
        Heap = new int[size + 1];
        Heap[0] = Integer.MAX_VALUE;
    }

    private int parent(int pos) { return pos / 2; }

    private int leftChild(int pos) { return (2 * pos); }

    private int rightChild(int pos) { return (2 * pos) + 1; }

    private boolean isLeaf(int pos) {
        return pos > (size / 2) && pos <= size;
    }

    private void swap(int fpos, int spos) {
        int tmp;
        tmp = Heap[fpos];

        Heap[fpos] = Heap[spos];
        Heap[spos] = tmp;
    }

    private void maxHeapify(int pos) {

        if (isLeaf(pos)) return;

        if (Heap[pos] < Heap[leftChild(pos)] || Heap[pos] < Heap[rightChild(pos)]) {

            if (Heap[leftChild(pos)] > Heap[rightChild(pos)]) {
                swap(pos, leftChild(pos));
                maxHeapify(leftChild(pos));
            } else {
                swap(pos, rightChild(pos));
                maxHeapify(rightChild(pos));
            }
        }
    }

    public void insert(int element) {
        Heap[size] = element;

        int current = size;
        while (Heap[current] > Heap[parent(current)]) {
            swap(current, parent(current));
            current = parent(current);
        }
        size++;
    }

    public void pop() {
        if(size > 0) {
            Heap[0] = Heap[size--];
            maxHeapify(0);
        }
    }

    public int top() { return Heap[0]; }
}

public class Q2 {

    public static void main(String[] arg) {

        MaxHeap q2 = new MaxHeap(3);

        q2.insert(10);
        q2.insert(20);
        q2.insert(30);

        System.out.println(q2.top());
        q2.pop();
        System.out.println(q2.top());
    }
}
