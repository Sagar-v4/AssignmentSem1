package Assignment2;

public class Q4 {

    Node head = null;

    static class Node{
        int data;
        Node next;
        Node prev;

        Node(int x){
            data = x;
            next = null;
            prev = null;
        }
    }

    void insert(int x) {
        Node node = new Node(x);

        if(head == null) {
            head = node;
            return;
        }

        Node curr = head;
        while(curr.next != null){
            curr = curr.next;
        }

        curr.next = node;
        node.prev = curr;

    }

    void removeElement(int delPosition)
    {
        if (head == null || delPosition == 0)
            return;

        Node curr = head;
        int i = 1;

        while (curr.next != null) {

            if(++i == delPosition ){
                curr.next = curr.next.next;
                break;
            }
            curr = curr.next;
        }
    }

    void printList() {
        Node node = head;

        while (node != null) {
            System.out.print(node.data + " ");
            node = node.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {

        Q4 list = new Q4();

        for (int i = 0; i < 6; i++)
            list.insert(i+1);

        System.out.print("Original : ");
        list.printList();

        list.removeElement(3);

        System.out.print("After Deleting(pos=3) : ");
        list.printList();
    }
}
