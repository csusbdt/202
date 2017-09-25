#include <iostream>
#include <cassert>

using namespace std;

class Integer {
public:
	Integer() : n(0) {}
	Integer(int n) : n(n) {}
	bool even() { return n % 2 == 0; }
	bool operator==(const Integer & i) { return i.n == n; }

private:
	int n;
};
	

template <class T>
class Stack {
public:
	Stack();
	~Stack();
	int size() const;
	bool empty() const;
	void push(T x);
	void pop();
	T & top();

private:
	void ensureCapacity(int c);

	T * data;
	int capacity;  // capacity of data array
	int n;         // number of elements in stack
};

template <class T>
Stack<T>::Stack() : data(nullptr), capacity(0), n(0) { 
}

template <class T>
Stack<T>::~Stack() { 
	delete [] data; // Deleting nullptr does nothing.
}

template <class T>
void Stack<T>::ensureCapacity(int minCapacity) {
	if (minCapacity <= capacity) return;
	T * oldData = data;
	data = new T[minCapacity];
	for (int i = 0; i < n; ++i) {
		data[i] = oldData[i];
	}
	delete [] oldData;
	capacity = minCapacity;
}

template <class T>
void Stack<T>::push(T x) {
	ensureCapacity(n + 1);
	data[n++] = x;
}

template <class T>
void Stack<T>::pop() {
	assert(n > 0);
	--n;
}

template <class T>
T & Stack<T>::top() {
	assert(n > 0);
	return data[n - 1];
}

template <class T>
int Stack<T>::size() const {
	return n;
}

template <class T>
bool Stack<T>::empty() const {
	return n == 0;
}

int main(int argc, char * args[]) {
	Stack<Integer> s;
	assert(s.empty());
	assert(s.size() == 0);
	s.push(Integer(1));
	assert(not s.empty());
	assert(s.size() == 1);
	assert(s.top() == Integer(1));
	s.pop();
	assert(s.empty());
	assert(s.size() == 0);

	s.push(Integer(1));
	assert(not s.empty());
	assert(s.size() == 1);
	assert(s.top() == Integer(1));
	s.push(Integer(2));
	assert(not s.empty());
	assert(s.size() == 2);
	assert(s.top() == Integer(2));
	s.pop();
	assert(not s.empty());
	assert(s.size() == 1);
	assert(s.top() == Integer(1));
	s.push(Integer(2));
	assert(not s.empty());
	assert(s.size() == 2);
	assert(s.top() == Integer(2));
	s.push(Integer(3));
	assert(not s.empty());
	assert(s.size() == 3);
	assert(s.top() == Integer(3));

	cout << "All tests passed." << endl;
}

