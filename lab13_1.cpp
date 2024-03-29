#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[]){
    for(int i=0; i<N; i++){ //Arithmetic Mean
        B[0] += A[i];
    } 
    B[0] /= N;

    for(int i=0; i<N; i++){ //Standard Deviation
        B[1] += pow(A[i]-B[0],2);
        }
    B[1] = sqrt(B[1]/N);

    B[2] = 1;               //Geometric Mean
    for(int i=0; i<N; i++){
        B[2] *= A[i];
    }
    B[2] = pow(B[2],1.0/N);

    for(int i=0; i<N; i++){ //Harmonic Mean
        B[3] += 1/A[i];
    }
    B[3] = N/B[3];

    double max = A[0], min = A[0];  //Max, Min
    for(int i=0; i<N; i++){
        if(A[i]>max) max = A[i];
        if(A[i]<min) min = A[i];
    }
    B[4] = max;
    B[5] = min;

}
