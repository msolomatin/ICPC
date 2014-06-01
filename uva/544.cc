// 544
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

map<string, int>cityMap;

int cityIndex(string s) {
	if (cityMap.find(s) != cityMap.end()) {
		cityMap[s];
	}
	else {
		cityMap[s] = cityMap.size();
	}
	return cityMap[s] - 1;
}

int main () {
	int noOfCities, r, weight, fromIndex, toIndex;

	const int N = 200;

	double cities[N + 5][N + 5];
	int scenario = 0;
	string from, to, startCity, endCity;

	//fstream fin("absum.in");

	while (cin >> noOfCities >> r) {
		if (noOfCities == 0 && r == 0) {
			break;
		}

		cityMap.clear();

		scenario += 1;

		for (int i = 0; i < noOfCities; i++) {
			for (int j = 0; j < noOfCities; j++) {
				cities[i][j] = -1;
			}
			cities[i][i] = 0;
		}

		for (int i = 0; i < r; i++) {
			cin >> from >> to >> weight;
			fromIndex = cityIndex(from);
			toIndex = cityIndex(to);
			cities[fromIndex][toIndex] = weight;
			cities[toIndex][fromIndex] = weight;
		}

		cin >> startCity >> endCity;

		for (int k = 0; k < noOfCities; k++) {
			for (int i = 0; i < noOfCities; i++) {
				for (int j = 0; j < noOfCities; j++) {
					cities[i][j] = max(cities[i][j], min(cities[i][k], cities[k][j]));
					cities[j][i] = cities[i][j];
				}
			}
		}

		fromIndex = cityIndex(startCity);
		toIndex = cityIndex(endCity);

		cout << "Scenario #" << scenario << endl;
		cout << cities[fromIndex][toIndex] << " tons" <<
				endl << endl;
	}

	//fin.close();

	return 0;
}
