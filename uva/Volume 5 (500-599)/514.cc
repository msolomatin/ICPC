// 514

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

        int N, ival, index;
        vector<int>p;
        string result, line;
        bool first = true;
        while (cin >> N) {
                if (N == 0) {
                        break;
                }
                if (!first) {
                        cout << endl;
                }
                first = false;
                while (getline(cin, line)) {
                        if (line == "") {
                                continue;
                        }
                        stringstream ss(line);
                        ss >> ival;
                        p.clear();

            stack<int>s;

            index = 1;
            result = "Yes";
            if (ival == 0) {
                break;
            }
            else {
                p.push_back(ival);
                for (int i = 1; i < N; i++) {
                        ss >> ival;
                    p.push_back(ival);
                }
                for (int i = 0; i < N; i++) {
                        if (!s.empty() && (s.top() == p[i])) {
                                s.pop();
                        }
                        else if (index <= p[i]) {
                                int j;
                                for (j = index; j <= p[i]; j++) {
                                        s.push(j);
                                }
                                index = j;
                                s.pop();
                        }
                        else if (!s.empty() && (s.top() != p[i] && index >= N)) {
                                result = "No";
                        }
                }
                if (!s.empty() && index >= N) {
                        result = "No";
                }
                cout << result << endl;
            }
                }

        }
        cout << endl;
        //fin.close();
        return 0;
}
