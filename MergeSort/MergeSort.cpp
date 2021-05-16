#include <List.h>

#include <iostream>

using namespace std;

int main()
{
	int a_sum;
	int b_sum;
	int c_sum;
	int run_c;
	List<int> A,B,C;
	for (int i = 0; i < 10; i++)
	{
		A.push_back(i);
		B.push_back(i + 10);
	}

	a_sum = A.check_sum();
	b_sum = B.check_sum();
	
	C.merge(A, B);
	c_sum = C.check_sum();
	run_c = C.run_num();

	std::cout << "A sum = " <<a_sum << endl;
	std::cout << "B sum = " <<b_sum << endl;
	std::cout << "C sum = " <<c_sum << endl;
	std::cout << "run in C = " << run_c << endl << endl;
}
