#ifndef __PRODUCTMANAGER_H_
#define __PRODUCTMANAGER_H_

#include "Employee.h"

class ProductManager : public Employee {
public:
	ProductManager(const char *name);
	virtual void receiveCall(Call *call);
	virtual void callHandled(Call *call);
	virtual void cannotHandle(Call *call);

private:
	
};

#endif
