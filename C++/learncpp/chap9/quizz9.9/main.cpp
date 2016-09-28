#include <string>
#include <iostream>

class MyString
{
private:
    std::string m_string;

public:
    MyString(const std::string string="")
        : m_string{string}
    {}

    std::string operator()(int index, int length);
};

std::string MyString::operator()(int index, int length)
{
    std::string ret;
    for (size_t i = index; i < index+length; ++i) {
        ret += m_string[i];
    }
    return ret;
}

int main()
{
    MyString string("Hello, world!");
    std::cout << string(7, 5); // start at index 7 and return 5 characters

    return 0;
}
