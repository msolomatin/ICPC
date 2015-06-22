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
#include <cstring>
#include <unordered_set>
#include <functional>
using namespace std;

int main() {
  priority_queue<tuple<int, int, int>,
    vector<tuple<int, int, int>>,
    greater<tuple<int, int, int>>>queries;

  string command;
  int id, period, K;

  while (cin >> command) {
    if (command == "#") {
      cin >> K;
      break;
    }
    cin >> id >> period;
    queries.push(make_tuple(period, id, period));
  }

  for (int i = 0; i < K; i++) {
    auto query = queries.top();
    queries.pop();
    cout << get<1>(query) << endl;
    queries.push(make_tuple(get<0>(query) + get<2>(query), get<1>(query), get<2>(query)));
  }

  return 0;
}
