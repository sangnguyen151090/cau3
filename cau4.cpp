#include <iostream>
#include <math.h>

using namespace std;

class Ptb1
{
protected:
	float b, c;
public:
	Ptb1(float m = 0, float n = 0);
	void Nhap(float x, float y);
	void Xuat();
	void Giai_B1();
};
// ========= Lop Phuong trinh bac 2 ========= //
class Ptb2 : public Ptb1
{
private:
	float a;
public:
	Ptb2(float m = 0, float n = 0, float o = 0);
	void Nhap(float x, float y, float z);
	void Xuat();
	void Giai_B2();
};
//======== Ham khoi tao phuong trinh bac 1 ========//
Ptb1::Ptb1(float m, float n)
{
	b = m;
	c = n;
}
//============= Ham nhap b, c ==============//
void Ptb1::Nhap(float x, float y)
{
	b = x;
	c = y;
}
//============= Ham xuat b, c ==============//
void Ptb1::Xuat()
{
	cout << "(" << b << ")x + (" << c << ") = 0" << endl;
}
//============= Ham Giai phuong trinh bac 1 ============//
void Ptb1::Giai_B1()
{
	if (b != 0)
		cout << "\n\nPhuong trinh co nhiem: x= " << (-c) / b << endl;
	else if (c == 0)
		cout << "\n\nPhuong trinh vo nghiem" << endl;
	else
		cout << "\n\nPhuong trinh co vo so nghiem" << endl;
}
//============= Ham khoi tao phuong trinh bac 2 ============//
Ptb2::Ptb2(float m, float n, float o) : Ptb1()
{
	a = m;
}
//============= Ham nhap a ==============//
void Ptb2::Nhap(float x, float y, float z)
{
	a = x;
	Ptb1::Nhap(y, z);
}
//============= Ham xuat phuong trinh bac 2 ==============//
void Ptb2::Xuat()
{
	if (a != 0)
		cout << "(" << a << ")x*x + (" << b << ")x + (" << c << ") = 0" << endl;
	else
		Ptb1::Xuat();
}
//============= Ham Giai phuong trinh bac 2 ============//
void Ptb2::Giai_B2()
{
	float delta;
	if (a != 0)
	{
		delta = b * b - 4 * a*c;
		cout << "\nDelta = " << delta << endl;
		if (delta < 0)
			cout << "\nPhuong trinh vo nghiem!" << endl;
		else if (delta == 0)
			cout << "\nPhuong trinh co nghiem x = " << (-b) / (2 * a) << endl;
		else
			cout << "\nPhuong trinh co 2 nghiem:\n\t x1 = " << ((-b) - (sqrt(delta))) / (2 * a) << " ;  x2 = " << ((-b) + (sqrt(delta))) / (2 * a) << endl;
	}
	else
		Ptb1::Giai_B1();
}

int main()
{
	Ptb2 x;
	float a, b, c;
	cout << "Nhap gia tri a, b, c: ";
	cin >> a;
	cin >> b;
	cin >> c;
	x.Nhap(a, b, c);
	cout << "Phuong trinh co dang: ";
	x.Xuat();
	x.Giai_B2();
	return 0;
}