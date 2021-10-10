#include <list>

#include "Customer.h"

using namespace std;

class FileDB
{
   
public:
    FileDB(string path);

    Customer get_customer_by_code(int code);
    list<Customer> get_customers();

    void add_customer(Customer c);

private:
    string path_;
};