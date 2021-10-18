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
    cout << shape1[0].a1(); 
    
    cout << "\t\tWelcome to the LINE CALCULATOR\t\t\n";
    cout << "All we need from you is the (a)x + (b)y = (c) forumla to find the point of intersection for two lines :)";
    

    
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