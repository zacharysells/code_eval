#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <cstdlib>
#include <algorithm>
using namespace std;

int sum(const list<int> &ints)
{
	list<int>::const_iterator it;
	int sum = 0;
	for(it = ints.begin(); it != ints.end(); ++it)
	{
		sum = sum + *it;
	}
	return sum;
}

void store_list(string &str, list<int> &ints)
{
	ints.clear();
	
	char token = ',';
	istringstream iss(str);
	string each;
	
	//for(string each; getline(iss, each, token); ints.push_front(atoi(each.c_str())));
	while(getline(iss, each, token))
	{
		ints.push_back(atoi(each.c_str()));
	}
}

int max_subarray(list<int> &ints)
{
	if(ints.size() <= 1)
	{
		return 0;
	}
	
	list<int> A(++ints.begin(), --ints.end());
	list<int> B(++ints.begin(), ints.end());
	list<int> C(ints.begin(), --ints.end());
	
	int A_max = sum(A);
	int B_max = sum(B);
	int C_max = sum(C);
	
	return max( max(sum(ints), A_max) , max(B_max, C_max) );
}

int main(int argc, char * argv[])
{
	ifstream file(argv[1]);
	
	string line;
	list<int> ints;
	int sum = 0;
	while(getline(file, line))
	{
		store_list(line, ints);
		sum = max_subarray(ints);
		printf("%d\n", sum);
	}
	
}
