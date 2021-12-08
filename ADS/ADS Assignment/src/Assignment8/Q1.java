package Assignment8;

class MinHeap {

    private final int[] Heap;
    private int size;
    private final int maxsize;

    private static final int FRONT = 1;

    public MinHeap(int maxsize) {

        this.maxsize = maxsize;
        this.size = 0;

        Heap = new int[this.maxsize + 1];
        Heap[0] = Integer.MIN_VALUE;
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

    private void minHeapify(int pos) {

        if (!isLeaf(pos)) {
            if (Heap[pos] > Heap[leftChild(pos)] || Heap[pos] > Heap[rightChild(pos)]) {

                if (Heap[leftChild(pos)] < Heap[rightChild(pos)]) {
                    swap(pos, leftChild(pos));
                    minHeapify(leftChild(pos));
                } else {
                    swap(pos, rightChild(pos));
                    minHeapify(rightChild(pos));
                }
            }
        }
    }

    public void insert(int element) {

        if (size >= maxsize) return;

        Heap[++size] = element;
        int current = size;

        while (Heap[current] < Heap[parent(current)]) {
            swap(current, parent(current));
            current = parent(current);
        }
    }

    public void pop() {
        if (size > FRONT) {
            Heap[FRONT] = Heap[size--];
            minHeapify(FRONT);
        }
    }

    public int top() { return Heap[FRONT]; }

}

public class Q1 {

    public static void main(String[] arg) {

        MinHeap q1 = new MinHeap(3);

        q1.insert(50);
        q1.insert(40);
        q1.insert(30);

        System.out.println(q1.top());
        q1.pop();
        System.out.println(q1.top());

    }
}
