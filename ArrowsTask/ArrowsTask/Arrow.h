#pragma once
#ifndef ARROW_H
#define ARROW_H

#include "Coordinate.h"

class Arrow
{
public:

    enum Direction
    {
        kUp = 72,
        kLeft = 75,
        kRight = 77,
        kDown = 80
    };

    Arrow(const Coordinate from, Arrow::Direction direction);

    Coordinate getOrigin() const { return m_origin; }
    Coordinate getDestination() const { return m_destination; }

private:
    Coordinate m_origin;
    Coordinate m_destination;

    Arrow();
};

#endif // ARROW_H