#include <iostream>
#include <ostream>
typedef struct vector{
    int i;
    int j;
    int k;
}vector;

vector operator+(const vector &a,const vector &b){ /**why are we using vector &a why not &vector a */
    vector c;
    c.i = a.i+b.i;c.j=a.j+b.j;c.k = a.k+ b.k;  /**what is const??*/
    return c;
}

std::ostream& operator<<(std::ostream& os, const vector& v) { /**what is ostream, what does ostream& os mean*/
    os << "(" << v.i << ", " << v.j << ", " << v.k << ")";
    return os;
}

int main(void){
    vector a,b;
    a.i = 6;
    a.j = 5;
    a.k =  3;
    b.i = 9;
    b.j = 4;
    b.k = 0;
    vector c = a + b; 
    std::cout<<c<<std::endl;
}