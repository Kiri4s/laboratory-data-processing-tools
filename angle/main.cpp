#include <iostream>
#include <fstream>
#include <cmath>
#include "angle.hpp"

int main() {
    std::ifstream infile("test.txt");
    std::ofstream outfile("result.txt");
    
    Angle_t a, b;
    infile >> a >> b;
    outfile << "a = " << a << '\n' << "b = " << b << '\n' << "a+b = " << a + b << '\n' << "a-b = " << a - b << '\n';
    outfile << "2b = " << 2 * b << '\n' << "a/3 = " << a / 3 << '\n' << "radians a = " << a.radians() << '\n';
    outfile << "sin(b) = " << sin(b.radians()) << '\n' << "-a = " << -a << '\n';
    
    infile.close();
    outfile.close();
}