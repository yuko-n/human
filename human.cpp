#include <iostream>
#include <string.h>
#include <locale.h>
#include <cstdlib>

using namespace std;

class WALK {
	public:
	int speed;
	WALK() {
		speed = rand()%5 + 1;
	}
	//set_speed()
	int get_speed() {
		return speed;
	}
};

class GCS : public WALK {
	public:
	double longtitude;
	double latitude;
	GCS(double longt, double latit) : WALK() {
		if (longt >= 0 && longt <= 180) longtitude = longt;
		else {
			cout << "ОШИБКА: Неверно задана долгота" << endl;
			longtitude = -1;
		}
		if (latit >= 0 && latit <= 90) latitude = latit;
		else {
			cout << "ОШИБКА: Неверно задана широта" << endl;
			latitude = -1;
		}
	}
	
	void set_gcs(double longt, double latit) {
		longtitude = longt;
		latitude = latit;
	}
	
	double get_longtitude() {
		return longtitude;
	}
	
	double get_latitude() {
		return latitude;
	}
	
	void get_gcs() {
		cout << "\nДолгота: " << get_longtitude() << endl;
		cout << "Широта: " << get_latitude() << endl;
	}
};

class HUMAN : public GCS {
	private:
		string first_name;
		string second_name;
		string middle_name;
		double weight;
		double height;
		int speed;

	public:	
		HUMAN(string fn, string sn, string mn, double w, double h, double longt, double latit) : GCS(longt, latit){
			first_name = fn;
			second_name = sn;
			middle_name = mn;
			weight = w;
			height = h;
			speed = get_speed();
		}
		
		string get_fn() {
			return first_name;
		}
		
		string get_sn() {
			return second_name;
		}
		
		string get_mn() {
			return middle_name;
		}
		
		void get_name() {
			cout << "ФИО: " << get_sn();
			cout << " " << get_fn();
			cout << " " << get_mn();
		}
		
		void set_name(string fn, string sn, string mn){
			first_name = fn;
			second_name = sn;
			middle_name = mn;
		}
		
		double get_weight() {
			return weight;
		}
		
		double get_height() {
			return height;
		}
		
		void get_parameters() {
			cout << "\nВес: " << get_weight() << endl;
			cout << "Рост: " << get_height() << endl;
		}
		
		void set_parameters(double w, double h) {
			weight = w;
			height = h;
		}
};

int main() {
	double w, h;
	HUMAN *human_1 = new HUMAN("Ярослав", "Обухович", "Евгеньевич", 79, 186, 55, 82.9);
	human_1->get_name();	
	human_1->get_parameters();
	human_1->get_gcs();
	cout << "Скорость движения: " << human_1->get_speed() << " км/ч"<< endl;
	cout << endl;

}