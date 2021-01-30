// Kevin Lu - 9964164
// This is the only file to submit.

#include "car.hpp"
#include <cstddef>
#include <cstring>
// #include .......
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

// default constructor
Car::Car() 
{
    //set pointer type vars to NULL
    manufacturer = NULL;
    model = NULL;
    
    //set backseatDoors to none
    backseatDoors = None;

    //set numerical vars to 0
    zeroToSixtyNs = 0;
    headonDragCoeff = 0;
    horsepower = 0;
    seatCount = 0;
}

// constructor with info arguments
Car::Car(char const* const manufacturerName, char const* const modelName, PerformanceStats perf, uint8_t numSeats, DoorKind backseatDoorDesign) 
{
    //set pointer type vars and allocating dynamic mem
    manufacturer = new char[50000];
    model = new char[50000];
    strcpy(manufacturer, manufacturerName);
    strcpy(model, modelName);
    
    //set backseatDoors
    backseatDoors = backseatDoorDesign;

    //set numerical vars
    zeroToSixtyNs = perf.zeroToSixtyNs;
    headonDragCoeff = perf.headonDragCoeff;
    horsepower = perf.horsepower;
    seatCount = numSeats;
}

// copy constructor
Car::Car(Car const& o)
{
    //deep copy pointer type vars
    manufacturer = new char[50000];
    model = new char[50000];
    copy(o.manufacturer, o.manufacturer + 50000, manufacturer);
    copy(o.model, o.model + 50000, model);
    
    //copy backseatDoors
    backseatDoors = o.backseatDoors;

    //copy numerical vars
    zeroToSixtyNs = o.zeroToSixtyNs;
    headonDragCoeff = o.headonDragCoeff;
    horsepower = o.horsepower;
    seatCount = o.seatCount;    
}

//constructor that sets values in current object equal to those in o
//takes one car object and copies it to another car obejct
Car& Car::operator=(Car const& o)
{
    // check for self assignment
    // car1 = car1;
    if(this == &o)
    {
        return *this;
    }

    //copy pointer type vars
    copy(o.manufacturer, o.manufacturer + 50000, manufacturer);
    copy(o.model, o.model + 50000, model);
    
    //copy backseatDoors
    backseatDoors = o.backseatDoors;

    //copy numerical vars
    zeroToSixtyNs = o.zeroToSixtyNs;
    headonDragCoeff = o.headonDragCoeff;
    horsepower = o.horsepower;
    seatCount = o.seatCount;   

    return *this;
}

// destructor
Car::~Car()
{
    delete[] manufacturer;
    delete[] model;
}

//accessor for manufacturer
char const* Car::getManufacturer() const
{
    return manufacturer;
}

//accessor for model
char const* Car::getModel() const
{
    return model;
}

//accessor for Performanace Stats
PerformanceStats Car::getStats() const
{
    PerformanceStats temp(horsepower, zeroToSixtyNs, headonDragCoeff);
    return temp;
}

//accessor for seatCount
uint8_t Car::getSeatCount() const
{
    return seatCount;
}

//accessor for backseatDoors
DoorKind Car::getBackseatDoors() const
{
    return backseatDoors;
}

//mutator for manufacturer
void Car::manufacturerChange(char const* const newManufacturer)
{
    delete[] manufacturer;
    manufacturer = new char[50000];
    strcpy(manufacturer, newManufacturer);
}

//mutator for model
void Car::modelNameChange(char const* const newModelName)
{
    delete[] model;
    model = new char[strlen(newModelName)];
    strcpy(model, newModelName);
}

//mutator for values of zeroToSixtyNs, headonDragCoeff, horsepower
void Car::reevaluateStats(PerformanceStats newStats)
{
    zeroToSixtyNs = newStats.zeroToSixtyNs;
    headonDragCoeff = newStats.headonDragCoeff;
    horsepower = newStats.horsepower;
}

//mutator for seatCount
void Car::recountSeats(uint8_t newSeatCount)
{
    seatCount = newSeatCount;
}

//mutator for backseatDoors
void Car::reexamineDoors(DoorKind newDoorKind)
{
    backseatDoors = newDoorKind;
}