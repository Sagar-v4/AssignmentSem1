package Assignment6;

public class Q4 {

    static void postOrder(Node node) {

        if (node == null)
            return;

        postOrder(node.left);

        postOrder(node.right);

        System.out.print(node.key + " ");
    }

    public static void main(String[] args) {

        BinaryTree q4tree = new BinaryTree();

        q4tree.implementTree(q4tree);

        System.out.println("Post Order traversal : ");

        postOrder(q4tree.root);
    }
}
