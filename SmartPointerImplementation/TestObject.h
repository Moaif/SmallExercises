#pragma once

class TestObject
{
public:
	TestObject();
	explicit TestObject(int value);
	void DoSomething();
	void DoSomethingConst() const;
	int GetInt()const;
private:
	int value = 0;
};