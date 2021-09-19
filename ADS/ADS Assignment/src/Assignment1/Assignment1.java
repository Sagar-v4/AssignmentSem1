package Assignment1;

import java.util.Scanner;

public class Assignment1 {

//    private static final Scanner sc = new Scanner(System.in);

    static void Q1()
    {
        int[] arr = {1, 2, 3, 4, 5, 6};

        System.out.println("Q1 Output : ");

        for (int j : arr) System.out.print(j + " ");

        System.out.print("[OR] ");

        for (int i = (arr.length-1); i >= 0; i--)
            System.out.print(arr[i] + " ");

    }

    static void Q2(){
        int[] arr = {1, 2, 3, 4, 5, 6};
        int[] newArr = new int[arr.length-1];

        Scanner sc = new Scanner(System.in);

        System.out.print("Original Array : ");
        for (int j : arr) System.out.print(j + " ");

        System.out.print("\nEnter Position to be Deleted : ");
        int pos = sc.nextInt();

        System.out.println("Q2 Output : ");

        if(pos > 0 && pos <= arr.length)
            for (int i = 0, j = 0; i < arr.length; i++) {
                if ( i == (pos-1) ) continue;
                newArr[j++] = arr[i];
            }

        arr = newArr;
        for (int j : arr) System.out.print(j + " ");
    }
    
    static void Q3() {
        int[] arr = {1, 2, 3, 4, 5, 6};
        int min = arr[0], max = arr[0];

        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > max)
                max = arr[i];
            else if (arr[i] < min)
                min = arr[i];
        }

        System.out.print("Original Array : ");
        for (int j : arr) System.out.print(j + " ");
        System.out.print("\nQ3 Output : \nMinimum number in array : " + min + "\nMaximum number in array : " + max);
    }

    static void Q4(){

        int sum = 0;
        int[] arr = {5, 10, 15, 20};

        for (int n: arr)
            sum += n;

        System.out.print("Original Array : ");
        for (int j : arr) System.out.print(j + " ");

        System.out.print("\nQ4 Output : sum = " + sum);

    }

    static void Q5(){
        int N = 10, pos = 6, newNum;
        int[] arr = new int[N];
        Scanner sc = new Scanner(System.in);

        for (int i = 0; i < pos; i++)
            arr[i] = i+1;

        System.out.print("Original Array : ");
        for (int i = 0; i < pos; i++)
            System.out.print(arr[i] + " ");

        System.out.print("\nEnter New Element : ");
        newNum = sc.nextInt();

        arr[pos++] = newNum;

        System.out.print("Q5 Output : ");

        for (int i = 0; i < pos; i++)
            System.out.print(arr[i] + " ");


    }

    public static void main(String[] args) {

//        Q1();
        Q2();
//        Q3();
//        Q4();
//        Q5();
        System.out.println("\n\n\n");

    }

}
