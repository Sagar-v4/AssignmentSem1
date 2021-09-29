package Assignment4;

import java.util.Scanner;

public class Q4 {

    int top = 0, capacity = 100;
    char[] arr = new char[capacity];

    public Q4(int size) { capacity = size; }

    void push(char val){ if (top < capacity) arr[top++] = val; }

    char pop() { return (top <= 0) ? 0 : arr[--top]; }

    char peek() { return (top > 0 && capacity >= top) ? arr[top - 1] : 0; }

    int size() { return top; }

    boolean isEmpty() { return top == 0; }

    static int precedence(char c){
        switch (c){
            case '+' :
            case '-' :
                return 1;
            case '*' :
            case '/' :
                return 2;
            case '^' :
                return 3;
        }
        return -1;
    }

    static String infixToPostfix(String s){
        String ans = "";
        int N = s.length();
        Q4 stack = new Q4(N);

        for (int i = 0; i < N; i++) {
            char c = s.charAt(i);

            if (precedence(c) > 0){
                while (!stack.isEmpty() && precedence( stack.peek()) >= precedence(c) )
                    ans += stack.pop();

                stack.push(c);

            } else if ( c == ')' ){
                char x = stack.pop();

                while (x != '(' ) {
                    ans += x;
                    x = stack.pop();
                }

            } else if ( c == '(' )
                stack.push(c);
            else
                ans += c;
        }

        for (int i = 0; i <= stack.size(); i++) {
            ans += stack.pop();
        }

        return ans;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter Infix Expression : ");
        String infix = sc.nextLine();

        String postfix = infixToPostfix(infix);

        System.out.println("Postfix Expression : " + postfix);
    }
}
