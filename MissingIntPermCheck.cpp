// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    /*
    long long actual_sum =  std::accumulate(A.begin(), A.end(), 0LL);
    long long expected_sum = (A.size()*(1 + A.size()))/2;
    return expected_sum == actual_sum;
    */
    std::sort(A.begin(), A.end());
    int min = 1;
    for (int a: A) {
        if (min == a)
            min++;
    }
    return min-1 == A.size();
    
}
