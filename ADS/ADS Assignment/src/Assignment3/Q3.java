package Assignment3;

import java.util.Objects;

public class Q3 {

    Node head = null;

    static class Node{
        String data;
        Node next;

        Node(String x){
            data = x;
            next = null;
        }
    }

    void insert(String s) {
        Node node = new Node(s);

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

    void merge(Node node){
        Node temp = head;
        while(temp != null) {
            if (temp.next == null){
                temp.next = node;
                break;
            }
            temp = temp.next;
        }
    }

    Node getByValue(String s){
        Node temp = head;
        while(temp != null) {
            if(Objects.equals(temp.data, s)){
                break;
            }
            temp = temp.next;
        }
        return temp;
    }

    static void printIntersection(Q3 l1, Q3 l2) {
        Node list1 = l1.head;
        while(list1 != null) {
            Node list2 = l2.head;
            while(list2 != null) {
                if (list2 == list1){
                    System.out.print(list2.data);
                    return;
                }
                list2 = list2.next;
            }
            list1 = list1.next;
        }
    }

    public static void main(String[] args) {

        Q3 ll1 = new Q3();
        Q3 ll2 = new Q3();

        ll1.insert("a1");
        ll1.insert("a2");
        ll1.insert("c1");
        ll1.insert("c2");
        ll1.insert("c3");

        ll2.insert("b1");
        ll2.insert("b2");
        ll2.insert("b3");
        ll2.merge(ll1.getByValue("c1"));

        System.out.print("Link List 1 : ");
        ll1.printList();

        System.out.print("Link List 2 : ");
        ll2.printList();

        System.out.print("Intersect Data : ");
        printIntersection(ll1, ll2);

    }
}
