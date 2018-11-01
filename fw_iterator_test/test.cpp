
#include "pch.h"


#include<numeric>
#include<algorithm>
#include<utility>
#include"../google_test_try/iterator.hpp"



template<class T>
class IteratorTest:public ::testing::Test{
protected:
	constexpr static const auto size = 3;
	T a[size]{3,4,5};
//	const double b[size * 2]{};
public:
	IteratorTest() :a{} {}

};

TYPED_TEST_CASE_P(IteratorTest);
TYPED_TEST_P(IteratorTest, BeginEq) {
	EXPECT_EQ(zxc::st::begin(a), zxc::st::begin(a));
}


TYPED_TEST_P(IteratorTest, EndEq) {
	EXPECT_EQ(zxc::st::end(a), zxc::st::end(a));

}


TYPED_TEST_P(IteratorTest, OldFor) {

	auto it = zxc::st::begin(a);
	for (int i{}; i < size-1 ;++i) {
		++it;
		EXPECT_NE( it, zxc::st::begin(a)  );
		EXPECT_NE( it, zxc::st::end(a) );
	}
	++it;

	EXPECT_NE(it , zxc::st::begin(a));
	EXPECT_EQ(it , zxc::st::end(a));

}


TYPED_TEST_P(IteratorTest, RangeFor){
	int count{0};
	auto it = zxc::st::begin(a);
	/*for (auto &e:a) {
		if (count != 0)
			EXPECT_NE(e, *it);
		else
			EXPECT_EQ(e, *it);
		++count;
	}*/
	
}

REGISTER_TYPED_TEST_CASE_P(
	IteratorTest
	, BeginEq, EndEq, OldFor,RangeFor);

using DefTypes = ::testing::Types<int, const double, const int* >;
INSTANTIATE_TYPED_TEST_CASE_P(Def, IteratorTest, DefTypes);
