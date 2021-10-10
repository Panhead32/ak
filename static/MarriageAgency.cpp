#include "Customer.h"

#include "FileDB.h"

#include <iostream>

#include <string>

#include <list>



using namespace std;



void empty_enter() {

	cout << "Press enter to continue..." << endl;

	string s;

	getline(cin, s);

};

void print_menu();

void menu(FileDB file_db);

Customer get_customer();

void print_exect(FileDB file_db);



int iter;



int main()

{

	FileDB file_db = FileDB("file.txt");



	iter = 0;

	iter += file_db.get_customers().size();


	menu(file_db);

	cout << file_db.get_customer_by_code(1).get_customer_db_data();

}



void menu(FileDB file_db)

{

	bool flag = true;

	do

	{

		if (flag)

			print_menu();



		flag = false;

		string a = "";



		getline(cin, a);



		if (a == "/add") {

			file_db.add_customer(get_customer());

			flag = true;

			empty_enter();

		}

		else if (a == "/all") {

			system("clear");
			
			for (auto c : file_db.get_customers())
			{
				c.print_pib();
			}

			flag = true;

			empty_enter();
		}

		else if (a == "/exact") {

			print_exect(file_db);

			empty_enter();

			flag = true;

		}

		else if (a == "/quit") {

			break;

		}

		else {

			cout << "You have written incorrect command";

			flag = false;

		}

	} while (true);

}



void print_menu()

{

	system("clear");

	cout << "/add - add customer" << endl;

	cout << "/all - watch all customers" << endl;

	cout << endl;

	cout << "/quit - exit the app" << endl;

	cout << ">> ";

}



Customer get_customer()

{
	try
	{
		
	system("clear");

	int sex_t;



	string t;



	string pib_;

	Sex sex_;

	int age_;

	double height_;

	double weight_;

	string bad_habits_;

	string hobby_;

	string address_;

	string phone_;

	string birth_day_;

	string passport_data_;

	int customer_code_;

	string partner_info_;



	cout << "Surname Name Father's name (in one line): " << endl;

	getline(cin, pib_);

	cout << "sex (0 - male, 1 - female): " << endl;

	cin >> sex_t;

	cout << "age: " << endl;

	cin >> age_;

	cout << "height (meters): " << endl;

	cin >> height_;

	cout << "weight (kylograms): " << endl;

	cin >> weight_;

	cout << "bad habits (in one line): " << endl;

	getline(cin, t); // next line
	getline(cin, bad_habits_);

	cout << "hobby (in one line): " << endl;

	getline(cin, hobby_);
		
	cout << "address (in one line): " << endl;

	getline(cin, address_);

	cout << "phone number (in one line): " << endl;

	getline(cin, phone_);

	cout << "birthday (in one line): " << endl;

	getline(cin, birth_day_);

	cout << "passport data (in one line): " << endl;

	getline(cin, passport_data_);

	cout << "partner information (in one line): " << endl;

	getline(cin, partner_info_);



	customer_code_ = ++iter;



	if (sex_t == 1)

		sex_ = Male;

	else

		sex_ = Female;



	return	Customer(customer_code_,

		pib_, sex_, birth_day_, age_, height_,

		weight_, bad_habits_, hobby_, address_,

		phone_, passport_data_, partner_info_);
	}
	catch (const char* exception)

	{
		cout << "Wrong data, try one more time" << endl;
		empty_enter();
		return get_customer();
	}

}



void print_exect(FileDB file_db)

{

	system("clear");





	try

	{

		cout << "Print customer code: ";

		int a;

		cin >> a;

		Customer c = file_db.get_customer_by_code(a);

		c.print_pib();

		c.print_public_info();

		c.print_private_info();

		c.print_other_info();

	}

	catch (const char* exception)

	{

		cout << "Not found" << endl;

	}

}




