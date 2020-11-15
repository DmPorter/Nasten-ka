#include <iostream>
#include "SetOfChar.h"
#include "dialog.h"

#define OPTS_NUM 11

typedef void (*opt_t)(cs::SetOfChar&);

static const opt_t OPTS[OPTS_NUM] =
{
	dialogconstructor0,
	dialogconstructor1,
	dialogconstructor2,
	dialoginput,
	dialogoutput,
	dialogsetUnion,
	dialogadd,
	dialogintersection,
	dialogdiffer,
	dialogcontains,
	dialogmakeSet

};

void menu()
{


}

void dialog(cs::SetOfChar& table)
{
	while (true) {
		menu();

		int choice = 0;
		getn(choice);
		std::cout << std::endl;

		if (!choice)
			break;

		else if (choice < 0 || choice > OPTS_NUM)
			std::cout << "[WARNING] Wrong option" << std::endl << std::endl;

		else
			OPTS[choice - 1](table);
	}
}

void dialogconstructor0(cs::SetOfChar& t) {
	cs::SetOfChar a;
	std::cin >> a;
	t = a;
}

void dialogconstructor1(cs::SetOfChar& t) {
	std::cout << " write power" << std::endl;
	int N;
	getn(N);
	try
	{
		cs::SetOfChar a(N);
		t = a;
	}
	catch (const std::exception&)
	{
		//выведи что-то
	}
}

void dialogconstructor2(cs::SetOfChar& t) {
	std::cout << " write string of symbols" << std::endl;
	char str[100];
	std::cin.getline(str, 99);
	cs::SetOfChar a(str);
	t = a;

}

void dialoginput(cs::SetOfChar& t) {
	cs::SetOfChar a;
	std::cin >> a;
	t = a;
}

void dialogoutput(cs::SetOfChar& t) {
	if (t.getCurrentPower() != 0)
	{
		std::cout << t;
	}
	else
	{
		std::cout << " error " << std::endl;
	}

}

void dialogsetUnion(cs::SetOfChar& t) {
	//if (t.getCurrentPower() != 0)
	//{
	//	std::cout << " Select the second term " << std::endl;
	//	int r;
	//	getn(r);
	//	if (r >= 0 && r < 12)
	//	{
	//		if (q[r] != nullptr) {
	//			t = t + q;
	//		}
	//		else {
	//			cs::SetOfChar a;
	//			q[r] = &a;
	//			t->setUnion(*t);
	//		}
	//	}
	//	else {
	//		std::cout << " error " << std::endl;
	//	}
	//}
	//else
	//{
	//	std::cout << " error " << std::endl;
	//}
}

void dialogadd(cs::SetOfChar& t) {
	if (t.getCurrentPower() != 0)
	{
		char c;
		std::cin.get(c);
		try
		{
			t += c;
		}
		catch (const std::exception & exception)
		{
			std::cout << exception.what() << std::endl;
		}
	}
	else
	{
		std::cout << " error " << std::endl;
	}
}

void dialogintersection(cs::SetOfChar& t) {
	if (t.getCurrentPower() != 0)
	{
		char d[100];
		std::cout << " Write string, pls" << std::endl;
		std::cin.getline(d, 100);
		cs::SetOfChar f(d);
		t = t * f;
	}
	else
	{
		std::cout << " error " << std::endl;
	}
}

void dialogdiffer(cs::SetOfChar& t) {
	if (t.getCurrentPower() != 0)
	{
		char h[100];
		std::cout << " Write string, pls" << std::endl;
		std::cin.getline(h, 100);
		cs::SetOfChar y(h);
		t = t - y;
	}
	else
	{
		std::cout << " error " << std::endl;
	}
}

void dialogcontains(cs::SetOfChar& t) {
	if (t.getCurrentPower() != 0)
	{
		char s;
		std::cout << " Write a symbol, pls" << std::endl;
		std::cin.get(s);
		bool p;
		p = t.contains(s);
		std::cout << p << std::endl;
	}
	else
	{
		std::cout << " error " << std::endl;
	}
}

void dialogmakeSet(cs::SetOfChar& t) {
	if (t.getCurrentPower() != 0)
	{
		char x[100];
		std::cout << " Write a string, pls" << std::endl;
		std::cin.getline(x, 100);
		t.makeSet(x);
	}
	else
	{
		std::cout << " error " << std::endl;
	}
}