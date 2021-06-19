#include <iostream>
#include <time.h>
#pragma warning(disable:4996)

using namespace std;

void Pin(int pin[])
{
	for (int i = 0; i < 4 ; i++)
		pin[i] = rand() % 10;
	for (int i = 0; i < 4; i++)
		cout << "ur pin is " << pin[i];
}
	
void LitePass()
{
	char alphabeth[] = {'a', 'b', 'c','d', 'e', 'f', 'g', 'h','i', 'g', 'k', 'l', 'm','n', 'o', 'p', 'q', 'r', 's',
		't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'G', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
		'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '\0'};
	int a;
	a = 6 + rand() % 5;
	cout << "\nlength of ur password is " << a;
	char* lite_password = new char[a];
	lite_password[a] = '\0';
	for (int i = 0; lite_password[i] != '\0'; i++)
	{
		lite_password[i] = alphabeth[rand()% (strlen(alphabeth) - 1)];
	}
	cout << "\nur lite password is " << lite_password;
}

void HardPass()
{
	char alphabeth[] = { 'a', 'b', 'c','d', 'e', 'f', 'g', 'h','i', 'g', 'k', 'l', 'm','n', 'o', 'p', 'q', 'r', 's',
		't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'G', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
		'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '!','@','#','$' ,'%','^','&','*','(',')','+','/', '?', '|','.','\0' };
	int a;
	a = 8 + rand() % 5;
	cout << "\nlength of ur password is " << a;
	char* hard_password = new char[a];
	hard_password[a] = '\0';
	for (int i = 0; hard_password[i] != '\0'; i++)
	{
		hard_password[i] = alphabeth[rand() % (strlen(alphabeth) - 1)];
	}
	cout << "\nur lite password is " << hard_password;
}
	
int main()
{
	srand(time(NULL));
	int choice;
	cout << "What u want to generate?\n1 - pin code\n2 - lite password\n3 - hard password \n"; cin >> choice;

	switch (choice)
	{
	case 1:
		int pin[4];
		Pin(pin);
		break;
	case 2:
		LitePass();
		break;
	case 3:
		HardPass();
		break;
	default:
		break;
	}
}
