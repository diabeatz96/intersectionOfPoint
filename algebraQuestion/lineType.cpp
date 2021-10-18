#include "lineType.h"
#include <iostream>

const double Pi = 3.14159265358979323846264; //constant expression
const double DegreestoRadians = 180/Pi;

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

void lineType::calculateLineShape(lineType side2, lineType side3, lineType side4)
{
    /*                      side 4
     *                   ------------
     *                  |           |
     *           side 1 |           |  side 2
     *                  |           |
     *                  -------------
     *                      side 3
     *
     *We are basing this off of the assumption that in a box these are the sides (based on the data given to us)
     */
    
    if(isLineParallel(side2) == true && side3.isLineParallel(side4) == true) {
        if(isLinePerpendicular(side3) && isLinePerpendicular(side4) && side2.isLinePerpendicular(side4) && side2.isLinePerpendicular(side3))
        {
            std::cout << "You're points lead me to believe that your equation is a square or a rectangle";
        }
        else
        {
            std::cout << "You're points fit the description of a parallelogram or a rhombus (graph for further analysis)";
        }
    }
    else
        std::cout << "You're points fit the aesthetic of a trapezoid or undefined shape (not listed)"; 



    /* Complicated Version OMITTED, doing easier method. with No angles. 
    convertToSlopeForm();
    side2.convertToSlopeForm();
    side3.convertToSlopeForm();
    side4.convertToSlopeForm();
    
    findIntersection(side3);
    side2.findIntersection(side4);
    side3.findIntersection(side2);
    side4.findIntersection(*this);

    std::cout << atan2(y_value(), x_value()) * DegreestoRadians << std::endl;
    std::cout << atan2(side2.y_value(), side2.x_value()) * DegreestoRadians << std::endl;
    std::cout << atan2(side3.y_value(), side3.x_value()) * DegreestoRadians << std::endl;
    std::cout << atan2(side4.y_value(), side4.x_value()) * DegreestoRadians << std::endl;
    */
}

lineType::lineType()
{
    double a = 0.0; 
    double b = 0.0;
    double c = 0.0;
    
    double xValue = 0.0;
    double yValue = 0.0;
    double slope = 0.0;
    double constant = 0.0;
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
