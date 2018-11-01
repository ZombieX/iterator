#pragma once

#include<cinttypes>
#include<array>

template<class T, std::uint64_t N >
class vector {
	std::array<T,N> ar;
	
public:
	vector(int x_, int y_) :x{ x_ }, y{ y_ } {}
	auto operator<(const point&t) const {
		return
			x < t.x ?
			true : y < t.y; ;
	}
};