#include <string>
#include <fstream>
#include "Customer.h"

using namespace std;

Customer::Customer()
	: customer_code_(-1)
{
	
}

Customer::Customer(int customerCode, string pib, Sex sex, string birthDay, unsigned age, double height,
	double weight, string badHabits, string hobby,
	string address, string phone,
	string passportData, string partnerInfo) : pib_(std::move(pib)), sex_(sex), age_(age),
	height_(height), weight_(weight), bad_habits_(std::move(badHabits)), hobby_(std::move(hobby)),
	address_(std::move(address)), phone_(std::move(phone)), birth_day_(birthDay),
	passport_data_(std::move(passportData)), customer_code_(std::move(customerCode)), 
	partner_info_(std::move(partnerInfo))
{
}

Customer::~Customer()
{

}

void Customer::print_pib()
{
	cout << pib_ << endl;
}

void Customer::print_public_info()
{
	cout << "--------------Appearance--------------------" << endl;
	this->print_appearance();
	cout << "--------------Leisure-----------------------" << endl;
	this->print_leisure();
}

void Customer::print_private_info()
{
	cout << "--------------Contact Information-----------" << endl;
	this->print_contact_info();
	cout << "--------------Passport Information----------" << endl;
	this->print_passport_info();
}

void Customer::print_appearance()
{
	cout << "Sex: " << get_sex() << endl;
	cout << "Age: " << age_ << endl;
	cout << "Height: " << height_ << endl;
	cout << "Weight: " << weight_ << endl;
}

void Customer::print_leisure()
{
	cout << "Hobby: " << hobby_ << endl;

	cout << "Bad habits: " << bad_habits_ << endl;
}

void Customer::print_contact_info()
{
	cout << "Address: " << address_ << endl;
	cout << "Phone: " << phone_ << endl;
}

void Customer::print_passport_info()
{
	cout << "Birthday: " << birth_day_ << endl;
	cout << "Other passport info: " << passport_data_ << endl;
}

void Customer::print_other_info()
{
	cout << "Customer code: " << customer_code_ << endl;
	cout << "Partner information: " << partner_info_ << endl;
}

string Customer::get_sex()
{
	switch (this->sex_)
	{
	case Male: return "male";
	case Female: return "female";
	default: return "0_o";
	}
}

// string pib_;
// Sex sex_;
// unsigned age_;
// double height_;
// double weight_;
// string bad_habits_;
// string hobby_;

// string address_;
// string phone_;

// string birth_day_;
// string passport_data_;

// int customer_code_;
// string partner_info_;

int Customer::get_code()
{
	return customer_code_;
}

string Customer::get_customer_db_data()
{
	string result = "";

	result += pib_ + '\n';
	result += get_sex() + '\n';
	result += to_string(age_) + '\n';
	result += to_string(height_) + '\n';
	result += to_string(weight_) + '\n';
	result += bad_habits_ + '\n';
	result += hobby_ + '\n';
	result += address_ + '\n';
	result += phone_ + '\n';
	result += birth_day_ + '\n';
	result += passport_data_ + '\n';
	result += to_string(customer_code_) + '\n';
	result += partner_info_ + '\n';

	return result;
}