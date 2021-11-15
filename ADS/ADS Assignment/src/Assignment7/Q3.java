package Assignment7;

class BinarySearchTree
{
    static class Node {
        int data;
        Node left, right;

        public Node(int data) {
            this.data = data;
            left = right = null;
        }
    }

    Node root;
    BinarySearchTree() { root = null; }
    void insert(int x) { root = insertAt(root, x); }

    Node insertAt(Node root, int x) {
        if (root == null) return new Node(x);

        else {
            if (x < root.data) root.left = insertAt(root.left, x);
            else if (x > root.data) root.right = insertAt(root.right, x);
        }
        return root;
    }

    void delete(int x) { root = deleteAt(root, x); }

    Node deleteAt(Node root, int x) {

        if (root.data == x) return null;
        else {
            if (x < root.data) root.left = deleteAt(root.left, x);
            else root.right = deleteAt(root.right, x);
        }
        return root;
    }

    void inOrder() { inorderRec(root); }

    void inorderRec(Node root) {
        if (root != null) {
            inorderRec(root.left);
            System.out.print(root.data + " ");
            inorderRec(root.right);
        }
    }
}

public class Q3 {

    public static void main(String[] args) {

        BinarySearchTree q3tree = new BinarySearchTree();

        q3tree.insert(100);
        q3tree.insert(20);
        q3tree.insert(10);
        q3tree.insert(500);
        q3tree.insert(30);

        System.out.print("Before Insertion : ");
        q3tree.inOrder();

        q3tree.insert(40);

        System.out.print("\nAfter Insertion : ");
        q3tree.inOrder();

        q3tree.delete(500);

        System.out.print("\nAfter Deletion : ");
        q3tree.inOrder();

    }
}
