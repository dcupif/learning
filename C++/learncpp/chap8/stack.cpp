#include <iostream>
#include <cassert>

class Stack
{
    int m_array[10];
    int m_next;

public:
    void reset()
    {
        for (size_t i = 0; i < 10; i++) {
            m_array[i] = 0;
        }
        m_next = 0;
    }

    bool push(int value)
    {
        if (m_next >= 10)
            return false;
        m_array[m_next++] = value;
        return true;
    }

    int pop()
    {
        assert(m_next>0);
        return m_array[--m_next];
    }

    void print()
    {
        std::cout << "( ";
        for (size_t i = 0; i < m_next; i++) {
            std::cout << m_array[i] << ' ';
        }
        std::cout << ")\n";
    }
};

int main()
{
	Stack stack;
	stack.reset();

	stack.print();

	stack.push(5);
	stack.push(3);
	stack.push(8);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

	return 0;
}
