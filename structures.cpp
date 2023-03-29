#include <iostream>

using namespace std;

struct Rectangle {
    int width;
    int height;
};

int main()
{
    struct Rectangle r1 = {5, 5};
    
    // Change the dimensions of rectangle
    r1.width = 2;
    r1.height = 2;
    
    cout << "The size of struct is: " << sizeof(r1) << endl;
    
    cout << "The area of rectangle is: ";
    cout << r1.width * r1.height << endl << endl;
    
    
    // defining array of structures
    struct Rectangle rectangles[2] = {
        { 4, 4 },   // first rectangle 
        { 2, 2 }    // second rectanlge
    };
    
    cout << "First rectanlge \n";
    
    cout << rectangles[0].width << endl;
    cout << rectangles[0].height << endl << endl;
    
    
    cout << "Printing rectangles" << endl;
    for (struct Rectangle r:rectangles)
    {
        cout << r.width << endl;
        cout << r.height << endl;
        cout << endl;
    }
    
    return 0;
}
