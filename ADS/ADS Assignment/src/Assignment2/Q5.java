package Assignment2;

public class Q5 {

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

    int findMiddle()
    {
        Node doubleJump = head;
        Node singleJump = head;

        while(doubleJump != null && doubleJump.next != null){
            doubleJump = doubleJump.next.next;
            singleJump = singleJump.next;
        }
        assert singleJump != null;
        return singleJump.data;
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

        Q5 list = new Q5();
        for (int i = 0; i < 7; i++)
            list.insert(i+1);

        System.out.print("Original : ");
        list.printList();

        System.out.print("Middle : " + list.findMiddle() + "\n");

    }
}
