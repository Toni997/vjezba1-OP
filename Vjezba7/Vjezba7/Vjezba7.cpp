#include <iostream>
#include "Board.h"

int main()
{
    Point p1({ 2, 2 }), p2({ 8, 8 }), p3({ 8, 2 }), p4({ 8, 16 });
    Board b(10, 20);

    try
    {
        b.DrawLine(p1, p2, 'x');
        b.DrawLine(p3, p4, 'x');

        b.Display();
    }
    catch (const std::out_of_range& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}