#include <iostream>
#include <iomanip>
#include <time.h>
#include <string.h>
#include <Windows.h>
#include <fstream>
#pragma warning(disable:4996)

using namespace std;

struct phoneBook
{
	char* FIO;
	long phone_number;
	char* email;
};


/*

bool Checkemail(char* text)
{
	int checker = 0, isob, itoch;
	for (int i = 0; text[i] != '\0'; i++)
	{
		if (text[i] == '@')
		{
			isob = i;
			checker++;
		}
	}
	if (checker != 1)
	{
		return 0;
	}
	else
	{
		checker = 0;
		if (text[0] == '.')
		{
			checker = 2;
		}
		for (int i = 0; text[i] != '\0'; i++)
		{
			if (text[i] == '.' && i > isob + 1)
			{
				itoch = i;
				checker++;
			}
		}
		if (checker != 1)
		{
			return 0;
		}
		else
		{
			for (int i = 0; text[i] != '\0'; i++)
			{
				if (!isalnum(text[i]) && text[i] != '@' && text[i] != '.')
				{
					checker = 0;
				}
			}
			if (checker == 0)
			{
				return 0;
			}
			else
			{
				int count = 0;
				for (int i = 0; text[i] != '\0'; i++)
				{
					if (i > itoch && !isalpha(text[i]))
					{
						checker = 0;
					}
					else if (i > itoch && isalpha(text[i]))
					{
						count++;
					}
				}
				if (checker == 0 || count < 2)
				{
					return 0;
				}
				else
				{
					return 1;
				}
			}
		}
	}
}

*/
void Add(phoneBook*& arr, int& size)
{
	char data[100];
	bool check;
	phoneBook* temp = new phoneBook[size + 1];
	for (int i = 0; i < size; i++)
		temp[i] = arr[i];
	delete[] arr;
	arr = temp;


	cin.ignore();
	cout << "Enter name: "; cin.getline(data, 100);
	arr[size].FIO = new char[strlen(data) + 1];
	strcpy(arr[size].FIO, data);

	cout << "Enter phone nubmer (without +): "; cin >> arr[size].phone_number;

	cin.ignore();
	cout << "Enter email: "; cin.getline(data, 100);
	arr[size].email = new char[strlen(data) + 1];
	strcpy(arr[size].email, data);
	/*check = Checkemail(arr[size].FIO);
	while (check != 1)
	{
		cin.ignore();
		cout << "Enter email: "; cin.getline(data, 100);
		arr[size].email = new char[strlen(data) + 1];
		strcpy(arr[size].email, data);
		check = Checkemail(arr[size].FIO);
	}*/
	system("cls");
	size++;

}


void Delete(phoneBook*& arr, int& size)
{
	phoneBook* temp = new phoneBook[size - 1];
	int index;
	cout << "Enter number in list: "; cin >> index;
	index--;
	for (int i = 0; i < size - 1; i++)
	{
		if (i < index)
			temp[i] = arr[i];
		else if (i > index)
			temp[i - 1] = arr[i];
	}
	delete[] arr[index].FIO;
	delete[] arr[index].email;
	arr = temp;
	size--;
}

void Edit(phoneBook*& arr, int size)
{
	int index;
	int choice;
	char new_data[100];
	cout << "Waht u want to edit?\n 1 - name\n 2 - phone number\n 3 - email "; cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << "Enter index og contact that u want to edit: "; cin >> index;
		index--;
		cin.ignore();
		cout << "\nEnter name: "; cin.getline(new_data, 100);
		arr[index].FIO = new char[strlen(new_data) + 1];
		strcpy(arr[index].FIO, new_data);
		system("CLS");
		break;
	}
	case 2:
	{
		cout << "Enter index og contact that u want to edit: "; cin >> index;
		index--;
		cout << "\nEnter phone number: "; cin >> arr[index].phone_number;
		system("CLS");
		break;
	}
	case 3:
	{
		cout << "Enter index og contact that u want to edit: "; cin >> index;
		index--;
		cin.ignore();
		cout << "\nEnter email: "; cin.getline(new_data, 100);
		arr[index].email = new char[strlen(new_data) + 1];
		strcpy(arr[index].email, new_data);
		system("CLS");
		break;
	}
	default:	break;
	}
}


