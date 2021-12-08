package Assignment8;

import java.util.*;

public class Q4 {

    static void findSymmetricPairs(int[][] arr) {

        Hashtable<Integer, Integer> hT = new Hashtable<>();

        for (int[] ints : arr) {
            int first = ints[0];
            int second = ints[1];

            Integer val = hT.get(second);

            if (val != null && val == first) System.out.println(second + ", " + first);

            else hT.put(first, second);
        }
    }

    public static void main(String[] arg) {

        int[][] arr = {{11, 20}, {30, 40}, {5, 10}, {40, 30}, {10, 5}};

        findSymmetricPairs(arr);
    }
}
