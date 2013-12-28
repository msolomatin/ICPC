// 558

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

		vector<int> dist;
		vector<vector<int> > vertex;
		vector<int>values(3);

		int cases, n, m;
		const int INF = 2000000000;
		cin >> cases;
		for (int i = 0; i < cases; i++) {
				cin >> n >> m;
				vertex.clear();
				dist.clear();
				dist.resize(m + 1);

				fill(dist.begin(), dist.end(), INF);
				dist[0] = 0;


				for (int j = 0; j < m; j++) {
						cin >> values[0] >> values[1] >> values[2];
						vertex.push_back(values);
				}

				// Ford-Bellman algorithm
				for (int v = 0; v < n; v++) {
						for (int k = 0; k < (int)vertex.size(); k++) {
								dist[vertex[k][1]] =
										min(dist[vertex[k][1]], dist[vertex[k][0]] +
												vertex[k][2]);
						}
				}

				bool negativeCycle = false;

				// Find negative cycle
				for (int v = 0; v < m; v++) {
						if (dist[vertex[v][1]] > dist[vertex[v][0]] +
								vertex[v][2]) {
								negativeCycle = true;
								break;
						}
				}

				if (negativeCycle) {
						cout << "possible" << endl;
				}
				else {
					cout << "not possible" << endl;
				}
		}

		//fin.close();
        return 0;
}