/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: agendron
 *
 * Created on October 5, 2017, 12:47 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

class FarmAnimal 
{
public:
    FarmAnimal(double water_consumption);
    double getWaterConsumption();
    // ...
private:
    double water_consumption;
};

FarmAnimal::FarmAnimal(double water_consumption) 
{
    this->water_consumption = water_consumption;
}

double FarmAnimal::getWaterConsumption() 
{
    return water_consumption;
}

class ConsumptionAccumulator 
{
public:
    ConsumptionAccumulator();
    double getTotalConsumption();
    void addConsumption(FarmAnimal animal);
private:
    double total_consumption;
};

ConsumptionAccumulator::ConsumptionAccumulator() :
total_consumption(0) 
{
}

double ConsumptionAccumulator::getTotalConsumption() 
{
    return total_consumption;
}

void ConsumptionAccumulator::addConsumption(FarmAnimal animal) 
{
    total_consumption += animal.getWaterConsumption();
}

int main() 
{
    ConsumptionAccumulator accumulator;

    // read user input
    // create appropriate objects and add them to the accumulator

    double myNumber = 0;
    string input;

    do 
    {
        getline(cin, input);
        if (1 == sscanf(input.c_str(), "cow %lf", &myNumber)) 
        {
            myNumber = (myNumber / 100)*8.6;
            accumulator.addConsumption(myNumber);
        } 
        else if (1 == sscanf(input.c_str(), "sheep %lf", &myNumber)) 
        {
            myNumber = (myNumber / 10)*1.1;
            accumulator.addConsumption(myNumber);
        } 
        else if (1 == sscanf(input.c_str(), "horse %lf", &myNumber)) 
        {
            myNumber = (myNumber / 100)*6.8;
            accumulator.addConsumption(myNumber);
        }
    }    
    while (input != "");

    cout << accumulator.getTotalConsumption();

    return 0;
}


