// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class AbstractClass
{

public:
	void TemplateMethod()
	{
		//code
		PrimitiveOperation1();
		//more code
		PrimitiveOperation2();
	}


private:
	virtual void PrimitiveOperation1() = 0;
	virtual void PrimitiveOperation2() = 0;

};


class ConcreteClass : public AbstractClass
{
	void PrimitiveOperation1()
	{
		
	}

	void PrimitiveOperation2()
	{
		
	}

};

int main()
{
	ConcreteClass concrete_class;
	AbstractClass& abstract_class{ concrete_class };

	abstract_class.TemplateMethod();
	return 0;
}