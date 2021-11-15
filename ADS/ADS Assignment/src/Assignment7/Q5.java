package Assignment7;

import java.util.Scanner;

public class Q5 {

    static void findAncestors(BinarySearchTree.Node root, int x, int[] arr) {
        int i = 0;

        while (root.data != x) {
            arr[i++] = root.data;
            root = (root.data > x) ? root.left : root.right;
        }
    }

    static int findLowestCommonAncestor(BinarySearchTree.Node root, int n1, int n2) {
        BinarySearchTree.Node root1 = root;
        BinarySearchTree.Node root2 = root;

        if(root.data != n1 && root.data != n2) {
            while (root1.left.data != n1 && root1.right.data != n1 && root2.left.data != n2 && root2.right.data != n2) {

                root1 = (root1.data > n1) ? root1.left : root1.right;
                root2 = (root2.data > n2) ? root2.left : root2.right;

                if (root1 == root2) root = root1;
                else break;
            }
        } else return -1;

        return root.data;
    }

    public static void main(String[] args) {

        boolean verify;
        int[] n = new int[2];
        int[][] arr = new int[2][10];

        Scanner sc = new Scanner(System.in);
        BinarySearchTree q5tree = new BinarySearchTree();

        q5tree.insert(20);
        q5tree.insert(8);
        q5tree.insert(22);
        q5tree.insert(22);
        q5tree.insert(4);
        q5tree.insert(12);
        q5tree.insert(10);
        q5tree.insert(14);

         do {
            verify = false;
            for (int i = 0; i < 2; i++) {

                System.out.print("Enter tree Element " + (i+1) +" : ");
                n[i] = sc.nextInt();

                try { findAncestors(q5tree.root, n[i], arr[i]); }
                catch(NullPointerException e){
                    System.out.println(n[i] + " Does not Exist in Tree..!!!\nEnter Elements again...");
                    verify = true;
                    break;
                }
            }
        } while(verify);

        for (int i = 0; i < 2; i++) {
            System.out.print("\nAncestor of " + n[i] + " : ");

            for (int j = 0; arr[i][j] != 0; j++)
                System.out.print(arr[i][j] + " ");
        }

        System.out.println("\nLowest Common Ancestor : " + findLowestCommonAncestor(q5tree.root, n[0], n[1]));

//        q5tree.inOrder();

    }
}
