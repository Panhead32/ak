#include <fstream>
#include <list>

#include "Customer.h"
#include "FileDB.h"

using namespace std;

FileDB::FileDB(string path)
    :path_(move(path))
{

}

Customer FileDB::get_customer_by_code(int code)
{
    for(auto c : get_customers())
    {
        if(c.get_code() == code)
            return c;
    }

    return Customer();
}
list<Customer> FileDB::get_customers()
{
    ifstream fin(path_, ios_base::in);

    list<Customer> results;

    while(!fin.eof())
    {
        string sex_t;

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
	
        getline(fin, pib_);
        getline(fin, sex_t);
        fin >> age_;
        fin >> height_;
        fin >> weight_;
        getline(fin, t); // next line
        getline(fin, bad_habits_);
        getline(fin, hobby_);
        getline(fin, address_);
        getline(fin, phone_);
        getline(fin, birth_day_);
        getline(fin, passport_data_);
        fin >> customer_code_;
        getline(fin, t); // next line
        getline(fin, partner_info_);

        if(sex_t == "male")
            sex_ = Male;
        else 
            sex_ = Female;

        results.push_back(
            Customer(customer_code_, 
                    pib_, sex_, birth_day_, age_, height_, 
                    weight_, bad_habits_, hobby_, address_, 
                    phone_, passport_data_, partner_info_)
        );
    }

    results.pop_back();

    fin.close();

    return results;
}

void FileDB::add_customer(Customer c)
{
    ofstream fout(path_, ios_base::app);

    fout << c.get_customer_db_data();

    fout.close();
}
