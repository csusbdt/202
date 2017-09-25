#include <iostream>
#include <cassert>

using namespace std;

class Stack {
public:
	Stack();
	~Stack();
	int size() const;
	bool empty() const;
	void push(int k);
	void pop();
	int & top();

private:
	void ensureCapacity(int c);

	int * data;
	int capacity;  // capacity of data array
	int n;         // number of elements in stack
};

Stack::Stack() : data(nullptr), capacity(0), n(0) { 
}

Stack::~Stack() { 
	delete [] data; // Deleting nullptr does nothing.
}

void Stack::ensureCapacity(int minCapacity) {
	if (minCapacity <= capacity) return;
	int * oldData = data;
	data = new int[minCapacity];
	for (int i = 0; i < n; ++i) {
		data[i] = oldData[i];
	}
	delete [] oldData;
	capacity = minCapacity;
}

void Stack::push(int k) {
	ensureCapacity(n + 1);
	data[n++] = k;
}

void Stack::pop() {
	assert(n > 0);
	--n;
}

int & Stack::top() {
	assert(n > 0);
	return data[n - 1];
}

int Stack::size() const {
	return n;
}

bool Stack::empty() const {
	return n == 0;
}

int main(int argc, char * args[]) {
	Stack s;
	assert(s.empty());
	assert(s.size() == 0);
	s.push(1);
	assert(not s.empty());
	assert(s.size() == 1);
	assert(s.top() == 1);
	s.pop();	
	assert(s.empty());
	assert(s.size() == 0);

	s.push(1);
	assert(not s.empty());
	assert(s.size() == 1);
	assert(s.top() == 1);
	s.push(2);
	assert(not s.empty());
	assert(s.size() == 2);
	assert(s.top() == 2);
	s.pop();	
	assert(not s.empty());
	assert(s.size() == 1);
	assert(s.top() == 1);
	s.push(2);
	assert(not s.empty());
	assert(s.size() == 2);
	assert(s.top() == 2);
	s.push(3);
	assert(not s.empty());
	assert(s.size() == 3);
	assert(s.top() == 3);

	cout << "All tests passed." << endl;
}

