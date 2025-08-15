#include <iostream>
#include <string>
using namespace std;

class Person{
    private:
     string d_name;
     string d_address;
     string d_phone;
     size_t d_mass;

    public:
        void setname(string const&name);
        void setaddress(string const&address);
        void setphone(string const&phone);
        void setmass(size_t mass);
        bool hasOnly(char const*characters,string const &objects);
        

        string const &name() const;
        string const &address() const;
        string const &phone() const;
        size_t mass() const;
};

void printperson(Person const &p);