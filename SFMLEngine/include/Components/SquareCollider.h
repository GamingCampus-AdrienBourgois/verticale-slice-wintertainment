#pragma once

#include "Component.h"

class SquareCollider : public Component
{
public:
	SquareCollider() = default;
	~SquareCollider() override = default;

	float width = 1.0f;
	float height = 1.0f;
	float x;
	float y;

	float GetWidth() const { return width; }
	float GetHeight() const { return height; }
	float GetX() const { return x; }
	float GetY() const { return y; }

	void SetWidth(const float _width) { width = _width; }
	void SetHeight(const float _height) { height = _height; }
	void SetX(const float _x) { x = _x; }
	void SetY(const float _y) { y = _y; }

	static bool IsColliding(const SquareCollider& _collider_a, const SquareCollider& _collider_b);
};
