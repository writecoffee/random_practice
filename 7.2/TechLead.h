#ifndef __TECHLEAD_H_
#define __TECHLEAD_H_

#include "Employee.h"
#include "CallHandler.h"

class TechLead : public Employee {
public:
	TechLead(const char *name);
	virtual void receiveCall(Call *call);
	virtual void callHandled(Call *call);
	virtual void cannotHandle(Call *call);

private:

};

#endif
