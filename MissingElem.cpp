

// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    //if (A.size() == 0)
    //    return 1;
    // write your code in C++11 (g++ 4.8.2)
    long expected_sum = ((A.size()+1)*(A.size()+2))/2;
    long actual_sum = std::accumulate(A.begin(), A.end(), 0L);
    return expected_sum - actual_sum;
}


