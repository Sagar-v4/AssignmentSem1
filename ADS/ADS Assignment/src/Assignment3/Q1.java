package Assignment3;

public class Q1 {

    public static void main(String[] args) {

        int i = 0;
        int[] ans = new int[8];
        int[] arr = {1, 100, -1, 5, -3, 5, -8, -4};

        for (int x: arr) if (x < 0) ans[i++] = x;

        for (int x: arr) if (x > 0) ans[i++] = x;
        System.out.print("Original : ");
        for (int x: arr) System.out.print(x + " ");
        System.out.print("\nAfter : ");
        for (int x: ans) System.out.print(x + " ");

    }
}
