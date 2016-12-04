// Generic grid
#include <array>
#include <iostream>

template<typename T, size_t HEIGHT, size_t WIDTH>
class Grid {
public:
	Grid(const T& el = T());
	template<typename E, size_t HEIGHT2, size_t WIDTH2>
	Grid(const Grid<E, HEIGHT2, WIDTH2>& src);
	template<typename E, size_t HEIGHT2, size_t WIDTH2>
	Grid<T, HEIGHT, WIDTH>& operator= (const Grid<E, HEIGHT2, WIDTH2>& rhs);
	
	virtual void print() const;
	virtual const std::array<T, WIDTH>& operator[] (size_t pos) const;
	virtual ~Grid() {};
private:
	std::array<std::array<T, WIDTH>, HEIGHT> m_grid;
	template<typename E, size_t HEIGHT2, size_t WIDTH2>
	void copy(const Grid<E, HEIGHT2, WIDTH2>& src);

};

template<typename T, size_t HEIGHT, size_t WIDTH>
void Grid<T, HEIGHT, WIDTH>::print() const {
	for (int i = 0; i < HEIGHT; i++) {

		for (int j = 0; j < WIDTH; j++) {
			std::cout << m_grid[i][j] << "   "; 
		}
		std::cout << std::endl;
	}

}

template<typename T, size_t HEIGHT, size_t WIDTH>
Grid<T, HEIGHT, WIDTH>::Grid(const T& el) {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			m_grid[i][j] = el; 
		}
	}
}
template<typename T, size_t HEIGHT, size_t WIDTH>
template<typename E, size_t HEIGHT2, size_t WIDTH2>
void Grid<T, HEIGHT, WIDTH>::copy(const Grid<E, HEIGHT2, WIDTH2>& src) {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (i < HEIGHT2 && j < WIDTH2)
				m_grid[i][j] = src[i][j];
			else
				m_grid[i][j] = T();
		}
	}

}

template<typename T, size_t HEIGHT, size_t WIDTH>
template<typename E, size_t HEIGHT2, size_t WIDTH2>
Grid<T, HEIGHT, WIDTH>::Grid(const Grid<E, HEIGHT2, WIDTH2>& src) {
	std::cout << "Templated copy constructr!" << std::endl;
	copy(src);
}

template<typename T, size_t HEIGHT, size_t WIDTH>
const std::array<T, WIDTH>& Grid<T, HEIGHT, WIDTH>::operator[] (size_t pos) const {
	return m_grid[pos];
}

template<typename T, size_t HEIGHT, size_t WIDTH>
template<typename E, size_t HEIGHT2, size_t WIDTH2>
Grid<T, HEIGHT, WIDTH>& Grid<T, HEIGHT, WIDTH>::operator= (const Grid<E, HEIGHT2, WIDTH2>& rhs) {
	std::cout << "Templated assignment operator!" << std::endl;
	copy(rhs);
	return *this;
}



