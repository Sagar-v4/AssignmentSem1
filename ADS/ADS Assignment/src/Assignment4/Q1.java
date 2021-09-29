package Assignment4;

public class Q1 {

    int top = 0, capacity;
    int[] arr = new int[100];

    public Q1(int size) { this.capacity = size; }

    public void push(int val){ if (top < capacity) arr[top++] = val; }

    public int pop() { return (top <= 0) ? 0 : arr[--top]; }

    public int peek() { return (top > 0 && capacity >= top) ? arr[top - 1] : 0; }

    public int size() { return top; }

    public boolean isEmpty() { return top == 0; }

    public boolean isFull() { return top >= capacity; }

    public static void main(String[] args) {

        Q1 stack1 = new Q1(5);

        System.out.println("isEmpty : " + stack1.isEmpty());
        System.out.println("isFull : " + stack1.isFull());

        stack1.push(11);
        stack1.push(22);
        stack1.push(33);
        stack1.push(44);
        stack1.push(55);
        stack1.push(66);

        System.out.println("Size : " + stack1.size());
        System.out.println("Peek : " + stack1.peek());
        System.out.println("isEmpty : " + stack1.isEmpty());
        System.out.println("isFull : " + stack1.isFull());
        System.out.println("Pop : " + stack1.pop());
        System.out.println("Size : " + stack1.size());
        System.out.println("Peek : " + stack1.peek());
        System.out.println("isEmpty : " + stack1.isEmpty());
        System.out.println("isFull : " + stack1.isFull());




    }

}
