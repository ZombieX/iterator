
#include "pch.h"


#include<numeric>
#include<algorithm>
#include<utility>
#include"../google_test_try/iterator.hpp"


//テストクラスの定義
template<class T>
class IteratorTest:public ::testing::Test{
protected:

	constexpr static const auto size = 3;
	T a[size]{3,4,5};

public:
	IteratorTest() :a{} {}

};

//テストケースの宣言
TYPED_TEST_CASE_P(IteratorTest);

//テストその１
TYPED_TEST_P(IteratorTest, BeginEq) {

	EXPECT_EQ(zxc::st::begin(a), zxc::st::begin(a));

}

//テストその2
TYPED_TEST_P(IteratorTest, EndEq) {

	EXPECT_EQ(zxc::st::end(a), zxc::st::end(a));

}

//テストその3
TYPED_TEST_P(IteratorTest, OldFor) {

	auto it = zxc::st::begin(a);
;
	for (int i{}; i < size-1 ;++i) {
		EXPECT_EQ( *it, a[i]  );
		++it;
	}

}

//テストその4
TYPED_TEST_P(IteratorTest, RangeFor){
	
	int count{0};
	auto it = zxc::st::begin(a);
	
	for (auto &e:a) {

		EXPECT_EQ(*it, e);
		++it;
	}
	
}

//テストクラスとテストを登録
REGISTER_TYPED_TEST_CASE_P(
	IteratorTest
	, BeginEq, EndEq, OldFor, RangeFor);

//テストしたい型のリストを生成　と　型リストのエイリアス生成
using DefTypes = ::testing::Types<int, const double, const int* >;

//テストのインスタンス生成
INSTANTIATE_TYPED_TEST_CASE_P( Def, IteratorTest, DefTypes);
