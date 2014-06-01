// 534
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

struct coord
{
	double x;
	double y;
};

const int N = 200;

double lake[N + 5][N + 5];

double dist(coord point1, coord point2) {
	return sqrt((point1.x - point2.x) * (point1.x - point2.x) +
			(point1.y - point2.y) * (point1.y - point2.y));
}

int main () {
	int stones;
	vector<coord> coordinates;
	int scenario = 0;

	//fstream fin("absum.in");

	while (cin >> stones) {
		if (stones == 0) {
			break;
		}
		coordinates.clear();
		coordinates.resize(stones);
		scenario += 1;
		for (int i = 0; i < stones; i++) {
			cin >> coordinates[i].x >> coordinates[i].y;
			//cout << coordinates[i].x << coordinates[i].y << endl;
		}
		for (int i = 0; i < stones - 1; i++) {
			for (int j = i; j < stones; j++) {
				if (i == j) {
					lake[i][j] = 0.0;
					lake[j][i] = 0.0;
				}
				else {
					lake[i][j] = dist(coordinates[i], coordinates[j]);
					lake[j][i] = lake[i][j];
				}
			}
		}
		for (int k = 0; k < stones; k++) {
			for (int i = 0; i < stones; i++) {
				for (int j = 0; j < stones; j++) {
					lake[i][j] = min(lake[i][j], max(lake[i][k], lake[k][j]));
				}
			}
		}
		cout << "Scenario #" << scenario << endl << "Frog Distance = " ;
		cout << fixed << setprecision(3) << lake[0][1] << endl << endl;
	}

	//fin.close();

	return 0;
}
