// 11631
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stack>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <set>
using namespace std;

vector<vector<pair<int, int> > >G;

int Prim(int start, int n) {
	const int INF = 1000000000;
	set<pair<int, int> >q;
	vector<int> cost(n, INF);
	cost[0] = 0;
	vector<bool> known(n, false);

	q.insert(make_pair(0, 0));
	for (int i = 0; i < n; i++) {
		// Extract minimum weight/cost/length
		int v = q.begin()->second;
		q.erase(q.begin());
		known[v] = true;
		for (int j = 0; j < G[v].size(); j++) {
			int to = G[v][j].first;
			int len = G[v][j].second;
			if (!known[to] && len < cost[to]) {
				cost[to] = len;
				q.insert(make_pair(cost[to], to));
			}
		}
	}

	int sum = accumulate(cost.begin(), cost.end(), 0);
	return sum;
}

int main() {
	//fstream fin("absum.in");
	int m, n, from, to, len, totalLength;
	while (cin >> m >> n) {
		if (m == 0 && n == 0) {
			break;
		}
		G.clear();
		G.resize(m);
		totalLength = 0;
		for (int i = 0; i < n; i++) {
			cin >> from >> to >> len;
			G[from].push_back(make_pair(to, len));
			G[to].push_back(make_pair(from, len));
			totalLength += len;
		}
		cout << totalLength - Prim(0, m)  << endl;
	}
	//fin.close();
    return 0;
}
