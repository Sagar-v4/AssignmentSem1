package Assignment5;

public class Q3 {

    int countPageFault(int[] a, CircularQueue c) {

        boolean fault = true;
        int pageFault = 0;

        for (int k : a) {
            fault = true;
            for (int j = 0; j < c.capacity; j++) {
                if (k == c.arr[j]) {
                    fault = false;
                    break;
                }
            }

            if (fault) {
                if (c.isFull()) {
                    c.dequeue();
                    c.enqueue(k);
                }
                pageFault++;
            }

            if (!c.isFull()) {
                c.enqueue(k);
            }
        }
        return pageFault;
    }

    public static void main(String[] args) {

        int cacheSize = 3;

        // change the array here
        int[] arr = new int[]{ 1, 2, 3, 4, 2, 5, 1 };       // 6
//        int[] arr = new int[]{ 5, 6, 3 , 7, 9, 8, 1, 9, 2 ,7 ,6 ,2 };     // 10

        // Circular Queue from Question 2
        // Question 2 is in same package so no need to import
        CircularQueue cache = new CircularQueue(cacheSize);
        Q3 q3 = new Q3();

        System.out.println("Page Faults : " + q3.countPageFault(arr, cache));

    }
}
