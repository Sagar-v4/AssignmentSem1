package Assignment2;

public class Q3 {

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
            head.next = head;
            return;
        }

        Node temp = head;
        while(temp.next != head) {
            temp = temp.next;
        }

        temp.next = node;
        node.next = head;
    }

    int countNodes()
    {
        Node temp = head;
        int result = 0;
        if (head != null)
        {
            do
            {
                temp = temp.next;
                result++;
            } while (temp != head);
        }

        return result;
    }

    void printList() {
        Node temp = head;
        if (head != null)
        {
            do
            {
                System.out.print(temp.data + " ");
                temp = temp.next;
            } while (temp != head);
        }
        System.out.println();
    }

    public static void main(String[] args) {

        Q3 list = new Q3();

        for (int i = 0; i < 5; i++)
            list.insert(i+1);

        System.out.print("Original : ");
        list.printList();

        System.out.print("Total Count : " + list.countNodes() + "\n");
    }
}
