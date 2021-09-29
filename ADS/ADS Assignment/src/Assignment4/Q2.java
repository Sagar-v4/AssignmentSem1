package Assignment4;

import java.util.Scanner;

public class Q2 {

    static String reverse(String s){
        String[] words = s.split("\\s");
        StringBuilder rev = new StringBuilder();

        for (String word : words) {
            StringBuilder sb = new StringBuilder(word);
            sb.reverse();
            rev.append(sb.toString()).append(" ");
        }

        return rev.toString().trim();
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a String : ");
        String str = sc.nextLine();

        str = reverse(str);

        System.out.print("Reversed String : " + str);
    }
}
