#pragma once

class LowerThan {
	int m_limit;

public:
	LowerThan(int limit) : m_limit(limit) {}
	bool operator()(int n) { return n < m_limit; }
};