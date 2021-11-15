package Assignment7;

import java.util.Scanner;

public class Q2 {

    private static boolean ifExist(Node node, int x) {

        if (node == null) return false;
        if (node.key == x) return true;

        return ifExist(node.left, x) || ifExist(node.right, x);
    }

    public static void main(String[] args) {

        BinaryTree q2tree = new BinaryTree();
        Scanner sc = new Scanner(System.in);

        q2tree.implementTree(q2tree);
        System.out.print("Enter Number To Check if it is Present : ");

        System.out.println("It's " + ((ifExist(q2tree.root, sc.nextInt())) ? "Present" : "Not Present") + " in the tree..");
    }


}