void Read(phoneBook*& arr, int& size)
{
	char buff[200];
	ifstream book("phone_book.txt");

	if (!book.is_open())
		cout << "File not open\n";
	else
	{
		while (!book.eof())
		{
			book.getline(buff, 200);
			size++;
		}
		book.close();
		size--;
		arr = new phoneBook[size];
		char* text;
		book.open("phone_book.txt");
		for (int i = 0; i < size; i++)
		{
			book.getline(buff, 200);
			text = strtok(buff, "|");
			arr[i].FIO = new char[strlen(text + 1)];
			strcpy(arr[i].FIO, text);

			arr[i].phone_number = atol(strtok(NULL, "|"));


			text = strtok(NULL, "|");
			arr[i].email = new char[strlen(text + 1)];
			strcpy(arr[i].email, text);
		}
		book.close();
	}
}


void Write(phoneBook*& arr, int& size)
{
	ofstream book("phone_book.txt");

	for (int i = 0; i < size; i++)
		book << arr[i].FIO << "|" << arr[i].phone_number << "|" << arr[i].email << "|\n";
	book.close();

}


void Search(phoneBook* arr, int size)
{
	int choice;
	bool check = 0;
	char temp[100];
	float data;
	cout << "\nFind by:\n1 - name\n2 - phone number\n3 - email\n"; cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cin.ignore();
		cout << "\nEnter name: "; cin.getline(temp, 100);
		for (int i = 0; i < size; i++)
		{
			if (!strcmp(arr[i].FIO, temp))
			{
				check = 1;
				cout << "\n" << i + 1 << "\t" << arr[i].FIO << "\t" << arr[i].phone_number << "\t" << arr[i].email;
			}
		}
		if (!check)
			cout << "\nNone was found";
		break;
	}
	case 2:
	{
		cout << "\nEnter phone number: "; cin >> data;
		for (int i = 0; i < size; i++)
		{
			if (arr[i].phone_number == data)
			{
				strcpy(temp, arr[i].FIO);
				check = 1;
				cout << "\n" << i + 1 << "\t" << arr[i].FIO << "\t" << arr[i].phone_number << "\t" << arr[i].email;
			}
		}
		if (!check)
			cout << "\nNone was found";
		break;
	}
	case 3:
	{
		cout << "\nEnter email: "; cin.getline(temp, 100);
		for (int i = 0; i < size; i++)
		{
			if (arr[i].email == temp)
			{

				check = 1;
				cout << "\n" << i + 1 << "\t" << arr[i].FIO << "\t" << arr[i].phone_number << "\t" << arr[i].email;
			}
		}
		if (!check)
			cout << "\nNone was found";
		break;
	}
	default:
		cout << "\nWrong choice";
		break;
	}
}



