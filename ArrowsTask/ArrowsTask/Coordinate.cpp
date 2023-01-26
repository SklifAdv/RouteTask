#include "Coordinate.h"
#include <math.h>

short Coordinate::distanceTo(Coordinate otherCoordinate) const
{
    short val = (short)sqrt( pow((otherCoordinate.x() - m_x), 2) + pow((otherCoordinate.y() - m_y), 2) );
    return val;
}

bool Coordinate::operator== (const Coordinate& c1)
{
    return (c1.x() == m_x && c1.y() == m_y);
}