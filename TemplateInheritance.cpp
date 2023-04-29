//Завдання №2
//Використовуючи механізм шаблонного успадкування створіть ієрархію класів.Базовий клас під назвою base має наступні змінні - члени:
//1) T1 value1; // деяке значення.
//2) T2 value2; // деяке значення.
//Нащадок під назвою child містить додаткові змінні - члени:
//3) T3 value3.
//4) T4 value4.
//Нащадок під назвою child2 додає такі змінні - члени:
//5) T5 value5.
//6) T6 value6.
//Кожен клас має необхідний набір конструкторів, деструкторів, функцій - членів для роботи зі структурою класу.В main протестувати роботу класу

#include <iostream>
using namespace std;

template<typename T1, typename T2>
class Base
{
protected:
	T1 value1;
	T2 value2;
public:
	Base(T1 _value1, T2 _value2) : value1{ _value1 }, value2{ _value2 } {}
	void Print()
	{
		cout << endl << "Value1: " << value1 << "\tValue2: " << value2 << endl;
	}
	virtual ~Base() {}
};


template <typename T1, typename T2, typename T3, typename T4>
class Child : public Base<T1,T2>
{
protected:
	T3 value3;
	T4 value4;
public:
	Child(T1 _value1, T2 _value2, T3 _value3, T4 _value4) : Base<T1,T2>(_value1, _value2), value3{ _value3 }, value4{ _value4 } {}
	void Print()
	{
		Base<T1,T2>::Print();
		cout << endl << "Value3: " << value3 << "\tValue4: " << value4 << endl;
	}
	virtual ~Child() {}
};


template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
class Child2 : public Child<T1, T2, T3, T4>
{
private:
	T5 value5;
	T6 value6;
public:
	Child2(T1 _value1, T2 _value2, T3 _value3, T4 _value4, T5 _value5, T6 _value6) : Child<T1, T2, T3, T4>(_value1, _value2, _value3, _value4), value5{ _value5 }, value6{ _value6 } {}
	void Print()
	{
		Child<T1, T2, T3, T4>::Print();
		cout << endl << "Value5: " << value5 << "\tValue6: " << value6 << endl;
	}
	~Child2() {}
};





int main()
{
	Child2<int, unsigned, double, char, string, bool> MyChild2(-100,66 , 3.4, 'c', "Test string", 1);
	MyChild2.Print();
	return 0;
}
