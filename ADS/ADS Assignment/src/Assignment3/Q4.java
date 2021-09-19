package Assignment3;

import java.util.Arrays;
import java.util.Scanner;

public class Q4 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter The Value of n : ");
        int N = sc.nextInt();

        int total = (N * (N+1)) / 2;
        int sum = 0, missing;

        int[] arr = new int[N-1];
        Arrays.fill(arr, 0);

        for (int i = 0; i < N-1; i++) {
            System.out.print("Enter Element No." + (i+1) + " [1-" + N + "] : ");
            arr[i] = sc.nextInt();

            boolean contain = false;

            for(int x=0; x < i; x++){
                if (arr[x] == arr[i]){
                    System.out.println("Invalid Element try again...");
                    i--;
                    contain = true;
                    break;
                }
            }

            if (arr[i] > N || arr[i] < 1){
                System.out.println("Invalid Element try again...");
                i--;
            }else if (arr[i] <= N && arr[i] >= 1 && !contain) {
                sum += arr[i];
            }
        }

        missing = total - sum;
        System.out.println("Missing Element : " + missing);


    }
}
