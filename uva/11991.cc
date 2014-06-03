// 11991
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stack>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <set>
#include <string>
#include <map>
using namespace std;

int main() {
	const int maxInt = 1000000;
	vector<vector<int> > ivec;

	int n, m, k, v, ival, counter, result;
	//fstream fin("absum.in");
	while (cin >> n >> m) {
		ivec.clear();
		ivec.resize(maxInt + 1);
		for (int i = 0; i < n; i++) {
			cin >> ival;
			ivec[ival].push_back(i + 1);
		}
		for (int i = 0; i < m; i++) {
			cin >> k >> v;

			result = (ivec[v].size() < k) ? 0 : ivec[v][k - 1];
			cout << result << endl;
		}
	}
	//fin.close();
	return 0;
}
