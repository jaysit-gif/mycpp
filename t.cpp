#include <iostream>
#include "class.h"

int main(){
    Person p;
    p.setname("LINUS TORVALDS");
    p.setmass(65);
    p.setphone("");
    p.setaddress("FINLAND");
    printperson(p);
    return 0;
}
