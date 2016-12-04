// Simple circular buffer.
#ifndef _CIRCULAR_BUFFER_
#define _CIRCULAR_BUFFER_

#include <array>
#include <initializer_list>
#include <exception>
#include <algorithm>




template <typename T, size_t N>
class CircularBuffer {
public:
    using iterator = typename std::array<T, N>::iterator;
    CircularBuffer();
    CircularBuffer(std::initializer_list<T> args);
    CircularBuffer(const CircularBuffer& src);
    CircularBuffer& operator=(const CircularBuffer& rhs);
    void write(T el);
    T read(); // removes element, so it is not const method
    bool is_empty() const {return m_end == m_begin;}
    size_t size() const {return m_elements.size();}
    int get_counter() const {return s_Counter;}
    int get_ID() const {return m_ID;}
private:
    std::array<T, N> m_elements;
    int m_begin;
    int m_end;
    static int s_Counter;
    int const m_ID;
};


template <typename T, size_t N>
int CircularBuffer<T, N>::s_Counter;

// Default constructor
template <typename T, size_t N>
CircularBuffer<T, N>::CircularBuffer(): m_ID(s_Counter++)  {
    m_begin = m_end = 0; 
}

// Initialiser list constructor
template <typename T, size_t N>
CircularBuffer<T, N>::CircularBuffer(std::initializer_list<T> args): m_ID(s_Counter++) {
    if (args.size() > N)
        throw std::invalid_argument("Initializer list contains more arguments than a buffer can store!");
    else {
        std::move(args.begin(), args.end(), m_elements.begin());
        m_begin = 0;
        m_end = N - 1;
    }
}

// Assignment oerator
template <typename T, size_t N>
CircularBuffer<T, N>& CircularBuffer<T, N>::operator=(const CircularBuffer<T, N>& rhs) {
    m_elements = rhs.m_elements;
    m_begin = rhs.m_begin;
    m_end = rhs.m_end;
    return *this;
}
// Copy constructor
template <typename T, size_t N>
CircularBuffer<T, N>::CircularBuffer(const CircularBuffer& src): m_ID(s_Counter++) {
    m_elements = src.m_elements;
    m_begin = src.m_begin;
    m_end = src.m_end;
}

// Write to buffer. Inserts an element.
template <typename T, size_t N>
void CircularBuffer<T, N>::write(T el) {
	m_elements.at(m_begin) = el;
	m_begin++;
	if (m_begin == m_elements.size())
		m_begin = 0;
}

// Read from buffer. Removes an element.
template <typename T, size_t N>
T CircularBuffer<T, N>::read() {
	T result = m_elements.at(m_end);
	m_end++;
	if (m_end == m_elements.size())
	    m_end = 0;
	return result;
}

#endif
