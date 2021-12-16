#include "Timer.h"

void Timer::Optimize()
{
	while (m_S >= 60)
	{
		m_M++;
		m_S -= 60;
	}

	while (m_M >= 60)
	{
		m_H++;
		m_M -= 60;
	}

	while (m_H < 0)
	{
		m_H = 0;
		m_M = 0;
		m_S = 0;
	}

	while (m_M < 0)
	{
		m_H--;
		m_M += 60;
	}

	while (m_S < 0)
	{
		m_M--;
		m_S += 60;
	}
}

double Timer::ToHours() const
{
	return (double)m_H + (double)m_M / 60 + m_S / 60 / 60;
}

void Timer::FromHours(double hours)
{
	m_H = 0;
	m_M = 0;
	m_S = 0;

	while (hours > 1)
	{
		m_H++;
		hours--;
	}

	hours *= 60;
	while (hours > 1)
	{
		m_M++;
		hours--;
	}

	hours *= 60;
	while (hours > 1)
	{
		m_S++;
		hours--;
	}

	m_S += hours;
}

std::ostream& operator<< (std::ostream& os, const Timer& timer)
{
	os << timer.m_H << ":" << timer.m_M << ":" << timer.m_S;
	return os;
}

bool Timer::operator< (const Timer& timer)
{
	double hoursTimer1 = ToHours();
	double hoursTimer2 = timer.ToHours();

	return hoursTimer1 < hoursTimer2;
}

Timer& Timer::operator+= (const Timer& timer)
{
	m_H = m_H + timer.m_H;
	m_M = m_M + timer.m_M;
	m_S = m_S + timer.m_S;

	Optimize();

	return *this;
}

Timer& Timer::operator+= (double seconds)
{
	m_S += seconds;

	Optimize();

	return *this;
}

Timer& Timer::operator-= (const Timer& timer)
{
	m_H = m_H - timer.m_H;
	m_M = m_M - timer.m_M;
	m_S = m_S - timer.m_S;

	Optimize();

	return *this;
}

Timer& Timer::operator+ (const Timer& timer)
{
	m_H = m_H + timer.m_H;
	m_M = m_M + timer.m_M;
	m_S = m_S + timer.m_S;

	Optimize();

	return *this;
}

Timer& Timer::operator- (const Timer& timer)
{
	m_H = m_H - timer.m_H;
	m_M = m_M - timer.m_M;
	m_S = m_S - timer.m_S;

	Optimize();

	return *this;
}

double Timer::operator/ (double number)
{
	return ToHours() / number;
}

Timer& Timer::operator/= (double number)
{
	double toHours = ToHours();
	toHours /= number;
	FromHours(toHours);

	return *this;
}
