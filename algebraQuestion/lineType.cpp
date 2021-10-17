#include "lineType.h"
#include <iostream>

void lineType::convertToSlopeForm(double a, double b, double c)
{
    
}

// If line is vertical, our slope will be undefined. 
bool lineType::isVerticalLine()
{
    if(b == 0)
        return true;
    return false; 
}

// If line is a horizontal line, then slope will be 0. 
bool lineType::isHorizontalLine()
{
    if(a == 0)
        return true;
    return false; 
}

bool lineType::isSameLine(lineType diffLine)
{
    if (diffLine.a1() == a1() && diffLine.b1() == b1() && diffLine.c1() == c1())
    {
        return true;
    }
    return false; 
}

bool lineType::isLineParallel(lineType diffLine)
{
    if (diffLine.slope1() == slope1() || (diffLine.isVerticalLine() && isVerticalLine()))
    {
        return true;
    }
    return false;
}

//Used to check against another line wheter or no a line is perpendicular. 
bool lineType::isLinePerpendicular(lineType diffLine)
{
    if(diffLine.isVerticalLine())
        if(isHorizontalLine())
            return true;
    if(diffLine.isHorizontalLine())
        if(isVerticalLine())
            return true;
    return false; 
}

void lineType::findIntersection(lineType)
{
}

void lineType::calculateLineShape(lineType, lineType, lineType)
{
}

//A constructor for creating a ax + by = c
lineType::lineType(double a, double b, double c)
{
    set_a(a);
    set_b(b);
    set_c(c);
}

//a Constructor for just a y = mx + b, where m is the "slope" and b is the constant. 
lineType::lineType(double slope, double constant)
{
    set_slope(slope);
    set_constant(constant);
}
