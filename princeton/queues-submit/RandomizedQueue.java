import edu.princeton.cs.algs4.StdRandom;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class RandomizedQueue<Item> implements Iterable<Item> {
    // construct an empty randomized queue
    private int count;
    private int front;
    private int rear;
    private Item[] items;

    public RandomizedQueue() {
        count = 0;
        items = (Item[]) new Object[1];
        front = rear = 0;
    }

    private void resize(int n) {
        Item[] temp = (Item[]) new Object[n];
        int size = 0;
        for(int i = 0; i < n; i++) {
            temp[i] = items[(front + i) % items.length];
        }
        items = temp;
        front = 0;
        rear = count;
    }

    // is the randomized queue empty?
    public boolean isEmpty() {
        return count == 0;
    }
    // return the number of items on the randomized queue
    public int size() {
        return count;
    }
    // add the item
    public void enqueue(Item item) {
        if(item == null)
            throw new IllegalArgumentException();
        if(count == items.length) resize(2 * items.length);
        items[rear++] = item;
        if(rear == items.length) {
            rear = 0;
        }
        count++;
    }
    // remove and return a random item
    public Item dequeue() {
        if(isEmpty()) throw new NoSuchElementException();

        int rand = (front + StdRandom.uniform(count)) % items.length;
        Item ret = items[rand];
        items[rand] = items[front];
        items[front] = null;
        count--;
        front = (front+1) % items.length;
        if(count == items.length/4) resize(items.length / 2);
        return ret;
    }
    // return a random item (but do not remove it)
    public Item sample() {
        if(isEmpty()) {
            throw new NoSuchElementException();
        }
        return items[(front + StdRandom.uniform(count)) % items.length];
    }
    // return an independent iterator over items in random order
    public Iterator<Item> iterator() {
        return new RandomizedQueueIterator();

    }
    private class RandomizedQueueIterator implements Iterator<Item> {
        int current = 0;
        int[] perm = StdRandom.permutation(count);

        public boolean hasNext() {
            return current != perm.length;
        }
        public void remove() { throw new UnsupportedOperationException(); }
        public Item next() {
            if(!hasNext()) {
                throw new NoSuchElementException();
            }
            return items[perm[current++]];
        }
    }
    // unit testing (optional)
    public static void main(String[] args) {
        RandomizedQueue<Integer> queue = new RandomizedQueue<Integer>();

        for(int i = 0; i < 100; i++) {
            queue.enqueue(i);
        }

        for(int i = 0; i < 100; i++) {
            System.out.println(queue.dequeue());
        }
        System.out.println(queue.isEmpty());
    }
}
