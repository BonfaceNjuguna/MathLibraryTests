#include "MathHeaders/Colour.h"
#include <cstdint>

namespace MathClasses {
	Colour::Colour() : colour(0xff) {}

	Colour::Colour(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) {
		SetRed(red);
		SetGreen(green);
		SetBlue(blue);
		SetAlpha(alpha);
	}

	uint8_t Colour::GetRed() const {
		return static_cast<uint8_t>((colour & 0xff000000) >> 24);
	}

	void Colour::SetRed(uint8_t red) {
		colour = (colour & 0x00ffffff) | (static_cast<uint32_t>(red) << 24);
	}

	uint8_t Colour::GetGreen() const {
		return static_cast<uint8_t>((colour & 0x00ff0000) >> 16);
	}

	void Colour::SetGreen(uint8_t green) {
		colour = (colour & 0xff00ffff) | (static_cast<uint32_t>(green) << 16);
	}

	uint8_t Colour::GetBlue() const {
		return static_cast<uint8_t>((colour & 0x0000ff00) >> 8);
	}

	void Colour::SetBlue(uint8_t blue) {
		colour = (colour & 0xffff00ff) | (static_cast<uint32_t>(blue) << 8);
	}

	uint8_t Colour::GetAlpha() const {
		return static_cast<uint8_t>(colour & 0x000000ff);
	}

	void Colour::SetAlpha(uint8_t alpha) {
		colour = (colour & 0xffffff00) | static_cast<uint32_t>(alpha);
	}

	bool Colour::operator==(const Colour& other) const {
		return colour == other.colour;
	}

	bool Colour::operator!=(const Colour& other) const {
		return colour != other.colour;
	}
}