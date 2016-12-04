// you can use includes, for example:
// #include <algorithm>
#include <limits>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
        
    vector<int> prefix_sum;
    prefix_sum.assign(A.size()+1, 0);
    
    for (int i = 1; i < prefix_sum.size(); i++) {
        prefix_sum[i] = prefix_sum[i-1] + A[i-1];  
    }
    int result = -1;
    double min = numeric_limits<double>::max();
    for (int i = 2; i < prefix_sum.size(); i++) {
        double tmp = (prefix_sum[i] - prefix_sum[i-2])/2.0;
        if (tmp < min) {
            min = tmp;
            result = i-2;
        }
    }
    for (int i = 3; i < prefix_sum.size(); i++) {
        double tmp = (prefix_sum[i] - prefix_sum[i-3])/3.0;
         if (tmp < min) {
            min = tmp;
            result = i-3;
        }
    }
    return result;
}
