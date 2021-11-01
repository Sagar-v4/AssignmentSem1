package Assignment6;

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

        binaryTree.root.left.left.left = new Node(8);
        binaryTree.root.left.left.right = new Node(9);

        binaryTree.root.left.right.left = new Node(10);
        binaryTree.root.left.right.right = new Node(11);

        binaryTree.root.right.left.right = new Node(13);

        binaryTree.root.right.right.left = new Node(14);
    }
}

public class Q1 {

    public static void main(String[] args) {

        BinaryTree q1tree = new BinaryTree();

        q1tree.implementTree(q1tree);
    }
}
