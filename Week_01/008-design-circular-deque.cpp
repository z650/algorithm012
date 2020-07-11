class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    int *data;
    int front, rear, cap;
    MyCircularDeque(int k) {
        data = new int[k + 1];
        front = rear = 0;
        cap = k + 1;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + cap) % cap;
        data[front] = value;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) return false;
        data[rear] = value;
        rear = (rear + 1) % cap;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % cap;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + cap) % cap;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) return -1;
        return data[front];
    }

    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty()) return -1;
        return data[(rear - 1 + cap) % cap];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return front == rear;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return (rear + 1) % cap == front;
    }
};