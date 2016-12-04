#include <algorithm>

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)   
    long local_slice = 0;
    long min = long(numeric_limits<int>::min())-1;
    long max_slice = min;
    for (int i = 0; i < A.size(); i++) {
        long tmp = local_slice + A[i];
	    if (local_slice > 0 && tmp > 0)
	        local_slice = tmp;
	    else
	        local_slice = A[i];    
        max_slice = local_slice > max_slice ? local_slice : max_slice;   
    }
    return max_slice;
}
