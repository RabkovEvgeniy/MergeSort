#include <List.h>

#include <iostream>

using namespace std;

int main()
{
	cout << "LAB 12.1:" << endl;
	int a_sum;
	int b_sum;
	int c_sum;
	int run_c;
	int run_a;
	int run_b;
	List<int> A,B,C;

	for (int i = 0; i < 10; i++)
	{
		A.push_back(i);
		B.push_back(i + 10);
	}

	run_a = A.run_num();
	run_b = B.run_num();
	a_sum = A.check_sum();
	b_sum = B.check_sum();
	
	C.merge(A,A.get_size(),B,B.get_size());
	c_sum = C.check_sum();
	run_c = C.run_num();

	std::cout << "A = {x|0 <= x < 10} B = {x|10 <= x < 20} "<< endl;
	std::cout << "-----------------------------------------------------" << endl;
	std::cout << "A sum = " <<a_sum << endl;
	std::cout << "B sum = " <<b_sum << endl;
	std::cout << "C sum = " <<c_sum << endl << endl;
	std::cout << "run in A = " << run_a << endl;
	std::cout << "run in B = " << run_b << endl;
	std::cout << "run in C = " << run_c << endl << endl;
	std::cout << "M + C = " << C.M << " + " << C.C << " = " <<C.M + C.C << endl << endl << endl << endl;
	A.clear();
	B.clear();
	C.clear();

	for (int i = 0; i < 20; i+=2)
	{
		A.push_back(i);
		B.push_back(i + 1);
	}

	run_a = A.run_num();
	run_b = B.run_num();
	a_sum = A.check_sum();
	b_sum = B.check_sum();

	C.merge(A, A.get_size(), B, B.get_size());
	c_sum = C.check_sum();
	run_c = C.run_num();

	std::cout << "A = {x|x < 20; x % 2 == 0} B = {x|x < 20; x % 2 != 0}"<< endl;
	std::cout << "-----------------------------------------------------" << endl;
	std::cout << "A sum = " << a_sum << endl;
	std::cout << "B sum = " << b_sum << endl;
	std::cout << "C sum = " << c_sum << endl << endl;
	std::cout << "run in A = " << run_a << endl;
	std::cout << "run in B = " << run_b << endl;
	std::cout << "run in C = " << run_c << endl << endl;
	std::cout << "M + C = " << C.M << " + " << C.C << " = " << C.M + C.C << endl << endl;
	C.clear();

	cout << endl << endl;
	cout << "LAB 12.2:" << endl;
	std::cout << "-----------------------------------------------------" << endl;
	std::cout << "-----------------------------------------------------" << endl;
	std::cout << "-----------------------------------------------------" << endl;
	C.FillDec(20);
	cout << "Fill Dec:" << endl;
	C.print();
	cout << endl << "Check sum:" << C.check_sum() << endl;
	C.MergeSort();
	cout << endl << "Merge Sort:" << endl;
	C.print();
	cout << endl << "Check sum:" << C.check_sum() << endl;
	cout << "Run:" << C.run_num() << endl;
	C.clear();

	std::cout << "-----------------------------------------------------" << endl;
	C.FillRund(20);
	cout << "Fill Inc:" << endl;
	C.print();
	cout << endl << "Check sum:" << C.check_sum() << endl;
	C.MergeSort();
	cout << endl << "Merge Sort:" << endl;
	C.print();
	cout << endl << "Check sum:" << C.check_sum() << endl;
	cout << "Run:" << C.run_num() << endl;
	C.clear();
	std::cout << "-----------------------------------------------------" << endl;

	cout << "n\t\tMergeSort\t" << endl;
	cout << "\tInc\tDec\tRand\tTeor" << endl;

	for (int i = 100; i < 501; i+=100)
	{
		cout << i << "\t";
		C.FillInc(i);
		C.MergeSort();
		cout << C.M + C.C << "\t";
		C.clear();
		C.FillDec(i);
		C.MergeSort();
		cout << C.M + C.C << "\t";
		C.clear();
		C.FillRund(i);
		C.MergeSort();
		cout << C.M + C.C << "\t";
		C.clear();
		cout << (int)(2 * i * log2(i) + i) << "\t";
		cout << endl;
	}
}
