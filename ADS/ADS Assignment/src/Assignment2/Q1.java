package Assignment2;

public class Q1 {

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

    void reverse()
    {
        Node prev = null;
        Node current = head;
        Node next;
        while (current != null) {
            next = current.next;
            current.next = prev;
            prev = current;
            current = next;
        }
        head = prev;
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

        Q1 list = new Q1();
        for (int i = 0; i < 5; i++)
            list.insert(i+1);

        System.out.print("Original : ");
        list.printList();

        list.reverse();

        System.out.print("Reverse : ");
        list.printList();
    }
}
