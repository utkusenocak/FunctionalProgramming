#include <iostream>
#include <vector>
#include <functional>
#include <string>
using namespace std;

void demoFuntion() {
	cout << "Called Demo Function" << endl;
}

void adder(int a, int b) {
	cout << "Called adder, a + b = " << a + b << endl;
}

class functor {
public:
	void operator()() const {
		cout << "Called functor" << endl;
	}
};
int main() {
	vector<function<void()>> funcs;
	funcs.push_back(demoFuntion);
	functor functor_instance;
	funcs.push_back(functor_instance);
	funcs.push_back([]() { cout << "Called anonymous lambda " << endl; });
	funcs.push_back(std::bind(&adder, 10, 15));
	for (auto& f : funcs) {
		f();
	}
	return 0;
}