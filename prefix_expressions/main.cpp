#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
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
		if(root == NULL)
		{
			printf("Stack is empty! Exiting..\n");
			exit(0);
		}
		return root->val;
	}
	
	
};

bool isOperator(const string &str)
{
	if(str.size() == 1)
	{
		char op = str[0];
		return (op == '+' || op == '-' || op == '*' || op == '/');
	}
	return false;
}

void setup_stack(const string &str, Stack<string> &stack)
{
	stringstream ss;
	ss.str(str);
	string s;
	while(ss >> s)
	{
		stack.push(s);
	}
}

int eval_prefix(char op, int operand1, int operand2)
{
	switch(op)
	{
		case '+':
		{
			return operand1 + operand2;
		}
		case '-':
		{
			return operand1 - operand2;
		}
		case '*':
		{
			return operand1 * operand2;
		}
		case '/':
		{
			return operand1 / operand2;
		}
	}
	
	//Error. This should never be reached
	printf("Illegal operator passed");
	exit(0);
}

int evalutate(const string &str)
{
	int operand1 = 0, operand2 = 0, result = 0;
	
	Stack<string> prefix;
	Stack<int> operands;
	setup_stack(str, prefix);
	
	
	while(!prefix.isEmpty())
	{
		string curr = prefix.top();
		if(isOperator(curr))
		{
			operand1 = operands.top();
			operands.pop();
			
			operand2 = operands.top();
			operands.pop();

			result = eval_prefix(curr[0], operand1, operand2);
			operands.push(result);
			
		}
		else
		{			
			//Convert string to int before pushing to stack
			operands.push( atoi(curr.c_str()) );
		}
		prefix.pop();
	}
	
	return operands.top();
}


int main(int argc, char *argv[])
{
	ifstream file(argv[1]);
	
	string line;
	int result = 0;
	while(getline(file, line))
	{
		result = evalutate(line);
		printf("%d\n", result);
	}
	
}
