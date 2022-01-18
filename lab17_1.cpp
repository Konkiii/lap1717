#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

void showData(double *,int,int);

void randData(double *,int,int);

void findRowSum(const double *,double *,int,int);

void findColSum(const double *,double *,int,int);

int main(){
	srand(time(0));
	const int N = 6, M = 8;
	double data[N][M] = {};
	double sum1[N] = {};
	double sum2[M] = {};
	double *dPtr = data[0];
	randData(dPtr,N,M);
	showData(dPtr,N,M);
	
	cout << "---------------------------------------------\n";
	
	findRowSum(dPtr,sum1,N,M);
	showData(sum1,N,1);
	
	cout << "---------------------------------------------\n";
	
	findColSum(dPtr,sum2,N,M); 
	showData(sum2,1,M);
}

void showData(double *x,int y,int z){
    cout << fixed << setprecision(2);
    for(int i = 0; i < y*z; i++){
        cout << x[i];
        if((i + 1) %z == 0) cout << endl;
        else cout << " ";
    }
}

void randData(double *x,int y,int z){
    for(int i = 0; i < y*z; i++){
        x[i] = rand() % 101 / 100.0;
    }
}

void findRowSum(const double *w,double *x,int y,int z){
	for(int i = 0;i < y;i++){
		double j = 0;
		for(int k = 0;k < z;k++){
			j += *((w + k) + (z * i));
		}
		x[i] = j;
	}
}

void findColSum(const double *w,double *x,int y,int z){
	int i = 0,j = 0;
	x[j] = 0;
	for(int a = 0;a < z;a++){
		i = a;
		for(int b = 0;b < y;b++){
			x[j] += w[i];
			i += z;
		}
		j++;
		x[j] = 0;
	}
}