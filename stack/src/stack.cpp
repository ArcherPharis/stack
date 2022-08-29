#include <iostream>
#include <memory>
#include <string>
#include <initializer_list>

const int maxSize = 100;

//uses generic types, class name will just be "stack"
template<typename StackType> 
class stack
{
	//creates an array that can accept generic type.
	StackType theStack[maxSize];
	int topIndex;

public:
	//constructor ensures it's empty.
	stack() { topIndex = 0; }
	~stack() { std::cout << "Deconstructor\n";}


	//copy con (deep copy)
	stack(const stack& rhs)
		: topIndex{ rhs.size()}, theStack{new StackType[maxSize]}
	{
		for (int i = 0; i < maxSize; ++i)
		{
			theStack[i] = rhs.theStack[i];
		}
	}

	//move con (shallow copy)
	stack(stack&& rhs)
		: topIndex{rhs.size()}, theStack{rhs.theStack}
	{
		rhs.theStack = nullptr;
		rhs.topIndex = 0;
	}

	//move assignment operator
	stack& operator=(stack&& rhs)
	{
		topIndex = std::move(rhs.topIndex);
		theStack = std::move(rhs.theStack);
		return *this;
	}

	//copy assignment operator, requires move assignment operator
	stack& operator=(const stack& rhs)
	{
		//copy 
		stack Temp = rhs;
		//and swap
		std::swap(*this, Temp);
		return *this;
	}


	StackType& operator[](int index)
	{
		return theStack[index];
	}

	int size() const
	{
		return topIndex;
	}

	void push(StackType item)
	{
		if (topIndex == maxSize)
		{
			std::cout << "Stack is full\n";
			return;
		}
		//puts whatever you push in as the topIndex, then increments the topindex variable for the next item.
		theStack[topIndex] = item;
		topIndex++;
	}

	StackType pop()
	{
		if (topIndex == 0)
		{
			std::cout << "Empty stack\n";
			return 0;
		}
		//decrements the index and pops out the item at that index.
		topIndex--;
		return theStack[topIndex];
	}
};

int main()
{
	stack<char> charStack;
	charStack.push('a');
	charStack.push('b');
	charStack.push('c');

	stack<std::string> stringStack;
	stringStack.push("stack");
	stringStack.push("am");
	stringStack.push("I");


	std::cout << "printing the second element in charStack: " << charStack[1] << "\n";

	for (int i = 0; i < 3; i++)
	{
		std::cout << charStack.pop() << '\n';
	}

	for (int i = 0; i < 3; i++)
	{
		std::cout << stringStack.pop() << '\n';
	}



	return 0;
}