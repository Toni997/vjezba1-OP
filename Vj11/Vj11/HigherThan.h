#pragma once

class HigherThan {
	int m_limit;

public:
	HigherThan(int limit) : m_limit(limit) {}
	bool operator()(int n) { return n > m_limit; }
};