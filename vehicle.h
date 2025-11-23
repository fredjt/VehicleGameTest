//
// Created by fredt on 11/20/25.
//

#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>

#include "base_categories.h"
#include "compatible_engines.h"

class Vehicle : public Object
{
protected:
    static std::string trim_;

    explicit Vehicle(const size_t price) : Object(price) {}

public:
    Vehicle() = delete;
    static std::string getTrim() { return trim_; }
};

class VehicleComponent : public Object {};

class Engine : VehicleComponent
{
protected:
    size_t num_cylinders_;
    double displacement_;

    enum FuelType
    {
        GASOLINE,
        DIESEL,
        E85,
        HYDROGEN,
        METHANOL
    } fuel_type_;

    Engine(const size_t num_cylinders, const double displacement,
           const FuelType fuel_type) : num_cylinders_(num_cylinders)
                                       , displacement_(displacement)
                                       , fuel_type_(fuel_type) {}

public:
    Engine() = delete;
};

class Ford_Duratec_2_3_I4 : public Engine
{
public:
    Ford_Duratec_2_3_I4() : Engine(4, 2.3, GASOLINE) {}
};

class Mazda_3_S_2007 : public Vehicle, Mazda_3_S_2007_ENGINES
{
    Engine* engine_ = new Ford_Duratec_2_3_I4();

public:
    Mazda_3_S_2007() : Vehicle(15000) {}
    void swapEngine(Engine* engine) { engine_ = engine; }
};

#endif // VEHICLE_H
