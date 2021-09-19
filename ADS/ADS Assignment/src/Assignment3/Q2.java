package Assignment3;

import java.util.Arrays;
import java.lang.Math;

public class Q2 {

    public static void main(String[] args) {

        int n = 14;
        int[] ans = new int[3];
        Arrays.fill(ans, 0);
        int[] arr = {1, 2, 3, 1, 3, 2, 2, 2, 3, 3, 3, 3, 3, 3};

        for (int x : arr )
            ans[x-1]++;

        for (int i=0; i < ans.length; i++ )
             if ( (n%2==0) ? (ans[i] > (n/2)) : (ans[i] > Math.floor(n/2)) ) System.out.print(i+1);

    }
}
