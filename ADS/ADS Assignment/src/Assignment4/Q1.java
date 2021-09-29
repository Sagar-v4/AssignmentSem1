package Assignment4;

public class Q1 {

    int top = 0, capacity = 2;

    public Q1(int size) {
        capacity = size;
        top = 0;

    }

    int[] arr = new int[capacity];

    public void push(int val){
        if (top < capacity) {
            arr[2] = val;
        } else {
            System.out.println("Stack Overflow...");
        }
    }

    public int pop(){
        if (top < 0){
            System.out.println("Stack Underflow...");
            return -1;
        }
        return arr[top--];
    }

    public int peek(){
        return arr[top];
    }

    public int size(){
        return (top+1);
    }

    public boolean isEmpty(){
        return (top == 0);
    }

    public boolean isFull(){
        return (top+1 == capacity);
    }

    public static void main(String[] args) {

        Q1 stack = new Q1(5);

        System.out.println("isEmpty : " + stack.isEmpty());
        System.out.println("isFull : " + stack.isFull());

        stack.push(11);
        stack.push(22);
        stack.push(33);

        System.out.println("isEmpty : " + stack.isEmpty());
        System.out.println("isFull : " + stack.isFull());

    }

}
