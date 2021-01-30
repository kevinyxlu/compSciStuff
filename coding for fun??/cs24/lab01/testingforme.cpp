//template.cpp
//Created by: Kevin Lu
//Created on: 10/20/2020
//Lab Partner: 

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <cmath>

#include "perf.hpp"
#include "doors.hpp"
#include "car.hpp"
#include "car.cpp"
#include "perf.cpp"
using namespace std;


int main()
{
    PerformanceStats example(1, 2, 3);
    Car test("sdoa", "asdg", example, 4, None);
    Car defCar;
    cout << test.getStats() << endl;
    cout << test.getManufacturer() << " " << test.getModel() << endl;
    test.manufacturerChange("Honda");
    test.modelNameChange("Civic");
    cout << test.getManufacturer() << " " << test.getModel() << endl;
    Car copy1(test);
    copy1 = copy1;
    return 0;
}