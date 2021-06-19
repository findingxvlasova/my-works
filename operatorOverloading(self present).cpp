#include <iostream>
#include <fstream>
#include <ostream>
#include<Windows.h>
#pragma warning (disable:4996)

using namespace std;

class greatSpeaker
{
public:
	void presentYourself(ostream& os)
	{
		os << goodEveninger;
	}
private:
	template<class whateverUWant>
	friend void selfPresentation(whateverUWant obj);
	string goodEveninger = "Good evening! My name is John Smith and I am here to let you know what happens when you do your programming homework on every day basis - you work for Amazon, Google and Apple\n";
	
};

class regularPerson
{
public:
	void presentYourself(ostream& os)
	{
		os << hier;
	}
private:
	template<class whateverUWant>
	friend void selfPresentation(whateverUWant obj);
	string hier = "Hi, my name is John. I work for Amazon\n";
};

class shyGuy
{
public:
	void presentYourself(ostream& os)
	{
		os << shyHier;
	}
	
private:
	template<class whateverUWant>
	friend void selfPresentation(whateverUWant obj);
	string shyHier = "Hi\n";
};

template<class whateverUWant>
void selfPresentation(whateverUWant obj)
{
	cout << "\nused type is: " << (typeid(obj).name());
	cout << "\npresenting value: "<< obj << "\n";
}
template<>
void selfPresentation(greatSpeaker obj)
{
	cout << "\nused type is: " << (typeid(obj).name());
	cout << "\npresenting value: " << obj.goodEveninger << "\n";
}
template<>
void selfPresentation(regularPerson obj)
{
	cout << "\nused type is: " << (typeid(obj).name());
	cout << "\npresenting value: " << obj.hier << "\n";
}
template<>
void selfPresentation(shyGuy obj)
{
	cout << "\nused type is: " << (typeid(obj).name());
	cout << "\npresenting value: " << obj.shyHier << "\n";
}




int main()
{
	greatSpeaker name90;
	name90.presentYourself(cout);
	
	regularPerson name95;
	name95.presentYourself(cout);
	shyGuy name98;
	name98.presentYourself(cout);
	

	cout << "\nint try: ";
	selfPresentation(23);
	cout << "\ndouble try: ";
	selfPresentation(23.3);
	cout << "\nchar try: ";
	selfPresentation("A");
	cout << "\nbool try: ";
	selfPresentation(false);

	selfPresentation(name90);
	selfPresentation(name95);
	selfPresentation(name98);






}







Шаблоны
#include <iostream>
using namespace std;

template<class T>
class X
{
public:
    X(T* ptr)
    {
        obj = ptr;
    }

    T& getObj()
    {
        return *obj;
    }

    void setObj(T* ptr)
    {
        obj = ptr;
    }
    void insert(T object, int idx)
    {
        obj[idx] = object;
    }
private:
    T* obj;
};

class A
{

};

int main()
{
 
    int* arr = new int[10];
    X<int> i_obj(arr);

    X<double> d_obj(nullptr);
     

    A a;
    X<A>a_obj(&a);


}





Класс шаблон с полноценным оператором копирования
#include <iostream>
using namespace std;

template<class whateverUWant>
class simpleX
{
public:

    simpleX(whateverUWant *ptr)
    {
        obj = ptr;
    }
    simpleX(const simpleX& other)
    {
        this->obj = other.obj;

    }
    simpleX& operator = (const simpleX& other)
    {
        if (this == &other)
            return *this;
        this->obj = other.obj;
        return *this;
    }
    
private:
    whateverUWant* obj;
};

int main()
{
    
    int one[10] = { 1,2,3,4,5,6,7,8,9,10 };
    simpleX<int>arr(one);
    simpleX<int>arr2(arr);

    arr2 = arr;


}















#include <iostream>
#include <vector>

using namespace std;

template<class whateverUWant>
class simpleX
{
public:

    simpleX(whateverUWant *ptr)
    {
        this->obj = ptr;
    }
    simpleX(const simpleX& other)
    {
        this->obj = other.obj;

    }
    ~simpleX()
    {
        delete[]obj;
    }
    simpleX& operator = (const simpleX& other)
    {
        if (this == &other)
            return *this;
        this->obj = other.obj;
        return *this;
    }
    void show()
    {
        for (int i = 0; i < 10; i++)
        {
            cout << "element " << i + 1 << ": " << obj[i] << "\n";
        }
    }
private:
    whateverUWant* obj;
};

class shape
{
public:
    void show()
    {
        cout << "born this way\n";
    }
};

int main()
{

    int one[10] = { 1,2,3,4,5,6,7,8,9,10 };
    simpleX<int>arr(one);
    simpleX<int>arr2(arr);

    arr2 = arr;

    arr.show();

    shape a;
    a.show();
    vector<int>obj(10);
    vector<int>obj3 = obj;

}

