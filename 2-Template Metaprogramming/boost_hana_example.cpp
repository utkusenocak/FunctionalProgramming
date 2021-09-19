#include <iostream>
#include <string>
#include <boost/hana.hpp>
namespace hana = boost::hana;
using namespace hana::literals;
using namespace std;

struct Truck {
	std::string name;
	double bed_length;
};

struct Car {
	std::string name;
};

struct Motorcycle {
	std::string name;
};

int main() {

	auto veichles = hana::make_tuple(
		Truck{"F-150", 8.5}, Car{"Volt"}, Motorcycle{"Ninja"}
	);
	auto has_bed_length = hana::is_valid(
		[](auto &&x) -> decltype((void) x.bed_length){}
	);
	auto trucks = hana::filter(veichles, has_bed_length);
	auto nontrucks = hana::filter(veichles, hana::compose(hana::not_, has_bed_length));

	hana::for_each(trucks, [](auto& viechle) {
		cout << "Truck = " << viechle.name << ", bed_length = " << viechle.bed_length << endl;
	});

	hana::for_each(nontrucks, [](auto& viechle) {
		cout << "Viechle = " << viechle.name << endl;
	});
	return 0;
}