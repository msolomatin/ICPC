// 572

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

vector <string> G;
bool visited[100][100];
int counter, X, Y;
char c;

void dfs(int i, int j, char c) {

        if (i < 0 || j < 0 || i >= X || j >= Y || visited[i][j] || G[i][j] != c) {
                return;
        }

        visited[i][j] = true;

        dfs(i, j + 1, c);
        dfs(i, j - 1, c);
        dfs(i - 1, j, c);
        dfs(i + 1, j, c);
        dfs(i - 1, j - 1, c);
        dfs(i + 1, j - 1, c);
        dfs(i - 1, j + 1, c);
        dfs(i + 1, j + 1, c);

}

int main(){

        //fstream f;
        //f.open("c:\\Users\\mikhail.solomatin\\Documents\\Visual Studio 2010\\Projects\\test\\Debug\\inp.txt");

        string s;

        while (cin >> X >> Y) {
                if (X == 0 && Y == 0) {
                        break;
                }

                G.clear();
                counter = 0;

                for (int i = 0; i < X; i++) {
                        for (int j = 0; j < Y; j++) {
                                visited[i][j] = false;
                        }
                }

                for (int i = 0; i < X; i++) {
                        cin >> s;
                        G.push_back(s);
                }

                for (int i = 0; i < X; i++) {
                        for (int j = 0; j < Y; j++) {
                                if (!visited[i][j] && G[i][j] == '@') {
                                        dfs(i, j, '@');
                                        counter += 1;
                                }
                        }
                }
                cout << counter << endl;
        }

        //f.close();

        return 0;
}
