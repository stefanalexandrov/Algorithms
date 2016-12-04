// you can use includes, for example:
#include <algorithm>
#include <array>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int X, vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    vector<int> sec;
    sec.assign(X, -1);
    for (int i = 0; i < A.size(); i++) {
        int tmp = sec[A[i]-1];
        if (i < tmp || tmp < 0)
           sec[A[i]-1] = i;
    }
    int result = -1;
    for (int i: sec) {
        if (i < 0)
            return -1;
        if (i > result || result < 0)
            result = i;
    }
    return result;
}
