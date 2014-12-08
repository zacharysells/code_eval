#include <cstdlib>
#include <fstream>
#include <cstring>
using namespace std;
void splitString(const string &line, string &a, string &b)
{
	int delim_pos = line.find(';');
	a = line.substr(0, delim_pos);
	b = line.substr(delim_pos + 1);
}



int lcs(const string &a, const string &b)
{
	int table[a.size()][b.size()];
	
	for(int i = 0; i < a.size(); ++i)
	{
		table[i][0] = 0;
	}
	for(int i = 0; i < b.size(); ++i)
	{
		table[0][i] = 0;
	}
	
	for(int i = 1; i < a.size(); ++i)
	{
		for(int e = 1; e < b.size(); ++e)
		{
			if(a[i] == a[e])
			{
				table[i][e] = 1 + table[i-1][e-1];
			}
			
			else
			{
				table[i][e] = max(table[i][e-1], table[i-1][e]);
			}
		}
	}
	
	return table[a.size() - 1][b.size() - 1];
}

int main(int argc, char * argv[])
{
	ifstream file(argv[1]);
	
	string line, a, b, result;
	int n = 0;
	while(getline(file, line))
	{
		splitString(line, a, b);
		result.clear();
		n = lcs(a, b);
		printf("%d\n", n);
	}
}
