#pragma once

struct Point { double x, y; };

class Board
{
public:
	Board();
	Board(int rows, int columns, char border = 'o');
	Board(const Board& other);
	Board(Board&& other) noexcept;
	~Board();

	void DrawChar(const Point& p, char ch);
	void DrawUpLine(const Point& p, char ch);
	void DrawLine(const Point& p1, const Point& p2, char ch);
	void Display() const;

	int GetX() const { return m_rows; }
	int GetY() const { return m_columns; }

private:
	int m_rows{};
	int m_columns{};
	char m_border{};
	char** m_board = nullptr;

	bool IsPointInRange(const Point& p) const;
};

