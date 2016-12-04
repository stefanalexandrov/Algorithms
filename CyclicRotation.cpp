// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(vector<int> &A, int K) {
    // write your code in C++11 (g++ 4.8.2)
    std::vector<int> result = A;
    if (K <= 0 || A.size() <= 1)
       return result;
    int safeK = K % A.size();
    std::rotate(result.rbegin(), result.rbegin()+safeK, result.rend());
    return result;
}
