#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

void sort_print(const string &numbers)
{
	vector<double> list;
	double x;
	stringstream ss;
	ss << numbers;
	while(ss >> x)
	{
		list.push_back(x);
	}
	sort(list.begin(), list.end());
	for(int i = 0; i < list.size(); ++i)
		printf("%g ", list[i]);
	if(list.size() != 0)
		printf("\n");
}


int main(int argc, char *argv[])
{
	ifstream infile(argv[1]);
	string temp;
	while(infile)
	{
		getline(infile, temp);
		sort_print(temp);
	}
}
