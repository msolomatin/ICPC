
// 575

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

		string s;
		int result;
		while (cin >> s) {
				if (s == "0") {
						break;
				}
				result = 0;
				for (int i = 0; i < (int)s.length(); i++) {
						result += (s[i] - '0') * (pow(2, s.length() - i) - 1);
				}
				cout << result << endl;
		}

		//fin.close();
        return 0;
}