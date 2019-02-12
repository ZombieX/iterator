
#include "pch.h"


#include<numeric>
#include<algorithm>
#include<utility>
#include"../google_test_try/iterator.hpp"


//�e�X�g�N���X�̒�`
template<class T>
class IteratorTest:public ::testing::Test{
protected:

	constexpr static const auto size = 3;
	T a[size]{3,4,5};

public:
	IteratorTest() :a{} {}

};

//�e�X�g�P�[�X�̐錾
TYPED_TEST_CASE_P(IteratorTest);

//�e�X�g���̂P
TYPED_TEST_P(IteratorTest, BeginEq) {

	EXPECT_EQ(zxc::st::begin(a), zxc::st::begin(a));

}

//�e�X�g����2
TYPED_TEST_P(IteratorTest, EndEq) {

	EXPECT_EQ(zxc::st::end(a), zxc::st::end(a));

}

//�e�X�g����3
TYPED_TEST_P(IteratorTest, OldFor) {

	auto it = zxc::st::begin(a);
;
	for (int i{}; i < size-1 ;++i) {
		EXPECT_EQ( *it, a[i]  );
		++it;
	}

}

//�e�X�g����4
TYPED_TEST_P(IteratorTest, RangeFor){
	
	int count{0};
	auto it = zxc::st::begin(a);
	
	for (auto &e:a) {

		EXPECT_EQ(*it, e);
		++it;
	}
	
}

//�e�X�g�N���X�ƃe�X�g��o�^
REGISTER_TYPED_TEST_CASE_P(
	IteratorTest
	, BeginEq, EndEq, OldFor, RangeFor);

//�e�X�g�������^�̃��X�g�𐶐��@�Ɓ@�^���X�g�̃G�C���A�X����
using DefTypes = ::testing::Types<int, const double, const int* >;

//�e�X�g�̃C���X�^���X����
INSTANTIATE_TYPED_TEST_CASE_P( Def, IteratorTest, DefTypes);
