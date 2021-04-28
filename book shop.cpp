#include <iostream>
#include <iomanip>
#include <time.h>
#include <string.h>
#include <Windows.h>
#pragma warning(disable:4996)

using namespace std;

//структура
struct book
{
    char author[100];
    char name[100];
    int isbn;
    float price;
    int num;
};

//добавление элемента
book* Add(book* list, int& size)
{
    if (size == 0)
        list = new book[size + 1];
    else
    {

        book* temp = new book[size + 1];
        for (int i = 0; i < size; i++)
            temp[i] = list[i];
        delete[] list;
        list = temp;
    }

    cout << "Enter author name: "; cin.getline(list[size].author, 100);
    cin.ignore();
    cout << "Enter book name: "; cin.getline(list[size].name, 100);
    cout << "Enter ISBN: "; cin >> list[size].isbn;
    cout << "Enter price: "; cin >> list[size].price;
    cout << "Enter number of these book: "; cin >> list[size].num;

    cin.ignore();
    size++;
    return list;
}

//удаление элемента
book* DeleteElement(book* list, int& size, int choice)
{
    if (choice == 1)
    {
        book* temp = new book[size - 1];
        for (int i = 0; i < size - 1; i++)
            temp[i] = list[i];
        delete[]list;
        list = temp;
        size--;
        return list;
    }
    else
    {
        int index;
        cout << "Enter the list number of the book you want to delete: "; cin >> index;

        size--;
        book* temp = new book[size];
        for (int i = 0; i < size; i++)
        {
            if (i < index)
                temp[i] = list[i];
            if (i == index)
                continue;
            if (i > index)
                temp[i] = list[i - 1];
        }
        delete[]list;
        list = temp;
        return list;
    }
}

void Sale(book* list, int size, int index, int nums)
{
    index--;
    for (int i = 0; i < size; i++)
    {
        if (i == index)
        {
            if (list[i].num > nums)
            {
                cout << "You have to pay: " << (float)list[i].price * nums;
                list[i].num -= nums;
            }
            else
            {
                cout << "Error!";
            }
        }
    }

}

void FindBook(book* list, int size, int choice)
{
    switch (choice)
    {
        //ISBN
    case 1:
        int ISBN;
        cout << "Enter ISBN of book: "; cin >> ISBN;
        for (int i = 0; i < size; i++)
        {
            if (ISBN == list[i].isbn)
            {
                cout << "#\tAuthor name\t\tBook name\tISBN\tPrice\tNumber of books\n";
                cout << i + 1 << "\t" << list[i].author << "\t\t" << list[i].name << "\t" << list[i].isbn << "\t" << list[i].price << "\t" << list[i].num << "\n";

            }
        }
        break;
        //author
    case 2:
        char author1[100];
        cin.ignore();
        cout << "Enter author name: "; cin.getline(author1, 100);
        cout << "#\tAuthor name\t\tBook name\tISBN\tPrice\tNumber of books\n";
        for (int i = 0; i < size; i++)
        {
            if (strcmp(list[i].author, author1) == 0)
            {

                cout << i + 1 << "\t" << list[i].author << "\t\t" << list[i].name << "\t" << list[i].isbn << "\t" << list[i].price << "\t" << list[i].num << "\n";
            }
        }
        break;
        //book name
    case 3:
        char namebook[100];
        cin.ignore();
        cout << "Enter book name: "; cin.getline(namebook, 100);
        cout << "#\tAuthor name\t\tBook name\tISBN\tPrice\tNumber of books\n";
        for (int i = 0; i < size; i++)
        {
            if (strcmp(list[i].name, namebook) == 0)
            {
                cout << i + 1 << "\t" << list[i].author << "\t\t" << list[i].name << "\t" << list[i].isbn << "\t" << list[i].price << "\t" << list[i].num << "\n";
            }
        }

        break;
    default:
        break;
    }
}


