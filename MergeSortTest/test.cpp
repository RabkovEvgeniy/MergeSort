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