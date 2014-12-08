#include <fstream>
#include <cmath>

using namespace std;

bool is_prime(int num)
{
	for(int i = 2; i <= int(floor(sqrt(double(num)))); ++i)
	{
		if(num % i == 0) return false;
	}
	return true;
}

void list_primes(int num)
{
	int first_prime = 0;
	for(int i = 2; i < num; ++i)
	{
		if(is_prime(i))
		{
			++first_prime;
			if(first_prime == 1) printf("%d", i);
			else printf(",%d", i);
		}
	}
	printf("\n");
}

int main(int argc, char *argv[])
{
	int num;
	ifstream infile(argv[1]);
	while(infile >> num)
	{
		list_primes(num);
	}
}
