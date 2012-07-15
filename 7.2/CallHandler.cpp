#include "CallHandler.h"

int CallHandler::LEVELS	= CallHandler::TOPLEVEL;

CallHandler::CallHandler() {
	_call_queues = new queue<Call *>[LEVELS];
	_employees_list = new vector<Employee *> *[LEVELS];
	for (int i = 0; i < LEVELS; ++i) {
		_employees_list[i] = new vector<Employee *>();
	}
}

void CallHandler::employ(Employee *newEmployee) {
	_employees_list[newEmployee->rank()]->push_back(newEmployee);
}

Employee *CallHandler::getCallHandler(Call *call) {
	for (int level = (int)(call->rank()); level < CallHandler::LEVELS; ++level) {
		vector<Employee *> *emp_lev = _employees_list[level];
		for (vector<Employee *>::iterator it = emp_lev->begin(); it != emp_lev->end(); ++it) {
			if ((*it)->isFree()) {
				return *it;
			}
		}
	}

	return NULL;
}

void CallHandler::dispatchCall(Call *call) {
	Employee *emp = getCallHandler(call);
	if (emp) { emp->receiveCall(call); }
	else { _call_queues[call->rank()].push(call); }
}
