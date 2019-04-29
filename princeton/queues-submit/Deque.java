import java.util.Iterator;
import java.util.NoSuchElementException;

//I chose linked list implementation for this assignment
//because this assignment requires constant worst-time case.
// resizing array implementation can be found here: https://github.com/icuzns/proj1a/blob/master/ArrayDeque.java
public class Deque<Item> implements Iterable<Item>{
    private class Node {
        Item data;
        Node next;
        Node prev;
    }

    private Node firstNode;
    private Node lastNode;
    private int count;

    // construct an empty deque
    public Deque(){
        lastNode = null;
        firstNode = null;
        count = 0;
    }


    // is the deque empty?
    public boolean isEmpty() {
        return lastNode == null || firstNode == null;
    }

    // return the number of items on the deque
    public int size() {
        return count;
    }

    // add the item to the front
    public void addFirst(Item item) {
        if(item == null)
            throw new IllegalArgumentException();
        Node n = new Node();
        n.data = item;
        if(lastNode == null || firstNode == null) {
            lastNode = firstNode = n;
        } else {
            n.prev = firstNode;
            firstNode.next = n;
            firstNode = n;
        }
        count++;
    }

    // add the item to the end
    public void addLast(Item item) {
        if(item == null)
            throw new IllegalArgumentException();

        Node n = new Node();
        n.data = item;
        n.next = null;

        if(firstNode == null || lastNode == null) {
            lastNode = firstNode = n;
        } else {
            n.next = lastNode;
            lastNode.prev = n;
            lastNode = n;
        }
        count++;
    }

    // remove and return the item from the front
    public Item removeFirst() {
        if(isEmpty())
            throw new NoSuchElementException();
        Node n = firstNode;
        firstNode = n.prev;
        count--;
        return n.data;
    }

    // remove and return the item from the end
    public Item removeLast() {
        if(isEmpty())
            throw new NoSuchElementException();
        Node n = lastNode;
        lastNode = n.next;
        count--;
        return n.data;
    }

    // return an iterator over items in order from front to end
    public Iterator<Item> iterator() {
        return new DequeIterator();
    }

    private class DequeIterator implements Iterator<Item> {
        private Node current = firstNode;
        public boolean hasNext() { return current != null; }
        public void remove() { throw new UnsupportedOperationException(); }
        public Item next() {
            if(!hasNext())
                throw new NoSuchElementException();
            Item ret = current.data;
            current = current.prev;
            return ret;
        }
    }


    // unit testing code.
    public static void main(String[] args)   {
        Deque<Integer> data = new Deque<Integer>();
        data.addFirst(1);
        data.addFirst(2);
        data.addLast(3);

        for(int i : data) {
            System.out.println(i);
        }
    }
}
