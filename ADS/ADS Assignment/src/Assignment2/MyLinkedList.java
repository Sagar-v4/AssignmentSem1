package Assignment2;

public class MyLinkedList {
    Node head;

    static class Node{
        int data;
        Node next;

        Node(int x){
            data = x;
            next = null;
        }
    }

    public MyLinkedList() {
        // TODO Auto-generated constructor stub
        head = null;
    }

    public MyLinkedList(int x) {
        head = new Node(x);
    }

    /**
     * Insert at beginning
     * @param x
     */
    void insertAtStart(int x) {
        Node node = new Node(x);

        node.next = head;

        head = node;
    }

    /**
     * Insert at end
     * @param x
     */
    void insertAtEnd(int x) {
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

    /**
     * Insert x after node having data k
     * @param x
     * @param k
     */
    void insertAfter(int x, int k) {
        Node node = new Node(x);

        Node temp = head;
        while(temp.data != k) {
            temp = temp.next;
        }

        node.next = temp.next;
        temp.next = node;
    }

    /**
     * Delete start(head) of linked list
     */
    void deleteStart() {
        if(head == null)
            return;

        head = head.next;
    }

    /**
     * Delete the end node of linked list
     */
    void deleteEnd() {
        if(head == null)
            return;

        if(head.next == null) {
            head = null;
            return;
        }

        Node temp = head;
        while(temp.next.next != null) {
            temp = temp.next;
        }
        temp.next = null;
    }

    /**
     * Delete particular element
     * @param k
     */
    void delete(int k) {
        if(head == null)
            return;

        Node temp = head;
        Node prev = head;

        while(temp.data != k) {
            prev = temp;
            temp = temp.next;
        }

        prev.next = temp.next;
    }

    /**
     * Prints the entire linked list
     */
    void printList() {
        Node temp = head;
        while(temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    /**
     * Driver code
     * @param args
     */
    public static void main(String[] args) {
        MyLinkedList ll = new MyLinkedList();
        ll.insertAtEnd(2);
        ll.insertAtStart(1);
        ll.insertAtEnd(4);
        ll.insertAfter(3, 2);

        ll.printList();

        ll.deleteStart();
        ll.deleteEnd();
        ll.delete(3);

        ll.printList();
    }
}