int FindBookJ(book* list, int size)
{
    int ISBN, j = 0;
    cout << "Enter ISBN of book: "; cin >> ISBN;

    for (int i = 0; i < size; i++)
    {
        if (ISBN == list[i].isbn)
            j = i;
    }
    return j;
}

void Edit(book* list, int size, int index)
{
    int choice;
    cout << "What do you want to edit?\n1 - author name\n2 - book name\n3 - price\n4 - ISBN\n5 - number of books\n0 - exit\n"; cin >> choice;
    switch (choice)
    {
    case 1:
    {
        char author1[100];
        cin.ignore();
        cout << "Enter author name: "; cin.getline(author1, 100);
        strcpy(list[index].author, author1);
        break;
    }
    case 2:
    {
        char bookname1[100];
        cin.ignore();
        cout << "Enter book name: "; cin.getline(bookname1, 100);
        strcpy(list[index].name, bookname1);
        break;
    }
    case 3:
    {
        float pricenew;
        cout << "Enter price: "; cin >> pricenew;
        list[index].price = pricenew;
        break;
    }
    case 4:
    {
        int ISBNnew;
        cout << "Enter ISBN: "; cin >> ISBNnew;
        list[index].isbn = ISBNnew;
        break;
    }
    case 5:
    {
        int numnew;
        cout << "Enter number of books: "; cin >> numnew;
        list[index].num = numnew;
        break;
    }
    default:
        break;
    }
}

//вывод на экран
void Show(book* list, int size)
{
    cout << "#\tAuthor name\t\tBook name\tISBN\tPrice\tNumber of books\n";

    for (int i = 0; i < size; i++)
    {
        if (list[i].num == 0)
            continue;
        else
            cout << i + 1 << "\t" << list[i].author << "\t\t" << list[i].name << "\t" << list[i].isbn << "\t" << list[i].price << "\t" << list[i].num << "\n";
    }
}

int main()
{
    srand(time(NULL));


    bool job = 1;
    book* list = 0;
    int size = 0, choice;
    while (job)
    {
        system("cls");
        Show(list, size);
        cout << "1 - add book\n2 - show existence books\n3 - sale\n4 - detete book\n5 - find book\n6 - edit books\n0 - exit\n\t\t"; cin >> choice;
        switch (choice)
        {
        case 1:
            cin.ignore();
            list = Add(list, size);
            break;
        case 2:
        {
            if (size == 0)
            {
                cout << "Empty!";
                Sleep(3000);
            }
            else
            {
                Show(list, size);
                Sleep(7000);
            }
            break;
        }
        case 3:
        {
            int index, nums;
            cout << "Enter # of book: "; cin >> index;
            cout << "Enter the number of books you want to buy: "; cin >> nums;
            Sale(list, size, index, nums);
            Sleep(5000);
            break;
        }
        case 4:
            if (size > 0)
            {
                cin.ignore();
                int which;
                cout << "1 - delete last book\n2 - delete book by number in list\n\t\t"; cin >> which;
                switch (which)
                {
                case 1:
                    list = DeleteElement(list, size, 1);
                    break;
                case 2:
                    list = DeleteElement(list, size, 2);
                    break;
                default:
                    break;
                }
            }
            else
            {
                cout << "\nEmpty list";
            }
            break;
        case 5:
        {
            if (size == 0)
            {
                cout << "Empty!";
                Sleep(3000);
            }
            else
            {
                int choice2;
                cout << "Hhow do you want to find the book?\n1 - by ISBN\n2 - by author\n3 - by name\n\t\t"; cin >> choice2;
                if (choice2 <= 0 || choice2 >= 4)
                {
                    cout << "Worng!";
                    Sleep(3000);
                }
                else
                {
                    FindBook(list, size, choice2);
                    Sleep(7000);
                }
            }
            break;
        }
        case 6:
        {
            int i;
            i = FindBookJ(list, size);
            Edit(list, size, i);
            break;
        }

        case 0:
            job = 0;
            break;
        default:
            break;
        }
    }
}

