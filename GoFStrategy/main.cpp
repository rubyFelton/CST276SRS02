// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class Strategy //strategy
{
public:
	virtual void AlgorithmInterface() = 0;
};

class Context //
{
private:
	Strategy * strategy_{ nullptr };
public:
	void setStrategy(Strategy* const strategy)
	{
		strategy_ = strategy;
	}

	void ContextInterface()
	{
		if(strategy_ != nullptr)
		{
			strategy_->AlgorithmInterface();
		}
	}
};

class ConcreteStrategyA : public Strategy //concrete strategy
{
public:
	void AlgorithmInterface() override
	{
		
	}
};

class ConcreteStrategyB : public Strategy //concrete strategy
{
public:
	void AlgorithmInterface() override
	{

	}
};

class ConcreteStrategyC: public Strategy //concrete strategy
{
public:
	void AlgorithmInterface() override
	{

	}
};

int main()
{

	Context context;
	ConcreteStrategyA concrete_strategy_a;
	ConcreteStrategyB concrete_strategy_b;
	ConcreteStrategyC concrete_strategy_c;

	context.setStrategy(&concrete_strategy_a);
	context.ContextInterface();

	context.setStrategy(&concrete_strategy_b);
	context.ContextInterface();

    return 0;
}

