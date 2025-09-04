#include <iostream>
#include <vector>

struct maxmin{
    int max;
    int min;
};

int summation(std::vector<int> vectr);
maxmin max_and_min(std::vector<int> a);

int main(){
    std::vector<int> vec;
    int N = 0;
    int z;
    std::cout<<"N: ";
    std::cin>>N;
    for(int i = 0;i<N;i++){
        std::cout<<"element"<<' '<<i+1<<": ";
        std::cin>>z;
        vec.push_back(z);
    }

    maxmin b = max_and_min(vec);
    std::cout<<"SUM: "<<summation(vec)<<'\n';
    std::cout<<"MAX: "<<b.max<<'\n'<<"MIN: "<<b.min<<'\n';
    return 0;
}

maxmin max_and_min(std::vector<int> a){
    maxmin m;
    int max = a[0];int min = a[0];
    for(int i = 0;i<a.size();i++){
        if(max<a[i]){
            max = a[i];
        }
        if(min>a[i]){
            min = a[i];
        }
    }
    m.max = max;
    m.min = min;
    return m;
}

int summation(std::vector<int> vectr){
    int sum = 0;
    for(int i = 0;i<vectr.size();i++){
        sum += vectr[i];
    }
    return sum;
}