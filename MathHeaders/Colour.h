#pragma once
#include <cstdint>

namespace MathClasses
{
    struct Colour
    {
        // Default constructor set colour to white
        Colour();
        // Constructor to set colour to a specific colour
        Colour(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);

        // Getters and setters for red
        uint8_t GetRed() const;
        void SetRed(uint8_t red);

        // Getters and setters for green
        uint8_t GetGreen() const;
        void SetGreen(uint8_t green);

        // Getters and setters for blue
        uint8_t GetBlue() const;
        void SetBlue(uint8_t blue);

        // Getters and setters for alpha
        uint8_t GetAlpha() const;
        void SetAlpha(uint8_t alpha);

        // Equality and inequality operators
        bool operator==(const Colour& other) const;
        bool operator!=(const Colour& other) const;

        // Colour data
        uint32_t colour; 
    };
}