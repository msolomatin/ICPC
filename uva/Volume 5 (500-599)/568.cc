// 568

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

int main()
{
    	//ifstream fin("input.txt");

		vector<int>tmp (10001);
		tmp[0] = 1;
		tmp[1] = 1;
		int fact = 1;

		for (int i = 2; i <= 10001; i++) {
				fact *= i;
				while (fact % 10 == 0) {
						fact /= 10;
				}
				fact %= 100000;
				tmp[i] = fact % 10;
		}
		int ival;
		while (cin >> ival) {
			cout << setw(5) << ival << " -> " << tmp[ival] << endl;
		}
		//fin.close();

        return 0;
}
