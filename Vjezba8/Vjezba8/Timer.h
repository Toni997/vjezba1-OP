#pragma once
#include <ostream>

class Timer
{
public:
	Timer() : m_H(0), m_M(0), m_S(0) {}
	Timer(int h, int m, double s) : m_H(h), m_M(m), m_S(s) {}

	friend std::ostream& operator<< (std::ostream& os, const Timer& timer);
	bool operator< (const Timer& timer);
	Timer& operator+= (const Timer& timer);
	Timer& operator+= (double seconds);
	Timer& operator-= (const Timer& timer);
	Timer& operator+ (const Timer& timer);
	Timer& operator- (const Timer& timer);
	double operator/ (double number);
	Timer& operator/= (double number);
	operator double() {	return ToHours(); }

private:
	void Optimize();
	double ToHours() const;
	void FromHours(double hours);

private:
	int m_H{};
	int m_M{};
	double m_S{};
};