/*
void Sort(phoneBook*& arr, int size)
{
	int choice, check = 0;
	char temp[100]; char temp2[100];
	cout << "\nEnter your choice\n1 - Sort name in alphabet order\n2 - Sort name against alphabeth order\n0 - Exit\n"; cin >> choice;
	switch (choice)
	{
	case 1:
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - 1; j++)
			{
				strcpy(temp, arr[j].FIO);
				strcpy(temp2, arr[j + 1].FIO);
				strcpy(temp, strtok(temp, " "));
				strcpy(temp2, strtok(temp2, " "));
				if (strlen(temp) > strlen(temp2))
				{
					check = 0;
					for (int a = 0; a < strlen(temp2); a++)
					{
						if (arr[j].FIO[a] > arr[j + 1].FIO[a])
						{
							swap(arr[j], arr[j + 1]);
							check = 1;
							break;
						}
						else if (arr[j].FIO[a] == arr[j + 1].FIO[a])
						{
							check++;
						}
						else
						{
							break;
						}
					}
					if (check == strlen(temp2))
					{
						swap(arr[j], arr[j + 1]);
					}
				}
				else if (strlen(temp) < strlen(temp2))
				{
					check = 0;
					for (int a = 0; a < strlen(temp); a++)
					{
						if (arr[j].FIO[a] > arr[j + 1].FIO[a])
						{
							swap(arr[j], arr[j + 1]);
							check = 1;
							break;
						}
						else if (arr[j].FIO[a] == arr[j + 1].FIO[a])
							check++;
						else
							break;
					}
					if (check == strlen(temp))
						swap(arr[j], arr[j + 1]);
				}
				else
				{
					for (int a = 0; a < strlen(temp); a++)
					{
						if (arr[j].FIO[a] > arr[j + 1].FIO[a])
						{
							swap(arr[j], arr[j + 1]);
							break;
						}
					}
				}
			}
		}
		break;
	}
	case 2:
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - 1; j++)
			{
				strcpy(temp, arr[j].FIO);
				strcpy(temp2, arr[j + 1].FIO);
				strcpy(temp, strtok(temp, " "));
				strcpy(temp2, strtok(temp2, " "));
				if (strlen(temp) > strlen(temp2))
				{
					check = 0;
					for (int a = 0; a < strlen(temp2); a++)
					{
						if (arr[j].FIO[a] < arr[j + 1].FIO[a])
						{
							swap(arr[j], arr[j + 1]);
							check = 1;
							break;
						}
						else if (arr[j].FIO[a] == arr[j + 1].FIO[a])
							check++;
						else
							break;
					}
					if (check == strlen(temp2))
						swap(arr[j], arr[j + 1]);
				}
				else if (strlen(temp) < strlen(temp2))
				{
					check = 0;
					for (int a = 0; a < strlen(temp); a++)
					{
						if (arr[j].FIO[a] < arr[j + 1].FIO[a])
						{
							swap(arr[j], arr[j + 1]);
							check = 1;
							break;
						}
						else if (arr[j].FIO[a] == arr[j + 1].FIO[a])
							check++;
						else
							break;
					}
					if (check == strlen(temp))
						swap(arr[j], arr[j + 1]);
				}
				else
				{
					for (int a = 0; a < strlen(temp); a++)
					{
						if (arr[j].FIO[a] < arr[j + 1].FIO[a])
						{
							swap(arr[j], arr[j + 1]);
							break;
						}
					}
				}
			}
		}
		break;
	}
	default:
		system("CLS");
		cout << "\nWrong choice";
		break;
	}
}*/



void Show(phoneBook* arr, int size)
{
	cout << "\n#\tname	\t\tphone number\t\t	e-mail\n";
	for (int i = 0; i < size; i++)
		cout << i + 1 << "\t" << arr[i].FIO << "\t\t+(code)" << arr[i].phone_number << "\t\t" << arr[i].email << "\n";
}


int main()
{
	int size = 0;
	phoneBook* list = new phoneBook[size];

	int choice;
	bool job = 1;
	while (job)
	{
		system("cls");
		if (size > 0)
			Show(list, size);
		cout << "Enter:\n 1 - add  contact\n 2 - delete contact\n  4 - edit contact\n 5 - search contact\n 6 - take contacts from file\n 7 - write contacts to file \n 8 - show\n 0 - exit\n"; cin >> choice;
		switch (choice)
		{
		case 1: Add(list, size); break;
		case 2: Delete(list, size); break;
		case 3: Edit(list, size); break;
		case 4:
			Search(list, size);
			Sleep(3000);
			break;
		case 5: Read(list, size); break;
		case 6: Write(list, size); break;
		case 7:
			if (size > 0)
				cout << "List is empty!!!";
			Sleep(3000);
			break;
		case 0: job = 0; break;
		default:
			break;
		}
	}
}



