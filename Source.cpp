#include "overcoat.h"

int main()
{
	setlocale(LC_ALL, "rus");

	int price, user;

	char type[SIZE];

	overcoat clother_1, clother_2;

	enum menu {CMP_TUPE = 1, COPY, CMP_PRICE};

	cout << "введите тип и цену первой одежды и второй одежды\n";
	
	gets_s(type);
	cin >> price;

	cin.ignore();

	clother_1.set_prise(price);
	clother_1.set_type(type);

	gets_s(type);
	cin >> price;

	clother_2.set_prise(price);
	clother_2.set_type(type);

	do
	{
		cout << "\nвведите \n1 сравнить тип \n2 присвоить данные одной одежды другой \n3 сравнить цену\n";

		cin >> user;

		switch (user)
		{
		case CMP_TUPE:
			clother_1 == clother_2 ? cout << "\n тип одежды равен\n" : cout << "\nтип одежды не равен\n";
			break;
		case COPY:
			clother_2 = clother_1;
			printf("\nцена и тип второй одежды \n%d", clother_2.get_price());
			printf("\n%s", clother_2.get_type());
			break;
		case CMP_PRICE:
			clother_1 > clother_2 ? cout << "\n цена первой одежды больше\n" : cout << "\nцена второй одежды больше\n";
			break;
		default:
			break;
		}
	} while (user != 0);

	return 0;
}