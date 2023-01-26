#pragma once
#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate
{
public:

    Coordinate()
        : m_x(0), m_y(0)
    {
    }

    Coordinate(
        short x,
        short y)
        : m_x(x), m_y(y)
    {
    }

    short x() const { return m_x; };
    short y() const { return m_y; };
    void setX(short x) { m_x = x; };
    void setY(short y) { m_y = y; };

    short distanceTo(Coordinate otherCoordinate) const;
    bool operator== (const Coordinate& c1);

private:
    short m_x = 0;
    short m_y = 0;
};

#endif // COORDINATE_H