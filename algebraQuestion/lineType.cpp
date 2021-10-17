#include "lineType.h"
#include <iostream>


//By take -a/b and c/b we can re-create converting a formula from slope form into x == y;
void lineType::convertToSlopeForm()
{
    double slope = -a/b;
    double constant = c/b; 

    set_slope(slope);
    set_constant(constant);
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

void lineType::findIntersection(lineType otherLine)
{
    double xCoefficent = 0.0;
    double constant = 0.0;
    double x = 0;
    double y = 0;

    if(otherLine.slope1() < 0)
        xCoefficent = slope1() + -otherLine.slope1();
    else
        xCoefficent = slope1() - otherLine.slope1();

    if (constant1() < 0)
        constant = constant1() + otherLine.constant1();
    else
        constant = otherLine.constant1() - constant1();

    x = constant/xCoefficent;

    y = (slope1() * x) + constant1();
    
    set_x_value(x);
    set_y_value(y);

    std::cout << "You're coordinate intersection for these lines are: ("  << x_value() << "," << y_value() << ") Thanks for using our program!" << std::endl;
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
