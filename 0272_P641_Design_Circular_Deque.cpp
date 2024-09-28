/*
Day: 272
Problem Number: 641 (https://leetcode.com/problems/design-circular-deque)
Date: 28-09-2024
Description:
Design your implementation of the circular double-ended queue (deque).
Implement the MyCircularDeque class:
* MyCircularDeque(int k) Initializes the deque with a maximum size of k.
* boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful, or false otherwise.
* boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful, or false otherwise.
* boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful, or false otherwise.
* boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful, or false otherwise.
* int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
* int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
* boolean isEmpty() Returns true if the deque is empty, or false otherwise.
* boolean isFull() Returns true if the deque is full, or false otherwise.
 
Example 1:
Input
["MyCircularDeque", "insertLast", "insertLast", "insertFront", "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 2, true, true, true, 4]

Explanation
MyCircularDeque myCircularDeque = new MyCircularDeque(3);
myCircularDeque.insertLast(1);  // return True
myCircularDeque.insertLast(2);  // return True
myCircularDeque.insertFront(3); // return True
myCircularDeque.insertFront(4); // return False, the queue is full.
myCircularDeque.getRear();      // return 2
myCircularDeque.isFull();       // return True
myCircularDeque.deleteLast();   // return True
myCircularDeque.insertFront(4); // return True
myCircularDeque.getFront();     // return 4
 
Constraints:
* 1 <= k <= 1000
* 0 <= value <= 1000
* At most 2000 calls will be made to insertFront, insertLast, deleteFront, deleteLast, getFront, getRear, isEmpty, isFull.

Code:  */
class MyCircularDeque {
public:
    vector<int> q;
    int front = 0;
    int size = 0;
    int capacity = 0;

    MyCircularDeque(int k) {
        q.assign(k, 0);
        capacity = k;
    }

    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        if (!isEmpty()) {
            front = (front - 1 + capacity) % capacity;
        }
        q[front] = value;
        ++size;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        int idx = (front + size) % capacity;
        q[idx] = value;
        ++size;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        front = (front + 1) % capacity;
        --size;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        --size;
        return true;
    }

    int getFront() {
        return isEmpty() ? -1 : q[front];
    }

    int getRear() {
        return isEmpty() ? -1 : q[(front + size - 1) % capacity];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
