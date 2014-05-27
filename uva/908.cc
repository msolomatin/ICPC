// 908
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
	int N, K, M;
	int from, to, cost, prevCost;
	int no = 0;

	while (cin >> N) {
		G.clear();
		G.resize(N);
		prevCost = 0;
		for (int i = 0; i < N - 1; i++) {
			cin >> from >> to >> cost;
			prevCost += cost;
		}
		if (no > 0) {
			cout << endl;
		}
		cout << prevCost << endl;

		cin >> K;
		for (int i = 0; i < K; i++) {
			cin >> from >> to >> cost;
			from -= 1;
			to -= 1;
			G[from].push_back(make_pair(to, cost));
			G[to].push_back(make_pair(from, cost));
		}

		cin >> M;
		for (int i = 0; i < M; i++) {
			cin >> from >> to >> cost;
			from -= 1;
			to -= 1;
			G[from].push_back(make_pair(to, cost));
			G[to].push_back(make_pair(from, cost));
		}
		cout << Prim(0, N) << endl;
		no += 1;
	}

	//fin.close();
	return 0;
}
