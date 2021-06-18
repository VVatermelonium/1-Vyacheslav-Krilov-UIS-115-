#pragma once
#include <iostream>

using namespace std;

class Pair
{
private:
	int* a;
	int* b;
public:
	// ����������� ��-���������
	Pair();
	// ����������� � �����������
	Pair(const int, const int);
	// ����������� �����������
	Pair(Pair&&) noexcept;
	// ����������� �����������
	Pair(const Pair&);
	// ������������ ������������
	Pair& operator= (Pair&& src);
	// ����������
	~Pair();
	// ����� ��������� a
	int get_a() const;
	// ����� ��������� b
	int get_b() const;
	// ��������� ������ a
	int* get_ptr_a() const;
	// ��������� ������ b
	int* get_ptr_b() const;
	// ����� ��������� a
	void set_a(int);
	// ����� ��������� b
	void set_b(int);
	// ����� ��������� ������ a
	void set_ptr_a(int*);
	// ����� ��������� ������ b
	void set_ptr_b(int*);
	// �������� �������� �� ���������
	bool operator== (const Pair&) const;
	// �������� ������������ ����� Pair(ac, bd)
	friend Pair operator* (Pair, Pair);
	// ����� �����������
	friend ostream& operator<< (ostream& out, const Pair&);
	// �������� ��������� ��� �� �������(�, b) - (�, d) = (� - b, � - d)
	friend Pair operator- (Pair, Pair);
};