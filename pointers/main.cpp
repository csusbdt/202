#include <iostream>
#include <cassert>

using namespace std;

int main(int argc, char * argv[]) {
	// The following definition of x allocates memory
	// on the program stack to store an integer value.
	int x;

	// On every computer I have worked on, 4 bytes of
	// memory is used to store an int, although this is
	// not required by any version of C++.  See the 
	// following stackoverflow post for additional details:
	// https://stackoverflow.com/questions/589575/what-does-the-c-standard-state-the-size-of-int-long-type-to-be
	assert(sizeof(x) == 4);

	// The following statement allocates memory on the program stack 
	// to store the memory address of an int. The datatype of ptr
	// is called a "pointer" or an "int pointer" to be more precise.
	int * ptr;

	// On 32-bit computers, 4 bytes are allocated to store pointers.
	// On 64-bit computers, 8 bytes are allocated to store pointers.
	assert(sizeof(ptr) == 4 or sizeof(ptr) == 8);

	// The following statement assigns the address of x
	// to ptr.  The ampersand in this statement is called 
	// the "address of operator." (Note: When used with function 
	// parameters, an ampersand indicates a "reference," which
	// is essentially a pointer.)
	ptr = &x;

	// The following statement assigns the value 3 to x by
	// using the "deference operator."
	*ptr = 3;

	// Think about this way: 
	// "ptr" represents the memory used to reference x and
	// "*ptr" represents the memory used to store x,
	// whence the term "dereference."

	// The following assertion proves that x has been set
	// to 3 through the pointer.
	assert(x == 3);

	// When we created ptr, we did not initialize it. so the
	// resulting address assigned to ptr is essentially random.
	// This makes debugging more difficult because the program
	// is non-deterministic.  To eliminate this problem, it is
	// a good idea to initialize pointers to a specific value.
	// If you have nothing to assign the pointer to, then assign
	// it the value zero, which is the address of the first byte
	// in memory.  It is illegal to read from or write to
	// the zero address.  The following code will crash the program.
	// Uncomment and run the following to see the result.
	//ptr = 0;
	//*ptr = 1;

	// It's better to consistenly crash with each run than to 
	// crash only sometimes, so initialize pointers to zero when
	// you have nothing else to assign to them.

	//  For increased redability, use nullptr rather than 0.
	ptr = nullptr;
	assert(nullptr == (void *) 0);

	// Most computers these days store multi-byte numbers
	// so that the least significant byte comes first.
	// This is also called "little endian" byte order.
	// "Big endian" means the opposite: most significant
	// byte first. The following code runs without fail
	// on little endian machines.
	x = 0x11223344;
	ptr = &x;
	unsigned char * a = (unsigned char *) ptr;
	assert(a[0] == 0x44);
	assert(a[1] == 0x33);
	assert(a[2] == 0x22);
	assert(a[3] == 0x11);

	// The following code does the same as above but uses
	// pointer arithmetic syntax rather than array syntax.
	assert(*a == 0x44);
	assert(*(a + 1) == 0x33);
	assert(*(a + 2) == 0x22);
	assert(*(a + 3) == 0x11);

	cout << "All tests passed." << endl;
}

