package Assignment7;

public class Q4 {

    private static final int[] arr = new int[10];
    private static int i = 0;

    public static void addInArr(BinarySearchTree.Node root)
    {
        if (root != null) {
            addInArr(root.left);
            arr[i++] = root.data;
            addInArr(root.right);
        }
    }

    public static int findMedian(int[] arr, int n)
    {
        int medianIndex;
        medianIndex = (n % 2 == 0) ? (((n/2) + ((n/2)+1)) / 2): ((n+1)/2);
        return arr[medianIndex - 1];
    }

    public static void main(String[] args) {

        int n;
        BinarySearchTree q4tree = new BinarySearchTree();

        q4tree.insert(20);
        q4tree.insert(8);
        q4tree.insert(22);
        q4tree.insert(4);
        q4tree.insert(12);
        q4tree.insert(10);
        q4tree.insert(14);

        addInArr(q4tree.root);

        System.out.print("Tree Elements : ");
        for (n = 0; arr[n] != 0; n++) { System.out.print(arr[n] + " "); }

        System.out.println("\nMedian = " + findMedian(arr, n));

    }
}
