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
	int max_so_far = 0, max_ending_here = 0;
	
	list<int>::iterator it;
	for(it = ints.begin(); it != ints.end(); ++it)
	{
		max_ending_here = max_ending_here + *it;
		
		if(max_ending_here < 0)
		{
			max_ending_here = 0;
		}
		if(max_so_far < max_ending_here)
		{
			max_so_far = max_ending_here;
		}
	}
	return max_so_far;
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
