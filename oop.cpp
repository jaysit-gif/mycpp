#include <iostream>
struct vector{
    int i,j,k; 
    vector(int i_init = 0,int j_init = 0,int k_init = 0):i(i_init),j(j_init),k(k_init){}//**what happens if i fill "{}" */
};

vector operator+(const vector &a,const vector &b){ 
    vector c;
    c.i = a.i+b.i;c.j=a.j+b.j;c.k = a.k+ b.k;  
    return c;
}

std::ostream& operator<<(std::ostream& os, const vector& v) { 
    os << "(" << v.i << ", " << v.j << ", " << v.k << ")";
    return os;
}

int operator*(const vector &a,const vector &b){ /**dot product */
    int c;
    c = a.i*b.i + a.j*b.j + a.k*b.k;
    return c;
}

int main(void){
    vector a(5,4,3),b(2,3,5);
    vector c = a + b; 
    int dotproduct = a*b;
    std::cout<<c<<std::endl;
    std::cout<<dotproduct<<std::endl;
}