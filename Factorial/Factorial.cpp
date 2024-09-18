#include <iostream>
using namespace std;

unsigned long long factorial(int n){
    if(n == 0){
        return 1;
    }
    
        return factorial ((n-1))* n;

};



int main(){
    cout << factorial(0);
return 0;
}