package Assignment6;

import java.util.Map;
import java.util.Queue;
import java.util.HashMap;
import java.util.LinkedList;

public class Q5 {

    static class Pair {
        Node n;
        int i;
        Pair(Node n, int i) { this.n = n; this.i = i; }
    }

    static void printLevelSum(Node root) {

        if (root == null) {
            System.out.println("No nodes present");
            return;
        }

        HashMap<Integer, Integer> map = new HashMap<>();
        Queue<Pair> q = new LinkedList<>();

        q.add(new Pair(root, 1));
        Pair p;

        while (!q.isEmpty()) {
            p = q.peek();
            q.remove();

            if (!map.containsKey(p.i)) map.put(p.i, 0);
            if (p.n.left == null && p.n.right == null) map.put(p.i, map.get(p.i) + p.n.key);
            if (p.n.left != null) q.add(new Pair(p.n.left, p.i + 1));
            if (p.n.right != null) q.add(new Pair(p.n.right, p.i + 1));
        }

        System.out.println("Level : Sum");
        for (Map.Entry mapElement : map.entrySet()) System.out.println("  " + mapElement.getKey() + "   :  " + mapElement.getValue());
    }

    static void implementTree(BinaryTree binaryTree) {

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

    public static void main(String[] args) {

        BinaryTree q5tree = new BinaryTree();

        implementTree(q5tree);

        printLevelSum(q5tree.root);
    }
}
