package Assignment8;

public class Q3 {

    static int kthLargestElement(int[] arr, int k) {

        MaxHeap mh = new MaxHeap(arr.length);

        for (int x : arr) { mh.insert(x); }

        while (k-- > 1) { mh.pop(); }

        return mh.top();
    }

    public static void main(String[] args) {

        int[] arr = {7, 4, 6, 3, 9, 1};
        int k = 2;

        System.out.println(k + "th largest array element is " + kthLargestElement(arr, k));
    }
}
