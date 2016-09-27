#include <iostream>
#include "Point3d.hpp"
#include "Vector3d.hpp"

void Point3d::print()
{
    std::cout << "Point (" << m_x << ", " << m_y << ", " << m_z << ")\n";
}

void Point3d::moveByVector(Vector3d &v)
{
    m_x += v.m_x;
    m_y += v.m_y;
    m_z += v.m_z;
}
