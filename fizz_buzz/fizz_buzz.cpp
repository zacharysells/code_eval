#include <fstream>
#include <cstdio>

using namespace std;

void fizz_buzz(int fizz_num, int buzz_num, int it)
{
	for(int i = 1; i < it+1; ++i)
	{
		if((i % fizz_num == 0) && (i % buzz_num == 0)) printf("%s ", "FB");
		else if(i % fizz_num == 0) printf("%c ", 'F');
		else if(i % buzz_num == 0) printf("%c ", 'B');
		else printf("%d ", i);
	}
	printf("\n");
	
}

bool check_constraints(int fizz_num, int buzz_num, int it, ifstream &infile)
{
	int num_tests = 0;
	while(infile >> fizz_num)
	{
		infile >> buzz_num;
		infile >> it;
		if(!((fizz_num >= 1 && fizz_num <= 20)
		&& (buzz_num >= 1 && buzz_num <= 20)
		&& (it >= 21 && it <= 100)))
		{
			return false;
		}
		++num_tests;
		if (num_tests > 20)
			return false;
	}
	return true;
}

int main(int argc, char *argv[])
{
	int fizz_num, buzz_num, iterations;
	ifstream infile;
	infile.open(argv[1]);
	
	if(!check_constraints(fizz_num, buzz_num, iterations, infile))
	{
		printf("ERROR");
		return 0;
	}
	
	infile.clear();
	infile.seekg(0, ios::beg);
	while(infile >> fizz_num)
	{
		infile >> buzz_num;
		infile >> iterations;
		fizz_buzz(fizz_num, buzz_num, iterations);
	}
}
