package Assignment5;

class Stack{

    int top = -1, capacity;
    public Stack(int size){ this.capacity = size; }

    IntQueue q1 = new IntQueue(capacity);
    IntQueue q2 = new IntQueue(capacity);

    public void push(int n) {

        if ( top < capacity - 1) {
            q1.enqueue(n);
            ++top;
        }
    }

    public int pop(){

        int i, val = 0;
        if(size() > 0 ) {
            for (i = 0; i < size() - 1; i++)
                q2.enqueue(q1.dequeue());

            val = q1.dequeue();
            top--;
            for (i = 0; i < size(); i++)
                q1.enqueue(q2.dequeue());

        }
        return val;
    }

    public int peek(){

        int i, val = 0;
        if(size() > 0 ) {
            for (i = 0; i < size() - 1; i++)
                q2.enqueue(q1.dequeue());

            val = q1.dequeue();
            for (i = 0; i < size() - 1; i++)
                q1.enqueue(q2.dequeue());

            q1.enqueue(val);
        }
        return val;
    }

    public void displayStack(){

        if(size() > 0 ) {
            int[] tempArr = new int[capacity];

            for (int i = 0; i < size() ; i++)
                tempArr[i] = q1.dequeue();

            for (int i = 0; i < size() ; i++)
                q1.enqueue(tempArr[i]);

            for (int i = size() - 1; i >= 0 ; i--)
                System.out.println(tempArr[i]);
        }
    }

    public int size() { return top+1; }

    public boolean isEmpty() { return (size() == 0); }

    public boolean isFull() { return (size() == capacity); }

}

public class Q4 {

    public static void main(String[] args) {

        Stack s = new Stack(3);

        System.out.println("empty : " + s.isEmpty());
        System.out.println("full : " + s.isFull());

        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4);
        s.push(5);

        s.displayStack();

        System.out.println("empty : " + s.isEmpty());
        System.out.println("full : " + s.isFull());

        System.out.println("peek : " + s.peek());
        System.out.println("pop : " + s.pop());
        System.out.println("peek : " + s.peek());
        System.out.println("pop : " + s.pop());
        System.out.println("peek : " + s.peek());
        System.out.println("pop : " + s.pop());
        System.out.println("peek : " + s.peek());
        System.out.println("pop : " + s.pop());

        System.out.println("empty : " + s.isEmpty());
        System.out.println("full : " + s.isFull());

        s.displayStack();

    }
}
