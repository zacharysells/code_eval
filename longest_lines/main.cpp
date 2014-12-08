#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
#include <set>

struct classComp
{
	bool operator() (const std::string &lhs, const std::string &rhs) const
	{
		return lhs.size() > rhs.size();
	}
};

std::set<std::string, classComp> storeLinesFromFile(std::ifstream &file)
{
	std::string line;
	std::set<std::string, classComp> lines;
	while(getline(file, line))
	{
		if(line.length() == 0)
		{
			continue;
		}
		else
		{
			lines.insert(line);
		}
	}
	
	return lines;
}

int main(int argc, char * argv[])
{
	std::ifstream file;
	std::string line;
	
	file.open(argv[1]);

	getline(file, line);
	int line_amount = atoi(line.c_str());
	
	std::set<std::string, classComp> lines = storeLinesFromFile(file);
	
	int line_counter = 0;
	for(std::set<std::string, classComp>::iterator it = lines.begin(); 
												   line_counter < line_amount && it != lines.end();
												   ++it, ++line_counter)
	{
		printf("%s\n", it->c_str());
	}
	
}
