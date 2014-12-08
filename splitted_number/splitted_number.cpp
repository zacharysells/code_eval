#include <cstdio>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

//Add operation char to the num parameter.
//Returns position of operation char. -1 if non-existant
int format(string &num, string &pattern)
{
	int num_int, e = 0, op_pos = -1;
	stringstream ss;
	
	ss << num;
	ss >> num_int;
	//if(!(num_int >= 100 && num_int <= 1000000000)) return -1;
	
	for(int i = 0; i < pattern.size(); ++i)
	{
		if(pattern[i] != '+' && pattern[i] != '-')
		{
			pattern[i] = num[e];
			++e;
		}
		else
			op_pos = i;
	}
	return op_pos;
}

void compute(string &num, string &pattern)
{
	int op_pos = format(num, pattern);
	if(op_pos < 0) return;
	
	string a, b;
	int a_num, b_num;
	stringstream ss;
	a = pattern.substr(0, op_pos);
	b = pattern.substr(op_pos+1);
	
	ss << a << " " << b;
	ss >> a_num >> b_num;

	if(pattern[op_pos] == '+')
		printf("%d\n", a_num + b_num);
	else
		printf("%d\n", a_num - b_num);
}

int main(int argc, char *argv[])
{
	string num, pattern;
	ifstream infile;
	infile.open(argv[1]);
	
	while(infile >> num)
	{
		infile >> pattern;
		compute(num, pattern);
	}
}
