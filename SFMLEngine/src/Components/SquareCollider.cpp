#include "Components/SquareCollider.h"

#include "GameObject.h"
#include "Maths/Vector2.h"

bool SquareCollider::IsColliding(const SquareCollider& _collider_a, const SquareCollider& _collider_b)
{
	const Maths::Vector2f position_a = _collider_a.GetOwner()->GetPosition();
	const Maths::Vector2f position_b = _collider_b.GetOwner()->GetPosition();
	return position_a.x - _collider_a.GetX() < position_b.x - _collider_b.GetX() + _collider_b.GetWidth() && position_a.x - _collider_a.GetX() + _collider_a.GetWidth() > position_b.x - _collider_b.GetX() && position_a.y - _collider_a.GetY() < position_b.y - _collider_b.GetY() + _collider_b.GetHeight() && position_a.y - _collider_a.GetY() + _collider_a.GetHeight() > position_b.y - _collider_b.GetY();
}
