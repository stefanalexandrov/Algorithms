#include "circularBuffer.h"
#include <iostream>
#include <string>

const size_t BUFFER_SIZE = 10;

template<size_t N>
std::string useBuffer(CircularBuffer<int, N>& buf) {
    std::string result = "";
    for (int i = 0; i<N+5; i++) {
	buf.write(i);
    }
    for (int i = 0; i<N; i++) {
	result += std::to_string(buf.read());
	result += ' ';
    }
    return result;
}

int main() 
{
    using iterator = std::array<int, 6>::iterator;
    try {
        CircularBuffer<int, BUFFER_SIZE> A;
        std::array<int, 5> tmp;
        // no typename necessary before std::array<int, 5>::iterator!!! hmmm
        //using iterator = std::array<int, 5>::iterator;
        std::cout << "Using circular buffer!!!\n";
        std::cout << useBuffer(A) << "\n";
        std::cout << "Using circular buffer created with initializer-list constructor!!!\n";
        CircularBuffer<int, BUFFER_SIZE> B {1,2,3,4,5,6,7,8,9,10};
        std::cout << useBuffer(B) << "\n";
        std::cout << "Number of buffers of type <int, 10>: " << A.get_counter() << "\n";
        CircularBuffer<int, BUFFER_SIZE+1> A1;
        CircularBuffer<int, BUFFER_SIZE+1> B1;
        CircularBuffer<int, BUFFER_SIZE+1> C1;
        std::cout << "Number of buffers of type <int, 11>: " << A1.get_counter() << "\n";
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}


