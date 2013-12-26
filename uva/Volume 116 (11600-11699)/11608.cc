
// 11608
#include <iostream>
#include <vector>
using namespace std;

int main() {
        int S, ival, current, tmp, caseNo = 1;
        vector<int>created(13);
        vector<int>required(12);
        while (cin >> S) {
                if (S < 0) {
                        break;
                }
                for (int i = 1; i < 13; i++) {
                        cin >> ival;
                        created[i] = ival;
                }
                for (int i = 0; i < 12; i++) {
                        cin >> ival;
                        required[i] = ival;
                }
                created[0] = S;
                cout << "Case " << caseNo << ":" << endl;
                for (int i = 0; i < 12; i++) {
                        if (created[i] - required[i] >= 0) {
                                cout << "No problem! :D" << endl;
                                created[i + 1] += created[i] - required[i];                                
                        }
                        else {
                                cout << "No problem. :(" << endl;
                                created[i + 1] += created[i];
                        }                        
                }
                caseNo += 1;
        }

        return 0;
}
