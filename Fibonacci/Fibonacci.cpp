
#include <iostream>
#include <chrono>
#include <vector> 

using namespace std;
using namespace std::chrono;


/*unsigned long long fibonacci(int n, vector<unsigned long long>& memo){
     if(n == 0 || n == 1){
         return 1;
     }
    if(memo[n]!=0){
        return memo[n];
    }
    memo[n] = fibonacci(n-1, memo) + fibonacci(n-2, memo);

    return memo[n];
    

}; 

*/



 unsigned long long fibonacciOpt(int n, unsigned long long tabla[]){
    if(tabla[n]== 0){
        tabla[n] = fibonacciOpt(n -2, tabla) + fibonacciOpt(n-1, tabla), tabla;
    }
    else{
        return 1;
    }
    return tabla[n];
 };

unsigned long long fibonacciOpt(int n){ // tabla de 0
     unsigned long long tabla[n+1];
    for(int i =0; i<=n; i++){
        tabla[i] =0; 
    }
    tabla[0] = tabla[1] = 1;
    fibonacciOpt(n, tabla);
};

int main(){
    auto begin = high_resolution_clock::now();
     int n = 60;
     cout  << fibonacciOpt(n);
    //vector<unsigned long long> memo(n + 1, 0);;
    // cout << fibonacci(n, memo);
    auto end = high_resolution_clock::now();
    auto duracion = end-begin;
    auto ms = duration_cast<milliseconds>(duracion).count();

    cout << "Tardo " << ms << "ms";
    return 0;
}