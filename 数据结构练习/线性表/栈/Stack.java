package com.algorithms.one;
import java.util.Iterator;
/**
 * @author PuZhiwei
 * 下压栈 链表实现
 * algorithms 4th P94
 * */

public class Stack<Item> implements Iterable<Item>{
    private Node first;
    private int N;


    /**
     * 定义节点嵌套类
     * */
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
     * 向栈顶添加元素
     * */
    public void push(Item item) {
        Node oldFirst = first;
        first = new Node();
        first.item = item;
        first.next = oldFirst;
        N++;
    }

    /**
     * 从栈顶删除元素
     * */
    public Item pop() {
        Item item = first.item;
        first = first.next;
        N--;
        return item;
    }

    /**
     * 迭代器，为方法使用 foreach 语句提供支持
     * */
    @Override
    public Iterator<Item> iterator() {
        return new StackIterator();
    }

    private class StackIterator implements Iterator<Item> {
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
