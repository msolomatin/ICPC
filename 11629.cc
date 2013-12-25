
// 11629

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

int convert(string s) {
        int r = 0;
        for (int i = 0; i < s.length(); i++) {
                if (s[i] == '.') {
                        r = r * 10 + (s[i + 1] - '0');
                        break;
                }
                else {
                        r = r * 10 + (s[i] - '0');
                }
        }
        return r;
}

bool isComparison(string s) {
        bool result = false;
        if (s == ">" || s == "<" || s == ">=" || s == "<=" || s == "=") {
                result = true;
        }
        return result;
}

int main()
{
        //ifstream fin("input.txt");

        int p, g;
        cin >> p >> g;
        map<string, int> m;
        string party, percentage;
        for (int i = 0; i < p; i++) {
                cin >> party >> percentage;
                m[party] = convert(percentage);                
        }
        int sum = 0, total;
        string s, result;
        for (int i = 0; i < g; i++) {
                sum = 0;
                cin >> s;
                while (!isComparison(s)) {
                        //cout << s << endl;
                        if (s != "+") {
                                sum += m[s];
                        }
                        cin >> s;
                }
                if (isComparison(s)) {
                        cin >> percentage;
                        //cout << percentage << endl;
                        total = 10 * convert(percentage);
                }
                if (s == ">") {
                        result = sum > total ? "correct." : "incorrect.";
                }
                else if (s == "<") {
                        result = sum < total ? "correct." : "incorrect.";        
                }
                else if (s == ">=") {
                        result = sum >= total ? "correct." : "incorrect.";
                }
                else if (s == "<=") {
                        result = sum <= total ? "correct." : "incorrect.";
                }
                else if (s == "=") {
                        result = sum == total ? "correct." : "incorrect.";
                }
                //cout << sum << " --- " << total << endl;
                cout << "Guess #" << i + 1 << " was " + result << endl;
        }

        //fin.close();
        return 0;
}
