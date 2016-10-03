#include <iostream>
#include <cstdint>

class Average
{
private:
  int32_t m_sum = 0;
  int8_t m_nb = 0;

public:
  Average()
  {}

  friend std::ostream& operator<< (std::ostream &out, Average &avg)
  {
    std::cout << static_cast<double>(avg.m_sum) / avg.m_nb;
    return out;
  }
  
  Average& operator+= (int x)
  {
    m_sum += x;
    ++m_nb;
    return *this;
  }
};

int main()
{
  Average avg;
	
  avg += 4;
  std::cout << avg << '\n'; // 4 / 1 = 4
	
  avg += 8;
  std::cout << avg << '\n'; // (4 + 8) / 2 = 6

  avg += 24;
  std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

  avg += -10;
  std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

  (avg += 6) += 10; // 2 calls chained together
  std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

  Average copy = avg;
  std::cout << copy << '\n';

  return 0;
}
