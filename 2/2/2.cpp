#include <iostream>
#include <fstream>
#include <string>

class Adres {
	private:
		std::string city;
		std::string street;
		int home;
		int flat;
	public:

		void new_city(std::string City) {
			this->city = City;
		}

		std::string get_city() {
			return city;
		}

		void inp_adr(std::string city, std::string street, int home, int flat) {
			this->city = city;
			this->street = street;
			this->home = home;
			this->flat = flat;

		}

		std::string adr() {

			return city + ", " + street + ", " + std::to_string(home) + ", " + std::to_string(flat);
		}

		
};

void sort(Adres* adr, int num) {
	for (int j = 0; j < num; j++) {
		for (int i = 0; i < num-1; i++) {
			if (adr[i + 1].get_city() < adr[i].get_city()) {
				std::string str;
				str = adr[i].get_city();
				adr[i].new_city(adr[i + 1].get_city());
				adr[i+1].new_city(str);

			}
			else {
				continue;
			}
		}
	}
	
}

int main() {

	std::ifstream file("in.txt");
	std::ofstream File("out.txt");

	setlocale(LC_ALL, "Russian");
	int num;
	file >> num;
	File << num << std::endl;
	Adres adres;
	Adres* adr = new Adres[num];

	std::string city;
	std::string street;
	int home;
	int flat;

	for (int i = 0; i < num; i++) {
		file >> city;
		file >> street;
		file >> home;
		file >> flat;
		adr[i].inp_adr(city, street, home, flat);

	}

	sort(adr, num);
	
	for (int i = 0; i < num; i++) {
		
		File << adr[i].adr() << std::endl;

	}

	delete[] adr;
}