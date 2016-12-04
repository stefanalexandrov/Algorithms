// you can use includes, for example:
#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>
#include <limits>
#include <iostream>


// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

const long double Epsilon = 1.0L;
bool compDoubles(long double a, long double b) {
    if (std::abs(a-b) < Epsilon)
            return true;
    else 
        return false;
}

int solution(std::vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    if (A.size() == 1)
        return 0;
    if (A.size() == 0)
        return -1;
    int index = 0;
    long double left_sum = 0.0L;
    long double right_sum = std::accumulate(A.begin()+1, A.end(), 0.0L);
    if (compDoubles(left_sum, right_sum))
        return index;
    left_sum = std::accumulate(A.begin(), A.begin()+1, left_sum);
    right_sum = std::accumulate(A.begin()+1, A.begin()+2, right_sum, std::minus<long double>());
    index += 1;
    for (auto it = A.begin()+1; it !=A.end(); it++, index++) {
        if (compDoubles(left_sum, right_sum))
            return index;
        //left_sum += A[index];
        left_sum = std::accumulate(it, it+1, left_sum);
        //right_sum -= A[index+1];
        right_sum = std::accumulate(it+1, it+2, right_sum, std::minus<long double>());
    }
    return -1; 
}

int main() {
    std::cout << std::boolalpha;
    std::cout << "Long double min value: " << std::numeric_limits<long double>::min() << std::endl;
    std::cout << "Long double max value: " << std::numeric_limits<long double>::max() << std::endl;
    std::cout << "Size of long double: " << sizeof(long double) << std::endl;
    std::cout << "int min value: " << std::numeric_limits<int>::min() << std::endl;
    std::cout << "int max value: " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "Size of int: " << sizeof(int) << std::endl;
    std::cout << "unsigned int min value: " << std::numeric_limits<unsigned int>::min() << std::endl;
    std::cout << "unsigned int max value: " << std::numeric_limits<unsigned int>::max() << std::endl;
    std::cout << "Size of unsigned int: " << sizeof(unsigned int) << std::endl;
 
    std::vector<int> arr = {-123, 345, 3333234, 65656, 5545, std::numeric_limits<int>::max()};
    std::vector<int> arr2 = {1, 2, 1};

    std::cout << "Equilibrium index: " << solution(arr) << std::endl;
    std::cout << "Equilibrium index: " << solution(arr2) << std::endl;

    return 0;
}
