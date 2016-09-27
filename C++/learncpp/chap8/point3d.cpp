#include <iostream>

class Point3d
{
    double m_x;
    double m_y;
    double m_z;

public:
    void setValues(double x, double y, double z)
    {
        m_x = x;
        m_y = y;
        m_z = z;
    }

    void print()
    {
        std::cout << '<' << m_x << ", " << m_y << ", " << m_z << '>';
    }
};

int main()
{
    Point3d point;
    point.setValues(1.0, 2.0, 3.0);

    point.print();

    return 0;
}
