#include <iostream>
#include <fstream>//to operate files
#include <sstream>//stringstream- for parsing line(string)
#include <string>//getline, string
using namespace std;

namespace POINT {
    class Point {
        double _x;
        double _y;
        double _z;
    public:
        Point() {
            _x = 0;
            _y = 0;
            _z = 0;
        }
        Point(double x) :Point() {
            _x = x;
        }
        Point(double x, double y) :Point(x) {
            _y = y;
        }
        Point(double x, double y, double z) :Point(x, y) {
            _z = z;
        }

        // setters
        void setX(double x) {
            _x = x;
        }
        void setY(double y) {
            _y = y;
        }
        void setZ(double z) {
            _z = z;
        }

        // getters    
        double getX() {
            return _x;
        }
        double getY() {
            return _y;
        }
        double getZ() {
            return _z;
        }

        // print
        void print() {
            cout << "Point: " << endl;
            cout << "X: " << _x << endl;
            cout << "Y: " << _y << endl;
            cout << "Z: " << _z << endl;
            cout << "----------------" << endl;
        }

        void save(ofstream& file) {
            file << _x << " " << _y << " " << _z << endl;
            file << "Point: " << endl;
            file << "X: " << _x << endl;
            file << "Y: " << _y << endl;
            file << "Z: " << _z << endl;
            file << "----------------" << endl;
        }
    };
}

namespace FRACTION {
	class Fraction
	{
	private:
		int num, den;

	public:
		Fraction() {
			num = 0;
			den = 1;
		}
		Fraction(int num) :Fraction() {
			this->num = num;
		}
		Fraction(int num, int den) {
			this->num = num;
			this->den = den;
		}

		//setters

		void setNum(int num) {
			this->num = num;
		}
		void setDen(int den) {
			this->den = den;
		}

		//getters
		int getNum() {
			return num;
		}
		int getDen() {
			return den;
		}

		//methods

		void print() {
			if (num > den) {//if the numerator is greater than the denominator
				int whole = num / den;
				num = num % den;
				cout << whole << " " << num << "/" << den << endl;
			}
			else {
				cout << num << "/" << den << endl;
			}
			cout << endl;
		}

		void print(int numerator, int denominator) {
			if (numerator > denominator) {//if the numerator is greater than the denominator
				int whole = numerator / denominator;
				numerator = numerator % denominator;
				cout << whole << " " << numerator << "/" << denominator << endl;
			}
			else {
				cout << num << "/" << den << endl;
			}
			cout << endl;
		}

		void print(Fraction f) {
			if (f.num > f.den) {//if the numerator is greater than the denominator
				int whole = f.num / f.den;
				f.num = f.num % f.den;
				cout << whole << " " << f.num << "/" << f.den << endl;
			}
			else {
				cout << f.num << "/" << f.den << endl;
			}
			cout << endl;
		}

		Fraction add(Fraction f) {
			Fraction result;
			result.num = num * f.den + f.num * den;
			result.den = den * f.den;
			return result;
		}

		void print_add(Fraction f) {
			Fraction result;
			result.num = num * f.den + f.num * den;
			result.den = den * f.den;
			cout << "Addition: ";
			cout << "(" << num << "/" << den << ") + (" << f.num << "/" << f.den << ") = ";
			print(result);
		}

		Fraction sub(Fraction f) {
			Fraction result;
			result.num = num * f.den - f.num * den;
			result.den = den * f.den;
			return result;
		}

		void print_sub(Fraction f) {
			Fraction result;
			result.num = num * f.den - f.num * den;
			result.den = den * f.den;
			cout << "Subtraction: ";
			cout << "(" << num << "/" << den << ") - (" << f.num << "/" << f.den << ") = ";
			print(result);
		}

		Fraction mul(Fraction f) {
			Fraction result;
			result.num = num * f.num;
			result.den = den * f.den;
			return result;
		}
		void print_mul(Fraction f) {
			Fraction result;
			result.num = num * f.num;
			result.den = den * f.den;
			cout << "Multiplication: ";
			cout << "(" << num << "/" << den << ") * (" << f.num << "/" << f.den << ") = ";
			print(result);
		}

		Fraction div(Fraction f) {
			Fraction result;
			result.num = num * f.den;
			result.den = den * f.num;
			return result;
		}
		void print_div(Fraction f) {
			Fraction result;
			result.num = num * f.den;
			result.den = den * f.num;
			cout << "Division: ";
			cout << "(" << num << "/" << den << ") / (" << f.num << "/" << f.den << ") = ";
			print(result);
		}


	};
}

