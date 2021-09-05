

// program written by : Balaram ,


// cpp program to solve system of linear equations
// using gauss elimination method



#include <iostream>


// print matrix function
void print_matrix(int n, double *Ab ){
for(int i1 = 0; i1<n; i1++){
std::cout<<"i1 = "<<i1<<"\n";
for(int j1 = 0; j1<(n+1); j1++){

std::cout<<"j1 = "<<j1<<"\n";
std::cout<<( *((Ab+i1*n)+j1) )<<"\n";
}
std::cout<<std::endl;
}

}


// function to fill nxn matrix
void fill_matrix_sset(int n, double *Ab , double sset[]){

std::cout<<"Enter the elements of matrix nxn : "<<"\n";
for(int i = 0; i<n; i++){

std::cout<<"i = "<<i<<"\n";
// initialize the soloution set to zeros
sset[i] = 0;
for(int j = 0; j<(n+1); j++){

std::cout<<"j = "<<j<<"\n";
std::cin>>( *((Ab+i*n)+j) ) ;
//std::cout<<( *((Ab+i*n)+j) );
}

std::cout<<std::endl;
}


}




//gauss_elimination_function

void gauss_elimination(int n, double *Ab  , double sset[] ){

double aji,  Abii;
for(int i = 0; i<n; i++){
Abii = ( *((Ab+i*n)+i) );
for(int j = i+1; j<n; j++){
aji = -( *((Ab+j*n)+i) )*(1.0)/Abii;
for(int k =0; k<(n+1); k++){
( *((Ab+j*n)+k) ) +=  (aji*( *((Ab+i*n)+k) ) );
}
}
}


// back_substitution_method

double sum= 0;
for(int i = n-1; i>=0; i--){
sum = 0;

for(int k = i+1; k<n;k++){
sum += ( *((Ab+i*n)+k) ) * (sset[k]);
}

sset[i] = ( ( *((Ab+i*n)+n) ) - sum )*(1.0)/( *((Ab+i*n)+i) ) ;

}



}




int main(){

int n = 2;
std::cout<<"\nEnter the n value (No of unknowns) : ";
std::cin>>n;
int  n1 = n+1;
double Ab[n][n1] ;
double solution_set[n]; //

fill_matrix_sset(n, (double *)Ab, solution_set);

print_matrix( n, (double *)Ab);
//gauss_elimination(n, (double *)Ab,solution_set);

std::cout<<"\n";
for(int k = 0; k<n; k++){
std::cout<<solution_set[k]<<" ";
}
std::cout<<"\n";

return 0;
}
