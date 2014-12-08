#include <fstream>

using namespace std;

void reverse(const string &str)
{
	if(str == "") return;
	if(str.find(" ") == string::npos) 
	{
		printf("%s ", str.c_str());
		return;
	}
	reverse(str.substr(str.find(" ") + 1));
	printf("%s", str.substr(0, str.find(" ") + 1).c_str());
}

int main(int argc, char *argv[])
{
	ifstream infile(argv[1]);
	string arg;
	while(infile)
	{
		getline(infile, arg);
		reverse(arg);
		if(arg != "") printf("\n");
	}
}
