#include <iostream>
using namespace std;

auto addCury = [](auto a) {
	return [a](auto b) {
		return [a, b](auto c) {
			return a + b + c;
		};
	};
};

int main() {
	auto added1 = addCury(1);
	auto added2 = added1(10);
	auto addResults = added2(100);
	cout << "results: " << addResults << endl;
	auto allAtOnce = addCury(990000)(9900)(99);
	cout << "All results: " << allAtOnce << endl;
	return 0;
}