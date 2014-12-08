#include <fstream>
#include <iostream>
#include <set>

using namespace std;

void getPermutationsPrefix(const string &prefix, const string &str, set<string> &perms)
{
	if(str.size() == 0)
	{
		perms.insert(prefix);
	}
	
	for(int i = 0; i < str.size(); ++i)
	{
		getPermutationsPrefix(prefix + str[i], str.substr(0,i) + str.substr(i + 1), perms);
	}
	
}

void getPermutations(const string &str)
{
	set<string> perms;
	getPermutationsPrefix("", str, perms);
	
	set<string>::iterator it;
	set<string>::iterator dupe;
	for(it = perms.begin(); it != perms.end(); ++it)
	{
		dupe = it;
		++dupe;
		if(dupe == perms.end())
		{
			printf("%s",it->c_str());
			break;
		}
		printf("%s,",it->c_str());
	}
}

int main(int argc, char * argv[])
{
	ifstream file(argv[1]);
	
	string line;
	while(getline(file, line))
	{
		getPermutations(line);
		printf("\n");
	}
	
}
