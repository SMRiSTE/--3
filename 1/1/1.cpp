#include <iostream>
#include <fstream>
#include <string>
std::ifstream file("in.txt");
std::ofstream File("out.txt");

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
			
			std::string str = this->city + ", " + this->street + ", " + std::to_string(this->home) + ", " + std::to_string(this->flat);
			File << str << std::endl;
			return str;
		}

};

int main() {
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
		adr[i].adr();
	}

	delete[] adr;

	File.close();
	file.close();
}