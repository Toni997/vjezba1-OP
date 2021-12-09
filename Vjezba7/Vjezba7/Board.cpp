#include <algorithm>
#include <stdexcept>
#include "Board.h"

Board::Board() : Board(10, 20) {}

Board::Board(int rows, int columns, char border) : m_rows(rows), m_columns(columns), m_border(border)
{
	m_board = new char*[m_rows];
	for (int i = 0; i < m_rows; i++)
	{
		m_board[i] = new char[m_columns];
	}

	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_columns; j++)
		{
			if (i == 0 || i == m_rows - 1 || j == 0 || j == m_columns - 1)
			{
				m_board[i][j] = m_border;
			}
			else
			{
				m_board[i][j] = ' ';
			}
		}
	}
}

Board::Board(const Board& other) :
	m_rows(other.m_rows), m_columns(other.m_columns),
	m_border(other.m_border)
{
	m_board = new char*[m_rows];
	for (int i = 0; i < m_rows; i++)
	{
		m_board[i] = new char[m_columns];
	}

	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_columns; j++)
		{
			m_board[i][j] = other.m_board[i][j];
		}
	}
}

Board::Board(Board&& other) noexcept :
	m_rows(other.m_rows), m_columns(other.m_columns),
	m_border(other.m_border), m_board(other.m_board)
{
	other.m_board = nullptr;
	other.m_rows = 0;
	other.m_columns = 0;
}

Board::~Board()
{
	for (int i = 0; i < m_rows; i++)
	{
		delete[] m_board[i];
	}

	delete[] m_board;
}

bool Board::IsPointInRange(const Point& p) const
{
	if (p.x <= 0 || (int)p.x >= (m_rows - 1) ||
		p.y <= 0 || (int)p.y >= (m_columns - 1))
	{
		return false;
	}

	return true;
}

void Board::Display() const
{
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_columns; j++)
		{
			printf("%c", m_board[i][j]);
		}
		printf("\n");
	}
}

void Board::DrawChar(const Point& p, char ch)
{
	if (!IsPointInRange(p))
	{
		throw std::out_of_range(
			std::string("(" + std::string(__func__) + ") Point not in valid range!"
		));
	}

	m_board[(int)round(p.x)][(int)round(p.y)] = ch;
}

void Board::DrawUpLine(const Point& p, char ch)
{
	if (!IsPointInRange(p))
	{
		throw std::out_of_range(
			std::string("(" + std::string(__func__) + ") Point not in valid range!"
			));
	}

	for (int x = (int)p.x, y = (int)round(p.y); x >= 1; x--)
	{
		m_board[x][y] = ch;
	}
}

void Board::DrawLine(const Point& p1, const Point& p2, char ch)
{
	if (!IsPointInRange(p1) || !IsPointInRange(p2))
	{
		throw std::out_of_range(
			std::string("(" + std::string(__func__) + ") One of the points not in valid range!"
			));
	}

	int stepsX = p1.x - p2.x;
	int stepsY = p1.y - p2.y;

	int stepsNeeded = abs(stepsX) > abs(stepsY) ? abs(stepsX) : abs(stepsY);
	
	double toSubtractEachStepX = (double)stepsX / (double)stepsNeeded;
	double toSubtractEachStepY = (double)stepsY / (double)stepsNeeded;
	
	for (double i = 0, x = p1.x, y = p1.y;
		i < (double)stepsNeeded + 1;
		i++, x -= toSubtractEachStepX, y -= toSubtractEachStepY)
	{
		m_board[(int)round(x)][(int)round(y)] = ch;
	}
}