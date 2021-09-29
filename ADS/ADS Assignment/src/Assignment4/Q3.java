package Assignment4;

import java.util.Scanner;

public class Q3 {

    public static int[] NGE(int[] arr, int n){
        int[] a = new int[n];
        a[n-1] = -1;
        for (int i = 0; i < n-1; i++)
            for (int j = i+1; j < n; j++)
                if(arr[i] < arr[j]){
                    a[i] = arr[j];
                    break;
                } else
                    a[i] = -1;

        return a;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("How many You Want Element : ");
        int N = sc.nextInt();

        int[] arr = new int[N];
        int[] ans;

        System.out.println("Enter " + N + " Elements := ");

        for (int i = 0; i < N; i++) {
            System.out.print("Enter Elements No. " + (i +1) +" : ");
            arr[i] = sc.nextInt();
        }

        ans = NGE(arr, N);

        System.out.print("Next Greater Elements : ");
        for (int x : ans)
            System.out.print(x + " ");
    }
}
