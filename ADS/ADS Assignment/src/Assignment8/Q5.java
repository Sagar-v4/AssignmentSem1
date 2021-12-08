package Assignment8;

import java.util.*;

public class Q5 {

    static void checkPairSum(int[] arr, int sum) {

        HashSet<Integer> hS = new HashSet<>();
        boolean verify = false;

        for (int j : arr) {
            int temp = sum - j;

            if (hS.contains(temp)) {
                System.out.println( j + ", " + temp);
                verify = true;
            }
            hS.add(j);
        }
        if(verify)
            System.out.println("Valid pair exists.");
        else
            System.out.println("No valid pair exists.");

    }

    public static void main(String[] args) {

//        int[] arr = { 0, -1, 2, -3, 1 };
//        int sum = -2;

        int[] arr = { 1, -2, 1, 0, 5 };
        int sum = 0;

        checkPairSum(arr, sum);
    }
}
