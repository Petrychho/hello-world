#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iterator>

void join(const std::vector< int > &from, std::vector< int > &to)
{
	std::vector<int> out;
	out.reserve(from.size() + to.size());

	std::merge(from.begin(), from.end(),
		to.begin(), to.end(),
		std::back_inserter(out));
	
	to = out;
};

void join1(const std::vector< int > &from, std::vector< int > &to)
{
	std::vector<int>::const_iterator first1, last1;
	std::vector<int>::iterator first2, last2, tmp_iter;
	std::vector<int> tmp;

	tmp.reserve(from.size() + to.size());
	first1 = from.begin();	last1 = from.end();
	first2 = to.begin();	last2 = to.end();
	tmp_iter = tmp.begin();
	

	while (first1 != last1 && first2 != last2)
	{
		tmp.push_back((*first1 < *first2) ? *first1++ : *first2++);
	}
	while (first1 != last1)
	{
		tmp.push_back(*first1++);
	}
	while (first2 != last2)
	{
		tmp.push_back(*first2++);
	}
	to = tmp;
};
	


int main()
{
	std::vector<int> A{ 1,2,3,4,5,6,7,8,9 };
	std::vector<int> B{ 4,5,6,7,8,9 };
	std::vector<int> C{ 1,2,3,4,5,6,7,8,9 };
	std::vector<int> D{ 4,5,6,7,8,9 };

	join(A, B);	

	std::cout << "B : ";
	std::copy(B.begin(), B.end(),
		std::ostream_iterator<int>(std::cout, " "));
	std::cout << '\n';

	join1(C, D);
	
	std::cout << "C : ";
	std::copy(B.begin(), B.end(),
		std::ostream_iterator<int>(std::cout, " "));
	std::cout << '\n';

	return 0;
}
