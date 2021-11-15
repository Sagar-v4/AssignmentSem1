package Assignment7;

class Node
{
    int key;
    Node left, right;

    public Node(int item)
    {
        this.key = item;
        left = right = null;
    }
}

class BinaryTree
{
    Node root;
    BinaryTree() { root = null; }
    BinaryTree(int key) { root = new Node(key); }

    void implementTree(BinaryTree binaryTree) {

        binaryTree.root = new Node(1);

        binaryTree.root.left = new Node(2);
        binaryTree.root.right = new Node(3);

        binaryTree.root.left.left = new Node(4);
        binaryTree.root.left.right = new Node(5);

        binaryTree.root.right.left = new Node(6);
        binaryTree.root.right.right = new Node(7);

        binaryTree.root.left.left.right = new Node(8);

        binaryTree.root.left.right.right = new Node(9);

        binaryTree.root.right.right.left = new Node(10);
        binaryTree.root.right.right.right = new Node(11);

        binaryTree.root.left.left.right.right = new Node(12);
    }

    int heightOfTree(Node node)
    {
        if (node == null)
            return -1;
        else
        {
            int lHeight = heightOfTree(node.left);
            int rHeight = heightOfTree(node.right);
            return (lHeight > rHeight) ? (lHeight + 1) : (rHeight + 1);
        }
    }
}

public class Q1 {

    public static void main(String[] args) {

        BinaryTree q1tree = new BinaryTree();

        q1tree.implementTree(q1tree);
        System.out.println("Height : " + q1tree.heightOfTree(q1tree.root));
    }
}
