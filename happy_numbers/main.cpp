#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <set>

using namespace std;

int sumSquaresOfDigits(int i)
{
	int sum = 0;
	while(i > 0)
	{
		sum = sum + ((i % 10) * (i % 10));
		i = i / 10;
	}
	return sum;
}


int isHappy(int candidate)
{
	
	set<int> sum_squares_list;
	int sum_square_digits;
	while(candidate != 1)
	{
		sum_square_digits = sumSquaresOfDigits(candidate);
		if(sum_squares_list.find(sum_square_digits) != sum_squares_list.end())
		{
			return 0;
		}
		sum_squares_list.insert(sum_square_digits);
		candidate = sum_square_digits;
	}
	
	return 1;
	
}

int main(int argc, char * argv[])
{
	ifstream file;
	file.open(argv[1]);
	
	string line;
	int candidate;
	while(getline(file, line))
	{	
		candidate = atoi(line.c_str());
		std::cout << isHappy(candidate) << std::endl;
	}
	
}
