#include "class.h"
using namespace std;

void Person::setname(string const& name){
    d_name = name;
}

void Person::setaddress(string const& address){
    d_address = address;
}

bool Person::hasOnly(char const*characters,string const &objects){
    return objects.find_first_not_of(characters)== string::npos;
}
//is this a constructor
void Person::setphone(string const&phone){
    if(phone.empty()){
        d_phone = "---not available---";
    }else if(hasOnly("1234567890",phone)){
        d_phone = phone; 
    }else{
        cout<<"phone number may only contain digits"<<endl;
    }
}
//then what is this???
void Person::setmass(size_t mass){
    d_mass = mass;
}

string const &Person::name() const{
    return d_name;
}

string const &Person::address() const{
    return d_address;
}

string const &Person::phone() const{
    return d_phone;
}

size_t Person::mass() const{
    return d_mass;
}

void printperson(Person const &p){
    cout<<"NAME:"<<p.name()<<endl;
    cout<<"ADDRESS:"<<p.address()<<endl;
    cout<<"PHONE:"<<p.phone()<<endl;
    cout<<"MASS:"<<p.mass()<<endl;
}


