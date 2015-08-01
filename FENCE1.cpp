#define _USE_MATH_DEFINES
#include <cmath> 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
main() {
    while (1) {
    double area;
    int n;
    cin >> n;
    
    if (n == 0)
        return 0;
    
    area = (n*n)/(2.0*M_PI);
	   
    printf("%.2lf\n",area);
}
}