namespace About_student {
    struct date {
    private:
        int _day;
        int _month;
        int _year;
    public:
        date() {
            _day = 1;
            _month = 1;
            _year = 2000;
        }
        date(int day, int month, int year) {
            this->_day = day;
            this->_month = month;
            this->_year = year;
        }
        void print() const {
            cout << _day << "." << _month << "." << _year << endl;
        }
        void set_day(int day) {
            _day = day;
        }
        void set_month(int month) {
            _month = month;
        }
        void set_year(int year) {
            _year = year;
        }
    };

    class Student {
    private:
        string _name;
        date _date_of_birth;
        long long _telephone;
        string _student_city;
        string _student_country;
        string _name_school;
        string _city_school;
        string _country_school;
        string _number_group;
    public:
        Student() {
            _name = "No name";
            _date_of_birth.set_day(1);
            _date_of_birth.set_month(1);
            _date_of_birth.set_year(2000);
            _telephone = 12345678;
            _student_city = "no city";
            _student_country = "no country";
            _name_school = "no name";
            _city_school = "no city";
            _country_school = "no country";
            _number_group = "AB:123";
        }
        Student(string name, date date_of_birth, long long telephone, string student_city, string student_country, string name_school, string city_school, string country_school, string number_group) {
            _name = name;
            _date_of_birth = date_of_birth;
            _telephone = telephone;
            _student_city = student_city;
            _student_country = student_country;
            _name_school = name_school;
            _city_school = city_school;
            _country_school = country_school;
            _number_group = number_group;
        }
        Student(string name, int day, int month, int year, long long telephone, string student_city, string student_country, string name_school, string city_school, string country_school, string number_group) {
            _name = name;

            _date_of_birth.set_day(day);
            _date_of_birth.set_month(month);
            _date_of_birth.set_year(year);

            _telephone = telephone;
            _student_city = student_city;
            _student_country = student_country;
            _name_school = name_school;
            _city_school = city_school;
            _country_school = country_school;
            _number_group = number_group;
        }

        // setters
        void set_name(string name) {
            _name = name;
        }
        void set_date_of_birth(date date_of_birth) {
            _date_of_birth = date_of_birth;
        }
        void set_date_of_birth(int day, int month, int year) {
            _date_of_birth.set_day(day);
            _date_of_birth.set_month(month);
            _date_of_birth.set_year(year);
        }
        void set_telephone(long long telephone) {
            _telephone = telephone;
        }
        void set_student_city(string student_city) {
            _student_city = student_city;
        }
        void set_student_country(string student_country) {
            _student_country = student_country;
        }
        void set_name_school(string name_school) {
            _name_school = name_school;
        }
        void set_city_school(string city_school) {
            _city_school = city_school;
        }
        void set_country_school(string country_school) {
            _country_school = country_school;
        }
        void set_number_group(string number_group) {
            _number_group = number_group;
        }

        // getters
        string get_name() const {
            return _name;
        }
        date get_date_of_birth() const {
            return _date_of_birth;
        }
        long long get_telephone() const {
            return _telephone;
        }
        string get_student_city() const {
            return _student_city;
        }
        string get_student_country() const {
            return _student_country;
        }
        string get_name_school() const {
            return _name_school;
        }
        string get_city_school() const {
            return _city_school;
        }
        string get_country_school() const {
            return _country_school;
        }
        string get_number_group() const {
            return _number_group;
        }

        void print() const {
            cout << "Name: " << _name << endl;
            cout << "Date of birth: ";
            _date_of_birth.print();
            cout << "Telephone: " << _telephone << endl;
            cout << "Student city: " << _student_city << endl;
            cout << "Student country: " << _student_country << endl;
            cout << "Name school: " << _name_school << endl;
            cout << "City school: " << _city_school << endl;
            cout << "Country school: " << _country_school << endl;
            cout << "Number group: " << _number_group << endl;
            cout << endl;
        }
    };
}

int main() {
    POINT::Point point1(1, 5);
    point1.print();
    point1.setZ(10);
    point1.print();

    
	FRACTION::Fraction f1(3, 4);
	FRACTION::Fraction f2(2, 3);
	f1.print();
	f2.print();

    About_student::date dob(1, 1, 2000);
    About_student::Student student1("Alex", dob, 3807812343, "City_1", "USA", "IT Step", "Vinnytsia", "Ukraine", "AC:123");
    student1.print();
    system("pause");
    return 0;
}