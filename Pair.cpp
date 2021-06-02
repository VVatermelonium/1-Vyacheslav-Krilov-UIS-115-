#include "Pair.h"

Pair::Pair()
{
#if DEBUG
	cout << "==> Pair::Pair()" << endl;
#endif
	a = new int(0);
	b = new int(0);
}

Pair::Pair(int a, int b)
{
#if DEBUG
	cout << "==> Pair::Pair(int a, int b)" << endl;
#endif
	this->a = new int(a);
	this->b = new int(b);
}

Pair::Pair(Pair&& src) noexcept
{
#if DEBUG
	cout << "==> Pair::Pair(Pair&& src) noexcept" << endl;
#endif
	this->a = src.get_ptr_a();
	this->b = src.get_ptr_b();
	src.set_ptr_a(nullptr);
	src.set_ptr_b(nullptr);
}

Pair::Pair(const Pair& src)
{
#if DEBUG
	cout << "==> Pair::Pair(Pair& src)" << endl;
#endif
	a = new int(src.get_a());
	b = new int(src.get_b());
}

Pair::~Pair()
{
#if DEBUG
	cout << "==> Pair::~Pair()" << endl;
#endif
	delete this->a;
	delete this->b;
}

int Pair::get_a() const
{
	return *this->a;
}

int Pair::get_b() const
{
	return *this->b;
}

int* Pair::get_ptr_a() const
{
	return this->a;
}

int* Pair::get_ptr_b() const
{
	return this->b;
}

void Pair::set_a(int a)
{
	*this->a = a;
}

void Pair::set_b(int b)
{
	*this->b = b;
}

void Pair::set_ptr_a(int* ptr)
{
	this->a = ptr;
}

void Pair::set_ptr_b(int* ptr)
{
	this->b = ptr;
}

ostream& operator<< (ostream& out, const Pair& p) {
	out << "(a: " << p.get_a() << ", b: " << p.get_b() << ")";
#if DEBUG
	out << ", јдреса (a: " << p.get_ptr_a() << ", b: " << p.get_ptr_b() << ")";
#endif
	return out;
}

Pair operator- (Pair x, Pair y) {
	return Pair(x.get_a() - x.get_b(), y.get_a() - y.get_b());
}

Pair& Pair::operator=(Pair&& src) {
#if DEBUG
	cout << "==> Pair& operator = (Pair&& src) noexcept" << endl;
#endif
	this->a = src.get_ptr_a();
	this->b = src.get_ptr_b();
	src.set_ptr_a(nullptr);
	src.set_ptr_b(nullptr);
	return *this;
}

bool Pair::operator==(const Pair& src) const {
	return ((*a == src.get_a()) && (*b == src.get_b()));
}

Pair operator*(Pair first, Pair second) {
	return Pair(first.get_a() * second.get_b(), first.get_b() * second.get_b());
}