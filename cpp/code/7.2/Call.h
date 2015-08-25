#ifndef __CALL_H_
#define __CALL_H_

#include "CallHandler.h"
#include "Employee.h"

class Call {
public:
	void reply(Employee *replier);
	void complain();
	void disconnect();
	int rank();
	void promoteRank();
	Call(int rank);

private:
	int _rank;
	Employee *_replier;
};

#endif
