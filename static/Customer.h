#pragma once
#include <iostream>
#include <string>
#include <set>

using namespace std;

enum BadHabits
{
	Alcohol,
	Smoking,
};

enum Sex
{
	Male,
	Female,
};

class Customer 
{
public:
	Customer();
	Customer(int customerCode, string pib, Sex sex, string birthDay, unsigned age, double height, double weight,
		string badHabits, string hobby,
		string address, string phone, string passportData,
		string partnerInfo);

	~Customer();
	void print_pib();
	void print_public_info();
	void print_private_info();
	void print_other_info();

	int get_code();
	string get_customer_db_data();


private:
	string pib_;
	Sex sex_;
	unsigned age_;
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

	void print_appearance();
	void print_leisure();
	void print_contact_info();
	void print_passport_info();

	string get_sex();
};

