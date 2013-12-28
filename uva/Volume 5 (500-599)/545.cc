// 545

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <stack>
#include <sstream>
#include <cctype>
#include <cmath>
#include <numeric>
#include <list>
#include <set>
#include <map>
#include <queue>
using namespace std;
#define EPS 1e-9

int main () {
        //fstream f;
        //f.open("c:\\Users\\mikhail.solomatin\\Documents\\Visual Studio 2010\\Projects\\test\\Debug\\inp.txt");       

        int n;
       
        double result = 1.0;
        int power = 1;
        const int N = 9001;
        vector<pair<double, int> > dvec(N);
       
        for (int i = 1; i <= N - 1; i++) {
                result *= 5.0;
    	
                if (floor(result) > 9) {
                        result /= 10;
                }
		power = log10(result) + (double)i * log10((double)2);
                dvec[i] = make_pair(result, power);               
        }
       
        int cases;
        cin >> cases;

        for (int i = 0; i < cases; i++) {
                cin >> n;
                cout << "2^-" << n << " = " << fixed << setprecision(3) << dvec[n].first + EPS
                        << "E-" << dvec[n].second << endl;
        }
       
        //f.close();
	return 0;
}