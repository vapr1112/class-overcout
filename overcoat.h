#pragma once
#include <iostream>
#define SIZE 1000

using namespace std;

class overcoat
{
private:
	int price;//цена
	char* type;

public:

	overcoat() = default;

	overcoat(const int price_p, const char* type_p) : price{ price_p }, type {new char[strlen(type_p) + 1]}//главный конструктор
	{
		strcpy_s(type, strlen(type_p) + 1, type_p);
	}

	overcoat(const overcoat& clother) : price{ clother.price }, type{ new char[strlen(clother.type) + 1] }//конструктор копирования
	{
		strcpy_s(type, strlen(clother.type) + 1, clother.type);
	}

	//аксессоры и модификаторы
	void set_prise(const int prise_p)
	{
		price = prise_p;
	}

	void set_type(const char* type_p)
	{
		delete[] type;

		type = new char[strlen(type_p) + 1];

		strcpy_s(type, strlen(type_p) + 1, type_p);
	}

	int get_price()
	{
		return price;
	}

	char* get_type()
	{
		return type;
	}

	//перегрузки операторов
	friend bool operator==(const overcoat& clothes_1, const overcoat& clothes_2)
	{
		return strcmp(clothes_1.type, clothes_2.type) == 0 ? 1 : 0;
	}

	const overcoat operator=(const overcoat& clother)
	{
		if (&clother != this)
		{
			price = clother.price;

			delete[] type;

			type = new char[strlen(clother.type) + 1];

			strcpy_s(type, strlen(clother.type) + 1, clother.type);
		}

		return *this;
	}

	friend bool operator>(const overcoat& clothes_1, const overcoat& clothes_2)
	{
		return clothes_1.price > clothes_2.price ? 1 : 0;
	}

	~overcoat()//деструктор
	{
		delete[] type;
	}
};

