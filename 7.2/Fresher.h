#ifndef __FRESHER_H_
#define __FRESHER_H_

#include "Employee.h"
#include "CallHandler.h"

class Fresher : public Employee {
public:
	Fresher(const char *name);
	virtual void receiveCall(Call *call);
	virtual void callHandled(Call *call);
	virtual void cannotHandle(Call *call);

private:

};

#endif
