#include <iostream>
#include <cassert>

using namespace std;

template<class T>
class Array {
public:
	Array(int size);
	~Array();
	T & operator[](int i) const;
	int size() const;
	void fill(int k);
	T * begin();
	T * end();

private:
	int len;
	T * data;
};

template<class T>
Array<T>::Array(int size) : len(size) { 
	data = new T[len]; 
}

template<class T>
Array<T>::~Array() { 
	delete [] data;
}

template<class T>
T & Array<T>::operator[](int i) const {
	return data[i];
}

template<class T>
int Array<T>::size() const {
	return len;
}

template<class T>
void Array<T>::fill(int k) {
	for (int i = 0; i < len; ++i) data[i] = k;
}

template<class T>
T * Array<T>::begin() {
	return data;
}

template<class T>
T * Array<T>::end() {
	return data + len;
}

int main(int argc, char * args[]) {
	Array<int> a(3);
	//assert(a[0] == 0);
	//assert(a[1] == 0);
	//assert(a[2] == 0);
	a[0] = 10;
	a[1] = 11;
	a[2] = 12;
	assert(a[0] == 10);
	assert(a[1] == 11);
	assert(a[2] == 12);
	assert(a.size() == 3);
	a.fill(5);
	assert(a[0] == 5);
	assert(a[1] == 5);
	assert(a[2] == 5);
	a[0] = 3;
	a[1] = 1;
	a[2] = 2;
	sort(a.begin(), a.end());
	assert(a[0] == 1);
	assert(a[1] == 2);
	assert(a[2] == 3);
	int * it = a.begin();
	assert(*it == 1);
	++it;
	assert(*it == 2);
	++it;
	assert(*it == 3);
	++it;
	assert(it == a.end());

	cout << "All tests passed." << endl;
}

