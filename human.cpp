#include <iostream>
#include <string.h>
#include <locale.h>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <ctime>

using namespace std;

class GCS {
	protected:
		double step;
		double speed;
	public:
		double longtitude;
		double latitude;
		double path;
		double way;
		vector<double> miliage;
		GCS (double longt, double latit) {
			longtitude = longt;
			latitude = latit;
			way = 0;
			path = 0;
		}
		
		void set_gcs (double longt, double latit) {
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
			cout << endl << "Долгота: " << get_longtitude() << endl << "Широта: " << get_latitude() << endl;
		}

		void rand_walk() {
			speed = (rand()%5 + 1);
			int quarter_1 = rand() % 4 + 1;
			int quarter_2 = rand() % 4 + 1;
			double past_long = longtitude;
			double past_lat = latitude;
			latitude = latitude + pow(-1, quarter_1)*(0.009*speed*step);
			longtitude = longtitude + pow(-1, quarter_2)*(0.009*speed*step);
			printf("%lf\t%lf\t%lf\t%lf\n", longtitude, latitude, step, speed);
			walk_mileage(past_long, past_lat);
		}

		void walk_mileage(double lon1, double lat1) {
			path += 111.2*sqrt((abs(lon1 - longtitude))*(abs(lon1 - longtitude)) + (abs(lat1 - latitude))*cos(3.14*lon1/180)*(abs(lat1 - latitude))*cos(3.14*lon1/180));
			way += path;
			miliage.push_back(path);
		}
		
		double get_way() {
			return way;
		}
};

class HUMAN : public GCS {
	private:
		string first_name;
		string second_name;
		string middle_name;
		double weight;
		double height;
        int life_time;
	public:	
		HUMAN(string fn, string sn, string mn, double w, double h, double longt, double latit, int life) : GCS (longt, latit) {
			first_name = fn;
			second_name = sn;
			middle_name = mn;
			weight = w;
			height = h;
            life_time = life;
			step = h/4 + 0.00037;
		}

		void set_name(string fn, string sn, string mn) {
			first_name = fn;
			second_name = sn;
			middle_name = mn;
		}
		
		void set_parameters(double w, double h) {
			weight = w;
			height = h;
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
			cout << "ФИО: " << get_sn() << " " << get_fn() << " " << get_mn();
		}
		
		double get_weight() {
			return weight;
		}
		
		double get_step() {
			return step;
		}
		
		double get_height() {
			return height;
		}
		
		void get_parameters() {
			cout << endl << "Вес: " << get_weight() << endl;
			cout << "Рост: " << get_height() << endl;
		}
		
		double get_speed() {
            return speed;
        }
		
        int get_life() {
            return life_time;
        }
		
		void walking() {
			for (int i=0; i<life_time;i++) {
				rand_walk();
			}
		}
};

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "RUS");
	double w, h;
	HUMAN *human_1 = new HUMAN("Петр", "Петров", "Петрович", 79, 0.00186, 55, 82.9, 5);
	human_1->walking();
	printf("%lf\n", human_1->get_way());
	cout << endl;
}
