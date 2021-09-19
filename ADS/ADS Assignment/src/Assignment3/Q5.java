package Assignment3;

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

    void printList() {
        Node temp = head;
        while(temp != null) {
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
        System.out.println();
    }

    void merge(Q5 l1, Q5 l2) {

        Node list1 = l1.head;
        Node list2 = l2.head;

        while(true) {

            if(list1 == null)
            {
                insert(list2.data);
                break;
            }
            if(list2 == null)
            {
                insert(list1.data);
                break;
            }

            if (list1.data <= list2.data){
                insert(list1.data);
                list1 = list1.next;
            } else {
                insert(list2.data);
                list2 = list2.next;
            }
        }
    }

    public static void main(String[] args) {

        Q5 ll1 = new Q5();
        Q5 ll2 = new Q5();
        Q5 ll3 = new Q5();

        ll1.insert(1);
        ll1.insert(2);
        ll1.insert(5);
        ll1.insert(9);
        ll1.insert(10);

        ll2.insert(2);
        ll2.insert(3);
        ll2.insert(6);
        ll2.insert(11);

        System.out.print("Link List 1 : ");
        ll1.printList();

        System.out.print("Link List 2 : ");
        ll2.printList();

        ll3.merge(ll1, ll2);
        System.out.print("After Merging : ");
        ll3.printList();

    }
}
