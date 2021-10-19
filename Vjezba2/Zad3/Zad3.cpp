#include <iostream>

struct Point {
	Point(const float x, const float y) : x(x), y(y) {}
	float x;
	float y;
};

struct Circle
{
	Circle(const float x, const float y, const float radius) : origin(x, y), radius(radius)	{}
	Point origin;
	float radius;
};

struct Rectangle
{
	Rectangle(const float x1, const float y1, const float x2, const float y2)
		: point1(x1, y1), point2(x2,y2)	{}

	Point point1;
	Point point2;
};

bool CheckOverlap(const Circle& circle, const Rectangle& rectangle)
{

	// Find the nearest point on the
	// rectangle to the center of
	// the circle
	const auto Xn = std::max(rectangle.point1.x, std::min(circle.origin.x, rectangle.point2.x));
	const auto Yn = std::max(rectangle.point1.y, std::min(circle.origin.y, rectangle.point2.y));

	// Find the distance between the
	// nearest point and the center
	// of the circle
	// Distance between 2 points,
	// (x1, y1) & (x2, y2) in
	// 2D Euclidean space is
	// ((x1-x2)**2 + (y1-y2)**2)**0.5
	const auto Dx = Xn - circle.origin.x;
	const auto Dy = Yn - circle.origin.y;
	return (Dx * Dx + Dy * Dy) <= circle.radius * circle.radius;
}

template<unsigned N>
size_t GetOverlapCount(const Circle& circle, const Rectangle (&rectangles)[N])
{
	size_t count = 0;
	auto size = sizeof rectangles / sizeof Rectangle;
	for(auto i = 0; i < size; i++)
		if (CheckOverlap(circle, rectangles[i])) count++;
	return count;
}

int main()
{
	Circle circle(0, 0, 2);
	Rectangle rectangles[] = { Rectangle(1,-1,3,1), Rectangle(3,0,5,3) };

	auto size = sizeof rectangles / sizeof Rectangle;

	std::cout << "Overlap count: " << GetOverlapCount<2>(circle, rectangles) << std::endl;
}