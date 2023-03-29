#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


class Rectangle
{
  private:
  int length;
  int height;
  
  public:
  Rectangle(int length, int height)
  {
      this->length = length;
      this->height = height;
  }
  
  int area()
  {
      return this->length * this->height;
  }
};

template <class T>
class Square
{
    private:
    T side;
    
    public:
    Square(T side)
    {
        this->side = side;
    }
    
    T area()
    {
        return this->side * this->side;
    }
    
    ~Square()
    {
        cout << "Calling the destructor of Square class" << endl;
    }
};


int main ()
{
    Rectangle r(10, 20);
    cout << "Area is: " << r.area() << endl;
    
    Rectangle *r2 = new Rectangle(2, 2);
    cout << "Area2 is: " << r2->area() << endl;
    
    Square<float> sqr(1.5);
    cout << "Area of sqr: " << sqr.area() << endl;
    
    return 0;
}
