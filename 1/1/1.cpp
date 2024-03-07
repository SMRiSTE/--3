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
		adr[i].inp_adr(city ,street, home, flat);
		File << adr[i].adr() << std::endl;
	}

	delete[] adr;

	File.close();
	file.close();
}