#include <iostream>
#include "lineType.h"
#include <fstream>

using namespace std;
void conductDataProcedures(lineType shape[], lineType shape2[], lineType shape3[]);

int main()
{
    double a;
    double b;
    double c;
    
    lineType line1;
    lineType line2;
    lineType shape1[4]; 
    lineType shape2[4];
    lineType shape3[4];

    conductDataProcedures(shape1, shape2, shape3);
    
    cout << "\t\tWelcome to the LINE CALCULATOR\t\t\n";
    cout << "There are two parts to this program, first, I am going to calculate the shapes from you\nHere are your results: \n";
    for(int i = 0; i < 4; i++)
    {
        shape1[i].convertToSlopeForm();
        shape2[i].convertToSlopeForm();
        shape3[i].convertToSlopeForm();
    }
    
    shape1[0].calculateLineShape(shape1[1], shape1[2], shape1[3]);
    cout << "\n\n";
    shape2[0].calculateLineShape(shape2[1], shape2[2], shape2[3]);
    cout << "\n\n";
    shape3[0].calculateLineShape(shape3[1], shape3[2], shape3[3]); 
    cout << "\n\n";

    cout << " \n In part 2, all we need from you is the (a)x + (b)y = (c) formula to find the point of intersection for two lines :)\nWhat is your A value? ";
    cin >> a;
    cout << "What is your B Value? ";
    cin >> b;
    cout << "What is your C Value ";
    cin >> c;
    line1.set_a(a);
    line1.set_b(b);
    line1.set_c(c);
    cout << "What is your A value for Line 2? ";
    cin >> a;
    cout << "What is your B Value? for line 2? ";
    cin >> b;
    cout << "What is your C Value for line 2? ";
    cin >> c;
    line2.set_a(a);
    line2.set_b(b);
    line2.set_c(c);
    
    if(!line1.isVerticalLine() && !line2.isVerticalLine())
    {
        line1.convertToSlopeForm();
        line2.convertToSlopeForm();
        if(line1.isSameLine(line2))
        {
            cout << "This is the same line.";
        }
           else if(!line1.isLineParallel(line2))
                line1.findIntersection(line2);
    }
    else
        cout << "You're line is vertical.";
    return 0;
}


    void conductDataProcedures(lineType shape[], lineType shape2[], lineType shape3[])
{
    ifstream fileIn;

    double a[12];
    double b[12];
    double c[12];
    int counter = 0;
    fileIn.open("data.txt");

    if (!fileIn.is_open())
    {
        cout << "File isn't open";
    }
    
    while(!fileIn.eof())
    {
        fileIn >> a[counter] >> b[counter] >> c[counter];
        counter++;
    }

    //stock in shape 1
    for(int i = 0; i < 4; i++)
    {
        shape[i].set_a(a[i]);
        shape[i].set_b(b[i]);
        shape[i].set_c(c[i]);
    }

    //stock in shape2
    for(int i = 0; i < 4; i++)
    {
        shape2[i].set_a(a[i + 4]);
        shape2[i].set_b(b[i + 4]);
        shape2[i].set_c(c[i + 4]);
    }

    //stock in shape3. 
    for(int i = 0; i < 4; i++)
    {
        shape3[i].set_a(a[i + 8]);
        shape3[i].set_b(b[i + 8]);
        shape3[i].set_c(c[i + 8]);
    }

    fileIn.close();
    
}