#include <cstdlib>
#include <iostream>
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
