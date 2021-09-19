#include <iostream>
#include <string>
using namespace std;

template<int n>
struct Fibonacci {
	enum {
		value = Fibonacci<n - 1>::value + Fibonacci<n - 2>::value
	};
};

template<>
struct Fibonacci<0> {
	enum {
		value = 0
	};
};

template<>
struct Fibonacci<1> {
	enum {
		value = 1
	};
};

int main() {
	cout << "fib<0> = " << Fibonacci<0>::value << endl;
	cout << "fib<1> = " << Fibonacci<1>::value << endl;
	cout << "fib<2> = " << Fibonacci<2>::value << endl;
	cout << "fib<3> = " << Fibonacci<3>::value << endl;
	cout << "fib<4> = " << Fibonacci<4>::value << endl;
	cout << "fib<11> = " << Fibonacci<11>::value << endl;
	cout << "fib<12> = " << Fibonacci<12>::value << endl;
	cout << "fib<45> = " << Fibonacci<45>::value << endl;
	return 0;
}