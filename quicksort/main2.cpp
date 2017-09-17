#include <iostream>
#include <cassert>

using namespace std;

template <class T>
void quicksort(T a[], int s, int e) {
	if (e - s < 1) return;
	int i = s - 1;
	for (int j = s; j < e; ++j) {
		if (a[j] < a[e]) swap(a[++i], a[j]);
	}
	swap(a[++i], a[e]);
	quicksort<T>(a, s, i - 1);
	quicksort<T>(a, i + 1, e);
}

int main(int argc, char * args[]) {
	int a[] = { 2, -9, 122, 45, -7, 33, -7, 16, 99, 21 };
	quicksort<int>(a, 0, 9);
	assert(a[0] == -9);
	assert(a[1] == -7);
	assert(a[2] == -7);
	assert(a[3] == 2);
	assert(a[4] == 16);
	assert(a[5] == 21);
	assert(a[6] == 33);
	assert(a[7] == 45);
	assert(a[8] == 99);
	assert(a[9] == 122);

	int b[] = { 2 };
	quicksort<int>(b, 0, 0);
	assert(b[0] == 2);

	int c[] = { 2, 2 };
	quicksort<int>(c, 0, 1);
	assert(c[0] == 2);
	assert(c[1] == 2);

	int d[] = { 2, -2 };
	quicksort<int>(d, 0, 1);
	assert(d[0] == -2);
	assert(d[1] == 2);

	cout << "All tests passed." << endl;	
}

