// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    size_t n = A.size();
    sort(A.begin(), A.end());
    int allpositive = A[n-1]*A[n-2]*A[n-3];
    int incl_negative = A[0]*A[1]*A[n-1];
    if (allpositive > incl_negative)
        return allpositive;
    else
        return incl_negative;
}
