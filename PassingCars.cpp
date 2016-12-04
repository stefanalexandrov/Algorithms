// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    long long n_passing_cars = 0;
    auto east_car = find(A.begin(), A.end(), 0);
    auto first_east = east_car;
    int total_sum = accumulate(east_car, A.end(), 0);
    n_passing_cars = total_sum;
    int next_sum = 0;
    while (east_car != A.end()) {
         east_car = find(east_car+1, A.end(), 0);
         next_sum = accumulate(first_east, east_car, next_sum);
         first_east = east_car;
         n_passing_cars += total_sum - next_sum;
         /*
         for (auto it2 = east_car; it2 != A.end(); it2++) {
            if (*it2 == 1)
                n_passing_cars++;
         }
         */
    }
    
    if  ( n_passing_cars > 1000000000)
        return -1;
    else 
        return n_passing_cars;
}
