#include <iostream>

struct Point {
	Point(const float x, const float y) : x(x), y(y) {}
	float x;
	float y;
};

struct Circle
{
	Circle(const Point origin, const float radius) : origin(origin), radius(radius)	{}
	Point origin;
	float radius;
};

struct Rectangle
{
	Rectangle(const Point& point1, const Point& point2)
		: point1(point1), point2(point2) {}

	Point point1;
	Point point2;
};

bool CheckOverlap(const Circle& circle, const Rectangle& rectangle)
{
	// Find the nearest point on the
	// rectangle to the center of
	// the circle
	const auto xn = std::max(rectangle.point1.x, std::min(circle.origin.x, rectangle.point2.x));
	const auto yn = std::max(rectangle.point1.y, std::min(circle.origin.y, rectangle.point2.y));

	// Find the distance between the
	// nearest point and the center
	// of the circle
	// Distance between 2 points,
	// (x1, y1) & (x2, y2) in
	// 2D Euclidean space is
	// ((x1-x2)**2 + (y1-y2)**2)**0.5
	const auto dx = xn - circle.origin.x;
	const auto dy = yn - circle.origin.y;
	return (dx * dx + dy * dy) <= circle.radius * circle.radius;
}

template<size_t N>
size_t GetOverlapCount(const Circle& circle, const Rectangle (&rectangles)[N])
{
	size_t count = 0;
	for(size_t i = 0; i < N; i++)
		if (CheckOverlap(circle, rectangles[i])) count++;
	return count;
}

int main()
{
	const Circle circle({ 0, 0 }, 2);
	Rectangle rectangles[] = { Rectangle({1,-1},{3,1}), Rectangle({3,0},{5,3}) };

	std::cout << "Overlap count: " << GetOverlapCount<2>(circle, rectangles) << std::endl;
}