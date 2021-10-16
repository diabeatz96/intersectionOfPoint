#pragma once
#include <fstream>

class lineType
{
public:




    /*                                    /*
     * GETTERS AND SETTERS FOR THE CLASS
     */                                   //
    
    double a1() const
    {
        return a;
    }

    void set_a(double a)
    {
        this->a = a;
    }

    double b1() const
    {
        return b;
    }

    void set_b(double b)
    {
        this->b = b;
    }

    double c1() const
    {
        return c;
    }

    void set_c(double c)
    {
        this->c = c;
    }

    double x_value() const
    {
        return xValue;
    }

    void set_x_value(double x_value)
    {
        xValue = x_value;
    }

    double y_value() const
    {
        return yValue;
    }

    void set_y_value(double y_value)
    {
        yValue = y_value;
    }

    double slope1() const
    {
        return slope;
    }

    void set_slope(double slope)
    {
        this->slope = slope;
    }

    double constant1() const
    {
        return constant;
    }

    void set_constant(double constant)
    {
        this->constant = constant;
    }


    /*
     *   Variety of Functions to work with linetypes.
     *   We will give the user and option to convert in program OR import from a file, either work is fine.
     *
     */

    void convertToSlopeForm(double, double, double);
    bool isVerticalLine(lineType);
    bool isSameLine(lineType);
    bool isLineParallel(lineType);
    bool isLinePerpendicular(lineType);
    void findIntersection(lineType);
    void importFileValues(std::fstream);
    
    lineType(double, double, double); // CONSTRUCTOR FOR ax + by = c
    lineType(double, double); //Constructor for y = mx + b

private:

    double a = 0.0; 
    double b = 0.0;
    double c = 0.0;
    
    double xValue = 0.0;
    double yValue = 0.0;
    double slope = 0.0;
    double constant = 0.0;
};
