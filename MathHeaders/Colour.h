#pragma once
#include <cstdint>

namespace MathClasses
{
    struct Colour
    {
        // Add the struct data fields and methods, as per the tutorials and exercises, here...
        // ...
    public:
        Colour();
        Colour(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);

        uint8_t GetRed() const;
        void SetRed(uint8_t red);

        uint8_t GetGreen() const;
        void SetGreen(uint8_t green);

        uint8_t GetBlue() const;
        void SetBlue(uint8_t blue);

        uint8_t GetAlpha() const;
        void SetAlpha(uint8_t alpha);

        bool operator==(const Colour& other) const;
        bool operator!=(const Colour& other) const;

        uint32_t colour; 
    };
}