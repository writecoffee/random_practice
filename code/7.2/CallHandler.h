#ifndef __CALLHANDLER_H_
#define __CALLHANDLER_H_

#include <cstdlib>
#include <queue>
#include <vector>
#include "Call.h"
#include "Employee.h"
using namespace std;

class Employee;
class Call;

class CallHandler {
public:
	enum Rank {
		FRESHER = 0, TECHLEAD, PRODUCTMANAGER, TOPLEVEL
	};

	CallHandler();
	Employee *getCallHandler(Call *call);
	void update();
	void dispatchCall(Call *call);
	void employ(Employee *newEmployee);

private:
	static int LEVELS;
	queue<Call *> *_call_queues;
	vector<Employee *> **_employees_list;
};

#endif
