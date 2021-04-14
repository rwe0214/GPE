#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main(){
	double a;
	while(cin >> a){
		double strip, dot, grid;
		grid = a*a - (1.0/6.0)*a*a*M_PI - (pow(3, 0.5)/4)*a*a;
		dot = a*a - (0.25)*a*a*M_PI - 2*grid;
		strip = a*a - 4*grid - 4*dot;
		printf("%.3f %.3f %.3f\n", strip, 4*dot, 4*grid);
	}
	return 0;
}
