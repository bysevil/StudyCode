#include"Date.h"

int main() {
	Date d1(2023, 9, 10);
	std::cout << "Date d1: ";
	d1.print();

	Date d2 = d1;
	std::cout << "CopyDate d2: ";
	d2.print();

	d1 += 1000;
	std::cout << "+=1000 d1 : ";
	d1.print();

	std::cout << "d1 - d2 :" << d1 - d2 << std::endl;

	d2 = d1 + 2000;
	std::cout << "d1+2000 d2 : ";
	d2.print();

	d2 = d1 - 1000;
	std::cout << "d1-1000 d2 : ";
	d2.print();

	d1 -= 1000;
	std::cout << "d1-=1000 d1 : ";
	d1.print();

	d2 = d1++;
	std::cout << "d1++ d1 : " ;
	d1.print();
	std::cout << "d1++ d2 : ";
	d2.print();

	d2 = ++d1;
	std::cout << "++d1 d1 : ";
	d1.print();
	std::cout << "++d1 d2 : ";
	d2.print();

	d2 = d1--;
	std::cout << "d1-- d1 : ";
	d1.print();
	std::cout << "d1-- d2 : ";
	d2.print();

	d2 = --d1;
	std::cout << "--d1 d1 : ";
	d1.print();
	std::cout << "--d1 d2 : ";
	d2.print();

	bool d = d1 > d2;
	std::cout << "d1 > d2 ? " << d <<std::endl;
	d = d1 == d2;
	std::cout << "d1 == d2 ? " << d << std::endl;



	return 0;
}