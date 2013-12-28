
// 591


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
using namespace std; 

class Solve {
public:
  int solve (vector<int> brick) {
    int result = 0;
    int sum = accumulate(brick.begin(), brick.end(), 0);
    int avg = sum / brick.size();
    for (int i = 0; i < brick.size(); i++) {
      if (brick[i] < avg) {
        result += avg - brick[i];
      }
    }

    return result;
  }
};



int main(){

  Solve s;
  int noOfBricks;
  int tmp, setNo = 0;
  vector<int> brick;

  while (cin >> noOfBricks) {
    brick.clear();
    setNo += 1;
    if (noOfBricks == 0) {
      break;
    }
    
    for (int i = 0; i < noOfBricks; i++) {
      cin >> tmp;
      brick.push_back(tmp);

    }

    cout << "Set #" << setNo << endl;
    cout << "The minimum number of moves is " << s.solve(brick) << "." << endl << endl;
  }
  return 0;
}

