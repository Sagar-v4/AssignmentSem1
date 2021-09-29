package Assignment4;

import com.sun.deploy.util.SyncAccess;

public class Q5 {

    int[] arr = new int[100];

    public Q5(int size) {
        this.capacity = size;
        this.topR = size - 1;
        this.topL = 0;
    }

    int topL, topR, capacity;

    public void pushL(int val){ if (topL <= topR) arr[topL++] = val; }

    public void pushR(int val){ if (topL <= topR) arr[topR--] = val; }

    public int popL() {
        int ans = (topL <= 0) ? 0 : arr[--topL];
        arr[topL] = 0;
        return ans;

    }

    public int popR() {
        int ans = (topR >= capacity) ? 0 : arr[++topR];
        arr[topR] = 0;
        return ans;
    }

    public int peekL() { System.out.println(topL); return (topL > 0 && topR + 1 >= topL) ? arr[topL - 1] : 0; }

    public int peekR() { System.out.println(topR); return (topR > 0 && capacity >= topL) ? arr[topR + 1] : 0; }

    public int sizeL() { return topL; }

    public int sizeR() { return capacity-topR-1; }

    public boolean isEmpty() { return (topL == 0) && (topR == capacity - 1); }

    public boolean isFull() { return topL > topR; }

    public void print() {
        for (int i = 0; i < capacity; i++) {
            System.out.print(arr[i] + " ");
        }
    }

    public static void main(String[] args) {
        Q5 stack = new Q5(10);


        System.out.println("Empty : " + stack.isEmpty());
        System.out.println("Full : " + stack.isFull());


//        stack.pushR(90);
//        stack.pushR(91);

        stack.pushL(11);
        stack.pushL(12);
        stack.pushL(13);
        stack.pushL(14);
        stack.pushL(15);
        stack.pushL(16);
        stack.pushL(17);
//        stack.pushL(18);
//        stack.pushL(19);
//        stack.pushL(20);
//        stack.pushL(21);

//        System.out.println(stack.popL());
//        System.out.println(stack.popL());


        stack.pushR(91);
        stack.pushR(92);
        stack.pushR(93);
        stack.pushR(94);
        stack.pushR(95);
        stack.pushR(96);
//        stack.pushR(97);
//        stack.pushR(98);
//        stack.pushR(99);
//        stack.pushR(100);
//        stack.pushR(101);

//        System.out.println(stack.popR());
//        System.out.println(stack.popR());
//        System.out.println(stack.popR());

        System.out.println("Size L : " + stack.sizeL());
        System.out.println("Size R : " + stack.sizeR());

        System.out.println("PEEK L : " + stack.peekL());
        System.out.println("PEEK R : " + stack.peekR());

        System.out.println("Empty : " + stack.isEmpty());
        System.out.println("Full : " + stack.isFull());

        stack.print();
    }
}
