#pragma once


#include<cinttypes>


namespace zxc {
	namespace st {

		template<class T, std::uint64_t N, bool alive>
		class iterator;



		template<class T, std::uint64_t N>
		class alive_iterator;

		template<class T, std::uint64_t N>
		class dead_iterator;
	}
	namespace dy {}
}


template<class T,std::uint64_t N, bool alive = true>
class zxc::st::iterator {
	T* here;
public:
	constexpr iterator(T* tp = nullptr)noexcept :here{ tp } {}
	
	auto& operator++() noexcept{
		++here; return *this;
	}

	auto operator++(int)noexcept {
		auto tmp = *this;
		++(*this);
		return tmp;
	}


	auto& operator*()const& noexcept{
		return *here;
	}

	auto& operator*()& noexcept {
		return *here;
	}

	auto& operator*()&& noexcept {
		return *here;
	}

	auto operator==(const zxc::st::iterator<T,N,true> &it)
		const noexcept{
		return here == it.here ;
	}

	auto operator==(const zxc::st::iterator<T, N, false> &it)
		const noexcept {
		return zxc::st::iterator<T, N, false>{here} == it;
	}


	template<bool B>
	auto operator!=(const zxc::st::iterator<T, N, B>&it)
		const noexcept{
		return !(*this == it);
	}


};


template<class T, std::uint64_t N>
class zxc::st::iterator<T, N, false> {
	T* here;
public:
	constexpr iterator(T* tp = nullptr)noexcept :here{ tp } {}

	template<bool B>
	auto operator==(const zxc::st::iterator<T, N, B> &it)
		const noexcept {
		return !B ? here == it.here : false;
	}

	template<bool B>
	auto operator!=(const zxc::st::iterator<T, N, B>&it)
		const noexcept {
		return !(*this == it);
	}


};


template<class T, std::uint64_t N>
class zxc::st::alive_iterator
	:public  zxc::st::iterator<T, N, true> {
public:
	constexpr alive_iterator(T*tp) :zxc::st::iterator<T, N, true>{tp} {}
};

template<class T, std::uint64_t N>
class zxc::st::dead_iterator
	:public  zxc::st::iterator<T, N, false> {
public:
	constexpr dead_iterator(T*tp) :zxc::st::iterator<T, N, false>{ tp + N } {}
};

/*
template<class T, std::uint64_t N_>
class zxc::st::iterator {
public:
	using value_type = T;
	constexpr static const auto N = N_;

	template<class >
};*/


namespace zxc{
	namespace st {

		template<class T, std::uint64_t N>
		auto begin(T(&arr)[N]) noexcept {
			return zxc::st::alive_iterator<T, N>{arr};
		}

		template<class T, std::uint64_t N>
		auto begin(const T(&arr)[N]) noexcept {
			return zxc::st::alive_iterator<const T,N>{arr};
		}


		template<class T, std::uint64_t N>
		auto end(T(&arr)[N])noexcept {
			return zxc::st::dead_iterator<T,N>{arr };
		}

		template<class T, std::uint64_t N>
		auto end(const T(&arr)[N]) {
			return zxc::st::dead_iterator<const T,N>{ arr };
		}

	}
}
