
// 11850

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

        vector<int>stations;
        int n, coordinate, fuelRemaining;

        while (cin >> n) {
                if (n == 0) {
                        break;
                }
                stations.clear();
                stations.resize(n);
                for (int i = 0; i < n; i++) {
                        cin >> coordinate;
                        stations[i] = coordinate;
                }
                sort(stations.begin(), stations.end());
                fuelRemaining = 200;
                bool flag = true;
                for (int i = 0; i < n - 1; i++) {
                        if (stations[i + 1] - stations[i] > fuelRemaining) {
                                flag = false;
                        }
                }
                if (2 * (1422 - stations[n - 1]) > fuelRemaining) {
                        flag = false;
                }
                string result = flag ? "POSSIBLE" : "IMPOSSIBLE";
                cout << result << endl;
        }

        //fin.close();
        return 0;
}