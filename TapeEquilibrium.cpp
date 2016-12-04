

// you can use includes, for example:
#include <algorithm>
#include <numeric>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    int result = std::numeric_limits<int>::max();
    long long left_sum = A.front();
    long long right_sum = std::accumulate(A.begin()+1, A.end(), 0LL);
    unsigned int index = 1;
    for (; index < A.size(); index++) {
        int tmp = std::abs(left_sum - right_sum);
        if (tmp < result)
            result = tmp;
        left_sum += A[index];
        right_sum -= A[index];
    }
    return result;
}


