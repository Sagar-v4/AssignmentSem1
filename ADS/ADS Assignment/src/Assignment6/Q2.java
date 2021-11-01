package Assignment6;

public class Q2 {

    static void inOrder(Node node) {

        if (node == null)
            return;

        inOrder(node.left);

        System.out.print(node.key + " ");

        inOrder(node.right);
    }

    public static void main(String[] args) {

        BinaryTree q2tree = new BinaryTree();

        q2tree.implementTree(q2tree);

        System.out.println("In Order traversal : ");

        inOrder(q2tree.root);
    }
}
