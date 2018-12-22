package com.algorithms.one;
import java.util.Iterator;
/**
 * @author PuZhiwei
 * 先进先出队列 链表实现
 * algorithms 4th P95
 * */

public class Queue<Item> implements Iterable<Item> {
    private Node first;
    private Node last;
    private int N;

    private class Node {
        Item item;
        Node next;
    }

    public boolean isEmpty() {
        return first == null;
    }

    public int size() {
        return N;
    }

    /**
     * 进队
     * */
    public void enQueue(Item item) {
        Node oldLast = last;
        last = new Node();
        last.item = item;
        last.next = null;
        if(isEmpty()) {
            first = last;
        } else {
            oldLast.next = last;
        }
        N++;
    }

    /**
     * 出队
     * */
    public Item deQueue() {
        Item item = first.item;
        first = first.next;
        if(isEmpty()) {
            last = null;
        }
        N--;
        return item;
    }

    /**
     * 迭代器，为方法使用 foreach 语句提供支持
     *
     * */
    @Override
    public Iterator<Item> iterator() {
        return new QueueIterator();
    }

    private class QueueIterator implements Iterator<Item> {
        private Node current = first;

        @Override
        public boolean hasNext() {
            return current != null;
        }

        @Override
        public void remove() {

        }

        @Override
        public Item next() {
            Item item = current.item;
            current = current.next;
            return item;
        }
    }
}
