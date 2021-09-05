
//program written by :  Balaram ,


// cpp program for henon method



#include <iostream>

//function defintion for henon method
double henon_method(double y, int k){

double x = y; //initial value

// lets say k iterations

for (int i = 1; i<=k; i++){
x = ( (1.0/2)*(x + y*1.0/x) );
}


return x;
}


int main()
{

std::cout<<"Henon Method : "<<"\n";

double n;
std::cout<<"Enter the number to find its square root value : "<<"\n";
std::cin>>n;
double a = henon_method(n,100000); // the iteration count value need to be optimized

std::cout<<"Square root of "<<n<<" is : "<< a<<"\n";


return 0;
}


