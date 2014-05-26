// 10034

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stack>
#include <cmath>
#include <iomanip>
#include <numeric>
using namespace std;

struct coord {
	double x;
	double y;
};

const int INF = 1000000000;
const int N = 101;
double G[N][N];

double dist(coord point1, coord point2) {
	return sqrt((point1.x - point2.x) * (point1.x - point2.x) +
			(point1.y - point2.y) * (point1.y - point2.y));
}

double Prim(int start, int n) {
	vector<double> length(n, INF);
	length[start] = 0;
	vector<bool> known(n, false);

	int vertexRemain = n;
	double minLength = INF;
	int minIndex;

	while (vertexRemain > 0) {
		minLength = INF;
		for (int i = 0; i < n; i++) {
			if (!known[i] && length[i] < minLength) {
				minLength = length[i];
				minIndex = i;
			}
		}

		known[minIndex] = true;

		for (int i = 0; i < n; i++) {
			if (!known[i]) {
				length[i] = min(G[minIndex][i], length[i]);
			}
		}

		vertexRemain -= 1;
	}

	return accumulate(length.begin(), length.end(), 0.0);
}

int main() {
    //fstream fin("absum.in");
    //ofstream fout("cycle2.out");

	int cases, n;
	vector<coord>coordinates;
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		cin >> n;
		coordinates.clear();
		coordinates.resize(n);
		for (int j = 0; j < n; j++) {
			cin >> coordinates[j].x >> coordinates[j].y;
		}
		// Adjacency matrix of distances
		for (int j = 0; j < n; j++) {
			for (int k = j; k < n; k++) {
				if (j == k) {
					G[j][k] = INF;
					G[k][j] = INF;
				}
				else {
					G[j][k] = dist(coordinates[j], coordinates[k]);
					G[k][j] = G[j][k];
				}
			}
		}
		double result = Prim(0, n);
		cout << fixed << setprecision(2) << result << endl;
		if (i != cases - 1) {
			cout << endl;
		}
	}

    //fout.close();
    //fin.close();
	return 0;
}
