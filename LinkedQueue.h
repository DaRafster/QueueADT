#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
class QueueNode {
public:
	QueueNode() {};
	QueueNode(const T& v) {
		value = b;
		next = nullptr;
	}

	T value;
	QueueNode<T>* next;
};

template <typename T>
class Queue {
public:
	Queue() {
		size = 0;
		front = back = nullptr;
	}

	~Queue() {
		while (front != nullptr) {
			QueueNode<T>* nextNode = front->next;
			delete front;
			front = nextNode;
		}
	}

	void enqueue(const T& item) {
		QueueNode<T>* nodeToInsert = new QueueNode(item);
		back->next = nodeToInsert;
		back = nodeToInsert;

		if (front == nullptr)
			front = nodeToInsert;

		size++;
	}

	T dequeue() {
		if (isEmpty())
			throw runtime_error("Queue is empty!");

		T value = front->value;
		QueueNode<T>* nodeToDelete = front;
		front = front->next;
		delete nodeToDelete;

		size--;

		if (size == 0)
			back == nullptr;

		return value;
	}

	int getSize() {
		return size;
	}

	bool isEmpty() {
		front == nullptr;
	}
private:
	StackNode<T>* top;
	int size;
};

#endif 

