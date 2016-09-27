#include <iostream>
#include <string>

class Ball
{
    std::string m_color;
    double m_radius;

public:

    // Using constructors with no default values

    // Ball()
    // {
    //     m_color = "black";
    //     m_radius = 10.0;
    // }
    //
    // Ball(const std::string &color)
    // {
    //     m_color = color;
    //     m_radius = 10.0;
    // }
    //
    // Ball(double radius)
    // {
    //     m_color = "black";
    //     m_radius = radius;
    // }
    //
    // Ball(const std::string &color, double radius)
    // {
    //     m_color = color;
    //     m_radius = radius;
    // }

    // Using as few constructors as possible with default values

    Ball(double radius)
	{
		m_color = "black";
		m_radius = radius;
	}

    Ball(const std::string &color = "black", double radius = 10.0)
    {
        m_color = color;
        m_radius = radius;
    }

    void print()
    {
        std::cout << "color: " << m_color << ", radius: " << m_radius << '\n';
    }
};

int main()
{
        Ball def;
        def.print();

	Ball blue("blue");
	blue.print();

	Ball twenty(20.0);
	twenty.print();

	Ball blueTwenty("blue", 20.0);
	blueTwenty.print();

    return 0;
}
