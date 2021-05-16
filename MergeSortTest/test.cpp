#include <pch.h>
#include <List.h>

template <typename T>
class TestList: public List<T>
{
public:
	bool head_is_nullptr()
	{
		return this->head==nullptr;
	};

	bool tail_is_nullptr()
	{
		return this->tail == nullptr;
	}

	int get_size()
	{
		return this->size;
	}

};


TEST(List, constructor) {
  
	//Arrange
	const int exp_size = 0;
	int real_size;
	bool tail_is_nullptr, head_is_nullptr;
	//Act
	TestList<int> list;
	real_size = list.get_size();
	tail_is_nullptr = list.tail_is_nullptr();
	head_is_nullptr = list.head_is_nullptr();

	//Assert
	EXPECT_EQ(real_size, exp_size);
	EXPECT_TRUE(head_is_nullptr);
	EXPECT_TRUE(tail_is_nullptr);
}

TEST(List, push_front) {

	//Arrange
	TestList<int> list;
	const int exp_size_0 = 1;
	const int exp_size_1 = 2;
	int real_size_0;
	int real_size_1;
	bool tail_is_nullptr, head_is_nullptr;
	
	//Act
	list.push_front(1);
	tail_is_nullptr = list.tail_is_nullptr();
	head_is_nullptr = list.head_is_nullptr();
	real_size_0 = list.get_size();
	
	list.push_front(2);
	real_size_1 = list.get_size();

	//Assert
	EXPECT_EQ(real_size_0, exp_size_0);
	EXPECT_FALSE(head_is_nullptr);
	EXPECT_FALSE(tail_is_nullptr);

	EXPECT_EQ(real_size_1, exp_size_1);
}

TEST(List, push_back) {

	//Arrange
	TestList<int> list;
	const int exp_size_0 = 1;
	const int exp_size_1 = 2;
	int real_size_0;
	int real_size_1;
	bool tail_is_nullptr, head_is_nullptr;

	//Act
	list.push_back(1);
	tail_is_nullptr = list.tail_is_nullptr();
	head_is_nullptr = list.head_is_nullptr();
	real_size_0 = list.get_size();

	list.push_back(2);
	real_size_1 = list.get_size();

	//Assert
	EXPECT_EQ(real_size_0, exp_size_0);
	EXPECT_FALSE(head_is_nullptr);
	EXPECT_FALSE(tail_is_nullptr);

	EXPECT_EQ(real_size_1, exp_size_1);
}

TEST(List, pop_front) {

	//Arrange
	TestList<int> list;
	list.push_front(1);
	list.push_front(2);

	int real_size_0;
	int real_size_1;
	int real_size_2;

	const int exp_size_0 = 0;
	const int exp_size_1 = 0;
	const int exp_size_2 = 1;
	bool tail_is_nullptr, head_is_nullptr;

	//Act
	list.pop_front();
	real_size_2 = list.get_size();

	list.pop_front();
	real_size_1 = list.get_size();
	tail_is_nullptr = list.tail_is_nullptr();
	head_is_nullptr = list.head_is_nullptr();

	EXPECT_THROW(list.pop_front(), int);
	real_size_0 = list.get_size();
	
	//Assert
	EXPECT_EQ(real_size_2, exp_size_2);
	
	EXPECT_EQ(real_size_1, exp_size_1);
	EXPECT_TRUE(head_is_nullptr);
	EXPECT_TRUE(tail_is_nullptr);

	EXPECT_EQ(real_size_0, exp_size_0);
}

TEST(List, pop_back) {

	//Arrange
	TestList<int> list;
	list.push_back(1);
	list.push_back(2);

	int real_size_0;
	int real_size_1;
	int real_size_2;

	const int exp_size_0 = 0;
	const int exp_size_1 = 0;
	const int exp_size_2 = 1;
	bool tail_is_nullptr, head_is_nullptr;

	//Act
	list.pop_back();
	real_size_2 = list.get_size();

	list.pop_back();
	real_size_1 = list.get_size();
	tail_is_nullptr = list.tail_is_nullptr();
	head_is_nullptr = list.head_is_nullptr();

	EXPECT_THROW(list.pop_back(), int);
	real_size_0 = list.get_size();

	//Assert
	EXPECT_EQ(real_size_2, exp_size_2);

	EXPECT_EQ(real_size_1, exp_size_1);
	EXPECT_TRUE(head_is_nullptr);
	EXPECT_TRUE(tail_is_nullptr);

	EXPECT_EQ(real_size_0, exp_size_0);
}