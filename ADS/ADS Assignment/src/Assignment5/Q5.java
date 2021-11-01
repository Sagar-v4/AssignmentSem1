package Assignment5;

public class Q5 {

    void displayAlternatingSeries(IntQueue q){

        int sum = 0;

        for (int i = 0; i < q.capacity; i++){

            sum += (i % 2 == 0) ? q.arr[i] : (q.arr[i] * -1);
            System.out.print(q.arr[i] + ((i+1 < q.capacity) ? ((i % 2 != 0) ? " + " : " - ") : " = "));
        }
        System.out.print(sum);
    }

    public static void main(String[] args) {

        // change the array here
//        int[] arr = new int[]{ 1, 3, 15, 9 };                 // 4
//        int[] arr = new int[]{ -1, 5, 2, -4, 8 };             // 8
        int[] arr = new int[]{ 3, 7, 8, 7, 2, 9, 3, 1 ,5 };     // -3
        int queueSize = arr.length;

        Q5 q5 = new Q5();

        // Int Queue from Question 1
        // Question 1 is in same package so no need to import
        IntQueue q = new IntQueue(queueSize);

        for (int x : arr)
            q.enqueue(x);

        q5.displayAlternatingSeries(q);
    }
}
