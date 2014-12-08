#include <fstream>
#include <string>
#include <sstream>
#include <stddef.h>
#include <cstdlib>
#include <cstdio>

using namespace std;


template <class T>
class Stack
{
	class Node
	{
		public:
		Node * next;
		T val;
		
		
		Node(T val)
		{
			this->val = val;
			this->next = NULL;
		}
	};
	
	Node * root;
	int size;
	
	public:

	Stack()
	:root(NULL), size(0)
	{}
	
	bool isEmpty() const
	{
		return (size == 0);
	}
	
	void push(T val)
	{
		Node * n = new Node(val);
		n->next = root;
		root = n;
		
		++size;
	}
	
	void pop()
	{
		if(size == 0)
			return;
		
		T val = root->val;
		Node * next = root->next;
		delete root;
		root = next;
		--size;
	}
	
	const T& top() const
	{
		if(root == NULL) exit(0);
		return root->val;
	}
	
	
};

void parseInput(const string &str)
{
	stringstream ss;
	ss.str(str);
	
	Stack<int> stack;
	int n;
	while(ss >> n)
	{
		stack.push(n);
	}
	
	bool alternate = true;
	while(!stack.isEmpty())
	{
		printf("%d ", stack.top());
		if(alternate)
		{
			stack.pop();
		}
		else
		{
			stack.pop();
		}
		alternate = !alternate;	
	}
}

int main(int argc, char * argv[])
{
	ifstream file(argv[1]);
	
	string line;
	while(getline(file, line))
	{
		parseInput(line);
		printf("\n");
	}
}
