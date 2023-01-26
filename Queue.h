#ifndef QUEUE_H
#define QUEUE_H

template <typename T, int CAP>
class Queue {
public:
	Queue() {
		front = back = 0;
	}

	void enqueue(const T& item) {
		if (isFull())
			throw runtime_error("Queue is full");

		q[back] = item;
		back = (back + 1) % CAP;
	}

	T dequeue() {
		if (isEmpty())
			throw runtime_error("Queue is empty");

		T item = q[front];
		front = (front + 1) % CAP;

		return item;
	}

	bool isFull() {
		return getSize() == CAP - 1;
	}

	bool isEmpty() {
		return front == back;
	}

	int getSize() {
		return (CAP - front + back) / CAP;
	}
private:
	T q[CAP];
	int front; // The index of the first item of the queue
	int back; // The index of the cell after the last item in the queue
};
#endif 
