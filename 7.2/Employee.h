#ifndef __EMPLOYEE_H_
#define __EMPLOYEE_H_

#include <iostream>
#include "Call.h"
using namespace std;
class CallHandler;
class Call;


class Employee {
public:
	Employee(int rank, const char *name);
	void reg(CallHandler *callHandler);
	virtual void receiveCall(Call *call) = 0;
	virtual void callHandled(Call *call) = 0;
	virtual void cannotHandle(Call *call) = 0;
	bool isFree() const;
	int rank() const;

protected:
	CallHandler *_callHandler;
	const char *_name;
	int _rank;
	bool _free;
};

#endif
