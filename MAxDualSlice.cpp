// you can use includes, for example:
// #include <algorithm>
#include <limits>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

struct Tripple {
		int X = 0;
		int Y = 1;
		int Z = 3;
		long sum = 0;
		long left_sum = 0;
		long right_sum = 0;
};
struct Tripple tripple;
int computeInit(vector<int>& V, int j) {
		tripple.X = j;
		if (V[j+1] < V[j+2]) {
			tripple.Y = j+1;
			tripple.sum = V[j+2];
			tripple.left_sum =  V[j+2];
			tripple.right_sum = 0;
		} else {
			tripple.Y = j+2;
			tripple.sum = V[j+1];
			tripple.left_sum = 0;
			tripple.right_sum = V[j+1];
		}
		tripple.Z = j+4;
		return tripple.Z;
}

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2
    if (A.size() == 3)
        return 0;
    computeInit(A , 0);
	long max_sum = tripple.sum;	
	for (int i = 4; i < A.size(); i++) {
	    if (tripple.right_sum < 0 && tripple.Y+4 < A.size()) {
		    i = computeInit(A ,tripple.Y);
		    //continue;
	    }
	    if (A[tripple.Y] < 0 && (tripple.X-tripple.Y) == 1 && tripple.Y+4 < A.size()) {
		    i = computeInit(A ,tripple.Y);
		    //continue;
	    }
		tripple.Z = i;
		long tmp = tripple.left_sum + A[i-1];
		if (/*tmp > 0 &&*/ A[i-1] >= A[tripple.Y]) {
			tripple.left_sum = tmp;
		} else if (/*tmp > 0 &&*/ A[i-1] < A[tripple.Y] /*&& A[tripple.Y] > 0*/) {
			tripple.right_sum += A[tripple.Y] + tripple.left_sum;
			tripple.left_sum = 0;
			tripple.Y = i-1;
		} else {
		    if (i+4 < A.size()) {
			    i = computeInit(A ,i);
		    } else
		        break;
		}
		if (tripple.left_sum < 0 && i+4 < A.size()) {
		    i = computeInit(A ,tripple.Z);
		    //continue;
	    } 
		tripple.sum = tripple.left_sum + tripple.right_sum;
		max_sum = tripple.sum > max_sum ? tripple.sum : max_sum;
	}
	tripple.sum = tripple.left_sum + tripple.right_sum;
	max_sum = tripple.sum > max_sum ? tripple.sum : max_sum;
	if (max_sum < 0)
		    return 0;
	return max_sum;
}
