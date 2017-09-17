#include <iostream>
#include <cassert>

using namespace std;

// s = start of range to sort
// e = end of range to sort
void msort(int a[], int x[], int s, int e) {
	// If there are less than 2 values to sort,
	// then there is nothing to do, so break recursion.
	if (e - s < 1) return;

	// Divide range into two ranges.
	// m = midpoint
	int m = (s + e) / 2;

	// Sort first range.
	msort(a, x, s, m);

	// Sort second range.
	msort(a, x, m + 1, e);

	// Copy values from a into x.
	for (int i = s; i <= e; ++i) x[i] = a[i];

	// Merge the two sorted subranges while
	// copying values from x back into a.

	int j = s;      // j = index into first range
	int k = m + 1;  // k = index into second range
	for (int i = s; i <= e; ++i) {
		     if (j > m)       a[i] = x[k++];
		else if (k > e)       a[i] = x[j++];
		else if (x[j] < x[k]) a[i] = x[j++];
		else                  a[i] = x[k++];
	}
}

void mergesort(int a[], int n) {
	int * x = new int[n];
	msort(a, x, 0, n - 1);
	delete [] x;
}

bool sorted(int a[], int n) {
	for (int i = 0; i < n - 1; ++i) {
		if (a[i] > a[i + 1]) return false;
	}
	return true;
}

int main(int argc, char * args[]) {
	int a[1000];
	for (int i = 0; i < 1000; ++i) a[i] = -50 + rand() % 100;
	mergesort(a, 1000);
	assert(sorted(a, 1000));

	int b[1001];
	for (int i = 0; i < 1001; ++i) b[i] = -50 + rand() % 100;
	mergesort(b, 1001);
	assert(sorted(b, 1001));

	int c[] = { 2 };
	mergesort(c, 1);
	assert(sorted(c, 1));

	int d[] = { 1, 2, 3, 4, 5 };
	mergesort(d, 5);
	assert(sorted(d, 5));

	cout << "All tests passed." << endl;	
}

