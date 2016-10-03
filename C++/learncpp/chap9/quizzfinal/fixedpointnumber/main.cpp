#include <iostream>
#include <cstdint>
#include <cmath>

class FixedPoint2
{
  
private:
  std::int16_t m_base;
  std::int8_t m_decimal;

public:
  FixedPoint2(std::int16_t base = 0, std::int8_t decimal = 0)
    : m_base{base}, m_decimal{decimal}
  {
  }

  FixedPoint2(double d)
  {
    m_base = static_cast<int16_t>(d);
    m_decimal = static_cast<std::int8_t>(round((d - m_base) * 100));
  }

  friend std::ostream& operator<< (std::ostream &out, const FixedPoint2 &fp)
  {
    out << fp.m_base << '.';

    if (fp.m_decimal < 10 && fp.m_decimal > -10)
      out << '0';

    out << static_cast<int>(fp.m_decimal > 0 ? fp.m_decimal : -fp.m_decimal);

    return out;
  }

  friend std::istream& operator>> (std::istream &in, FixedPoint2 &fp)
  {
    double d;
    in >> d;
    fp = FixedPoint2(d);

    return in;
  }

  friend FixedPoint2 operator+ (const FixedPoint2 &fp1, const FixedPoint2 &fp2)
  {
    FixedPoint2 temp(fp1.m_base + fp2.m_base, fp1.m_decimal + fp2.m_decimal);

    if (temp.m_decimal > 100) {
      temp.m_decimal -= 100;
      temp.m_base += 1;
    } else if (temp.m_decimal < -100) {
      temp.m_decimal += 100;
      temp.m_base -= 1;
    }

    return temp;
  }

  FixedPoint2 operator- ()
  {
    return FixedPoint2(-m_base, -m_decimal);
  }

  operator double()
  {
    return m_base + static_cast<double>(m_decimal) / 100;
  }
  
};

void testAddition()
{
	// h/t to reader Sharjeel Safdar for this function
	std::cout << std::boolalpha;
	std::cout << (FixedPoint2(5.67) + FixedPoint2(3.23) == FixedPoint2(8.90)) << '\n'; // both positive, no overflow
	std::cout << FixedPoint2(5.67) << '+' << FixedPoint2(3.23) << '=' << FixedPoint2(5.67) + FixedPoint2(3.23) << "\t// " << FixedPoint2(8.90) << '\n';
	std::cout << (FixedPoint2(5.55) + FixedPoint2(5.55) == FixedPoint2(11.10)) << '\n'; // both positive, overflow
	std::cout << (FixedPoint2(-54.25) + FixedPoint2(-25.26) == FixedPoint2(-79.51)) << '\n'; // both negative, no overflow
	std::cout << (FixedPoint2(-54.54) + FixedPoint2(-24.67) == FixedPoint2(-79.21)) << '\n'; // both negative, overflow
	std::cout << (FixedPoint2(85.74) + FixedPoint2(-25.45) == FixedPoint2(60.29)) << '\n'; // second negative, no overflow
	std::cout << (FixedPoint2(85.74) + FixedPoint2(-25.85) == FixedPoint2(59.89)) << '\n'; // second negative, overflow
	std::cout << (FixedPoint2(-85.74) + FixedPoint2(25.45) == FixedPoint2(-60.29)) << '\n'; // first negative, no overflow
	std::cout << (FixedPoint2(-85.74) + FixedPoint2(25.85) == FixedPoint2(-59.89)) << '\n'; // first negative, overflow
}
 
int main()
{
	testAddition();
 
	FixedPoint2 a(34, 56); 
	std::cout << a << '\n';
 
	std::cout << -a << '\n';
 
	std::cout << "Enter a number: "; // enter 5.678
	std::cin >> a;
	
	std::cout << "You entered: " << a << '\n';
 
	return 0;
}
