#include <fstream>
#include <cstdio>

using namespace std;

int fib(int n)
{
	if(n < 0) return -1;
	if(n == 0) return 0;
	if(n == 1) return 1;
	return fib(n-1) + fib(n-2);
}

int main(int argc, char * argv[])
{
	int n;
	ifstream infile;
	infile.open(argv[1]);
	
	while(infile >> n)
		printf("%d\n", fib(n));
}
