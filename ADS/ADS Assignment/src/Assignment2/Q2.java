package Assignment2;

public class Q2 {

    Node head = null;

    static class Node{
        int data;
        Node next;

        Node(int x){
            data = x;
            next = null;
        }
    }

    void insert(int x) {
        Node node = new Node(x);

        if(head == null) {
            head = node;
            return;
        }

        Node temp = head;
        while(temp.next != null) {
            temp = temp.next;
        }

        temp.next = node;
    }

    void removeDuplicates()
    {
        Node curr = head;

        while (curr != null) {
            Node temp = curr;
            while(temp != null && temp.data == curr.data) {
                temp = temp.next;
            }
            curr.next = temp;
            curr = curr.next;
        }
    }

    void printList() {
        Node temp = head;
        while(temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {

        Q2 list = new Q2();

        list.insert(1);
        list.insert(2);
        list.insert(2);
        list.insert(3);
        list.insert(4);
        list.insert(4);

        System.out.print("Original : ");
        list.printList();

        list.removeDuplicates();

        System.out.print("Duplicates Removed : ");
        list.printList();
    }
}
