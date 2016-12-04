

// you can use includes, for example:
#include <algorithm>
#include <vector>
#include <bitset>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    //cout << "start!\n";
    const size_t int_size = sizeof(int)*8;
    // write your code in C++11 (g++ 4.8.2)
    std::vector<size_t> gaps = {};
    std::bitset<int_size> bits(N);
    //cout << bits << endl;
    int index = int_size-2;
    while (index >= 0) {
       //cout << "entered while!\n";
       size_t size_of_gap = 0;
       if (bits[index] == true && index >= 1 && bits[index-1] == false) {
           //cout << "enter index: " << index << " :" << bits[index] <<endl;
           index -=1;
           //cout << "found 1-0 transition!\n";
           for (;index >= 0 ;index--) {
               if (bits[index] == false) {
                    //cout << "incrementing!!!\n";
                    size_of_gap += 1;
                } else {
                    index += 1;
                    gaps.push_back(size_of_gap);
                    size_of_gap = 0;
                    break;
                }
           }
          if (size_of_gap != 0)
              gaps.push_back(size_of_gap);    
       }
       index -= 1;   
    }
    if (gaps.size() == 0)
        return 0;
    std::sort(gaps.begin(), gaps.end());
    return gaps.back();
}


