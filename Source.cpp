#include "overcoat.h"

int main()
{
	setlocale(LC_ALL, "rus");

	int price, user;

	char type[SIZE];

	overcoat clother_1, clother_2;

	enum menu {CMP_TUPE = 1, COPY, CMP_PRICE};

	cout << "������� ��� � ���� ������ ������ � ������ ������\n";
	
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
		cout << "\n������� \n1 �������� ��� \n2 ��������� ������ ����� ������ ������ \n3 �������� ����\n";

		cin >> user;

		switch (user)
		{
		case CMP_TUPE:
			clother_1 == clother_2 ? cout << "\n ��� ������ �����\n" : cout << "\n��� ������ �� �����\n";
			break;
		case COPY:
			clother_2 = clother_1;
			printf("\n���� � ��� ������ ������ \n%d", clother_2.get_price());
			printf("\n%s", clother_2.get_type());
			break;
		case CMP_PRICE:
			clother_1 > clother_2 ? cout << "\n ���� ������ ������ ������\n" : cout << "\n���� ������ ������ ������\n";
			break;
		default:
			break;
		}
	} while (user != 0);

	return 0;
}