// 924
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
#include <queue>
using namespace std;

vector<vector<int> >G;

void dfs(int start, int employees) {
    int ival, maximumDailyBoom = -1;
    vector<int>maximumDailyBoomCounter(employees, 0);
    vector<int>boom(employees, 0);

    vector<bool> visited(employees, false);
    queue<int>q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        ival = q.front();
        q.pop();
        vector<int>::iterator it;
        for (it = G[ival].begin(); it != G[ival].end(); it++) {
            if (!visited[*it]) {
                maximumDailyBoomCounter[*it] = maximumDailyBoomCounter[ival] + 1;
                visited[*it] = true;
                q.push(*it);
                boom[maximumDailyBoomCounter[*it]] += 1;
            }
        }
    }
    
    int maxBoom = -1, maxIndex = 0;
    for (int i = 0; i < employees; i++) {
        if (boom[i] > maxBoom) {
            maxBoom = boom[i];
            maxIndex = i;
        }
    }
    if (maxBoom == 0) {
        cout << maxBoom << endl;
    }
    else {
        cout << maxBoom << " " << maxIndex << endl;
    }
}

int main() {
    int employees, friends, testCases, myFriend, test;
    //fstream fin("absum.in");
    cin >> employees;
    G.resize(employees);
    for (int i = 0; i < employees; i++) {
        cin >> friends;
        for (int j = 0; j < friends; j++) {
            cin >> myFriend;
            G[i].push_back(myFriend);
        }
    }

    cin >> testCases;
    for (int i = 0; i < testCases; i++) {
        cin >> test;
        dfs(test, employees);
    }

    //fin.close();
    return 0;
}
