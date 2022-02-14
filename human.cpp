#include <iostream>
#include <string.h>
#include <locale.h>

using namespace std;

class HUMAN {
	private:
		string first_name;
		string second_name;
		string middle_name;
		double weight;
		double height;
		double s;

	public:	
		HUMAN(string fn, string sn, string mn, double w, double h) {
			first_name = fn;
			second_name = sn;
			middle_name = mn;
			weight = w;
			height = h;
			s = h/4 + 37;
		}
		
		double get_step(s, h) {
			s = h/4 + 37;
			cout << "Длина шага: " << s;
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
			cout << "Вес: " << get_weight() << endl;
			cout << "Рост: " << get_height() << endl;
		}
		
		void set_parameters(double w, double h, double s) {
			weight = w;
			height = h;
		}
};

int main() {
	double w, h;
	HUMAN *human_1 = new HUMAN("Ярослав", "Обухович", "Евгеньевич", 79, 186);
	human_1->get_name();
	cout << endl;
	human_1->get_parameters();
	cout << endl;
	human_1->get_step();
	cout << endl;
	cout << "Задайте новые параметры(вес, рост): ";
	cin >> w >> h;

	human_1->set_parameters(w, h);
	human_1->get_parameters();
	human_1->get_step();
	cout << endl;
	HUMAN *human_2 = new HUMAN("Алсу", "Ахматшина", "Фанисовна", 57, 156);
	human_2->get_name();
	cout << endl;
	human_2->get_parameters();
	
	human_2->get_step(get_parameters(), s);
}