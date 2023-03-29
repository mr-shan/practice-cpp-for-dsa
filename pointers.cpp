#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Rectangle
{
  int width;
  int height;
};

void struct_ptr_in_c ()
{
    struct Rectangle *p;
    p = (struct Rectangle *) malloc (sizeof (struct Rectangle));
    p->width = 20;
    p->height = 40;
    
    printf ("The width is: %d and height is: %d\n", p->width, p->height);
    
    free (p);
    return;
}

void struct_ptr_in_cpp ()
{
    Rectangle *p;
    p = new Rectangle;
    p->width = 5;
    p->height = 10;
    
    cout << "The width is: " << p->width;
    cout << " and height is: " << p->height << endl;
    
    delete p;
    
    return;
}

int main ()
{
    int num1 = 10;
    int *pt_num1 = &num1;
    
    std::cout << num1 << std::endl;	// value of variable
    std::cout << pt_num1 << std::endl;	// address of variable num1 which is stored in the pointer
    std::cout << *pt_num1 << std::endl;	// The value stored at the address which is stored in pointer
    std::cout << sizeof (pt_num1) << std::endl;	// size of pointer. It's same across it's datatype.
    std::cout << sizeof (*pt_num1) << std::endl;	// size of integer variable
    
    cout << endl;
    
    // allocate dynamic memory in the heap section.
    // (int *) is type conversion from void to int
    // malloc is function to allocate the memory. It takes the size of memory as param    
    int *ptr_arr = (int *) malloc (5 * sizeof (int));
    int *ptr_arr_cpp = new int[5];
    
    for (int i = 0; i < 5; ++i)
    {
      ptr_arr[i] = i + 1;
      ptr_arr_cpp[i] = (i + 1) * 2;
    }
    
    cout << "Printing the array" << endl;
    for (int i = 0; i < 5; ++i)
    {
      cout << ptr_arr[i] << ": x2 = ";
      cout << ptr_arr_cpp[i] << endl;
    }
    
    
    int arr[4] = { 2, 4, 6, 8 };
    int *ptr_to_arr = arr;	// pointer to array
    cout << "\n\n";
    for (int i = 0; i < 4; ++i)
    {
      cout << ptr_to_arr[i] << endl;
    }
    
    free (ptr_arr);		// de-allocate the memory from heap. 'C' way
    delete[]ptr_arr_cpp;		// de-allocate the memory from heap. 'C++' way
    
    
    
    // Pointer to struct
    
    struct Rectangle r = { 200, 100 };
    struct Rectangle *ptr_struct = &r;
    
    cout << "\n\nPrinting the Rectangle struct: \n";
    printf ("The width is %d and height is %d\n", r.width, r.height);
    
    cout << "\nPrinting using pointer to Rectangle struct: \n";
    cout << ptr_struct->width << endl;	// using arrow operator to access the struct elements
    
    // the reason for giving *ptr_struct in bracket is 
    // for resolving it's value first before accessing height using dot operator.
    cout << (*ptr_struct).height << endl;	// using pointer and dot operator to access struct elements
    
    
    cout << endl << endl;
    struct_ptr_in_c ();
    struct_ptr_in_cpp ();
    return 0;
}
