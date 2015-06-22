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
  map<int, int> frequency;
  int T, N, M, ival, count;
  cin >> T;
  for (int i = 0; i < T; i++) {
    frequency.clear();
    cin >> N >> M;
    count = 0;
    for (int j = 0; j < N; j++) {
      cin >> ival;
      frequency[ival] += 1;
    }
    for (int j = 0; j < M; j++) {
      cin >> ival;
      frequency[ival] -= 1;
    }

    for (auto it = frequency.begin(); it != frequency.end(); it++) {
      count += abs(it->second);
    }

    cout << count << endl;

  }
  return 0;
}
