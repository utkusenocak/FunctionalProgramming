#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int main() {
	auto render = [](auto collection) {
		for (const auto& val : collection) {
			cout << val << endl;
		}
	};
	vector<int> inCollection{ 1,2,3,4,5,6,7,8,9,10 };
	vector<int> outCollection;
	transform(inCollection.begin(), inCollection.end(), back_inserter(outCollection), [](const int& val) {return val * 3; });
	cout << "Transform" << endl;
	render(outCollection);

	vector<int> filteredCollections;
	copy_if(outCollection.begin(), outCollection.end(), back_inserter(filteredCollections), [](int& val) {return val % 2 != 0; });
	cout << "copy_if" << endl;
	render(filteredCollections);

	int results = accumulate(filteredCollections.begin(), filteredCollections.end(), 0, [](int total, int current) { return total + current; });
	cout << "accumulate" << endl;
	cout << "results = " << results << endl;
	return 0;
}