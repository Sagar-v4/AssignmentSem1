package Assignment6;

public class Q3 {

    static void preOrder(Node node) {

        if (node == null)
            return;

        System.out.print(node.key + " ");

        preOrder(node.left);

        preOrder(node.right);
    }

    public static void main(String[] args) {

        BinaryTree q3tree = new BinaryTree();

        q3tree.implementTree(q3tree);

        System.out.println("Pre Order traversal : ");

        preOrder(q3tree.root);
    }
}
