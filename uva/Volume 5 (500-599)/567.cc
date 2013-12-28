// 567

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
#include <functional>
using namespace std; 

const int maxN = 20;
const long long INF = 2147483647;
long long G[maxN][maxN];

void FloydWarshall() {
        for (int k = 0; k < maxN; k++) {
                for (int i = 0; i < maxN; i++) {
                        for (int j = 0; j < maxN; j++) {                                
                                G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
                        }
                }
        }
}

int main(){

        //fstream f;
        //f.open("c:\\Users\\m_solomatin\\Documents\\Visual Studio 11\\Projects\\uva\\Debug\\inp.txt");

        //int to, delay, startFrom, goTo, caseNo = 0, minDelay, no;
        int n, ival, from, to, no = 1;
        bool first, firstSet = true;

        while (cin >> n) {
                first = true;
                for (int i = 0; i < maxN; i++) {
                        for (int j = 0; j < maxN; j++) {
                                G[i][j] = INF;
                        }
                        G[i][i] = 0;
                }
                for (int i = 0; i < maxN - 1; i++) {
                        if (!first) {
                                cin >> n;
                        }
                        first = false;
                        for (int j = 0 ; j < n; j++) {
                                cin >> ival;
                                G[i][ival - 1] = 1;
                                G[ival - 1][i] = 1;
                        }
                }

                FloydWarshall();
                //if (!firstSet) {
                //        cout << endl;
                //}
                //firstSet = false;

                cout << "Test Set #" << no << endl;
                cin >> ival;
                for (int i = 0; i < ival; i++) {
                        cin >> from >> to;
                        //cout << setw(2) << from << " to " << setw(2) << to << ": ";
                        //cout << G[from - 1][to - 1] << endl;
                        printf("%2d to %2d: %d\n", from, to, G[from - 1][to - 1]);
                }
                cout << endl;
                no += 1;
        }

        //f.close();

        return 0;
}