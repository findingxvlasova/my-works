#include <iostream>
#pragma warning(disable: 4996)
using namespace std;
class PhoneBook
{
	char* name;
	long long home_number;
	long long work_number;
	long long mobile_number;
	char* email;
	char* info;
public:

	PhoneBook()
	{
		char text_for_name[] = "New Contact";
		strcpy(name, text_for_name);
		home_number = 1111111;
		work_number = 111111111;
		mobile_number = 111111111;
		char eemail[] = "email@mail.com";
		strcpy(email, eemail);
		char infoo[] = "19 y.o. designer";
		strcpy(info, infoo);
		cout << "constructor\n";
	};
	PhoneBook(char* Name, long long home, long long work, long long mobile,char* Email, char* Info)
	{
		name = Name;
		home_number = home;
		work_number = work;
		mobile_number = mobile;
		email = Email;
		info = Info;
		cout << "constructor\n";
	};
	void show()
	{
		cout << "\nname: " << name;
		cout << "\nhome num: " << home_number;
		cout << "\nwork num: " << work_number;
		cout << "\nmobile num: " << mobile_number;
		cout << "\nemail: " << email;
		cout << "\ninfo: " << info;
	}


};
int main()
{
	char name[100], info[100], email[100];
	long long home, work, mobile;
	cout << "Enter name of the contact: "; cin.getline(name, 100);
	cout << "Enter howme number: "; cin >> home;
	cout << "Enter work number: "; cin >> work;
	cout << "Enter mobile number: "; cin >> mobile;
	cin.ignore();
	cout << "Enter email of the contact: "; cin.getline(email, 100);
	cin.ignore();
	cout << "Enter info about contact: "; cin.getline(info, 100);


	PhoneBook first_contact(name, home, work, mobile, email, info);
	first_contact.show();
}
