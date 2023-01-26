#include "Arrow.h"
#include <iostream>

Arrow::Arrow(const Coordinate from, Arrow::Direction direction)
{
    Coordinate dest(0, 0);

    switch(direction)
    {
        case kUp: 
        {
            dest.setX(from.x());
            dest.setY(from.y() + 1);
            break;
        }
        case kDown: 
        {
            dest.setX(from.x());
            dest.setY(from.y() - 1);
            break;
        }
        case kLeft: 
        {
            dest.setX(from.x() - 1);
            dest.setY(from.y());
            break;
        }
        case kRight:
        {
            dest.setX(from.x() + 1);
            dest.setY(from.y());
            break;
        }
    }

    m_origin = from;
    m_destination = dest;
}
