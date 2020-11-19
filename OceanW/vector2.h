#pragma once

struct Vector2
{
	int x, y;

	Vector2(int x = 0, int y = 0):
		x(x), y(y)
	{ }

	bool operator==(const Vector2& r)
	{
		return x == r.x
			&& y == r.y;
	}
};