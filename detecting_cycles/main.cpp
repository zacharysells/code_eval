#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

void setupArray(const string &line, vector<int> &seq)
{
	stringstream ss;
	ss.str(line);
	int n;
	while(ss >> n)
	{
		seq.push_back(n);
	}
}

void printCycle(const vector<int> &list)
{
	int hare = 0, rabbit = 0;
	for(; hare < list.size(); ++hare, rabbit += 2)
	{
		if(rabbit >= list.size())
			break;
			
			
		cout << "Hare: " << list[hare] << endl;
		cout << "rabbit: " << list[rabbit] << endl;
	}
	
}

int main(int argc, char * argv[])
{
	ifstream file(argv[1]);
	
	string line;
	vector<int> seq;
	while(getline(file, line))
	{
		seq.clear();
		setupArray(line, seq);
		printCycle(seq);
		printf("\n");
	}
	
}
