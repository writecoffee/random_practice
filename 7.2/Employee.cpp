#include "Employee.h"

Employee::Employee(int rank, const char *name) {
	_rank = rank;
	_name = name;
	_free = true;
}

int Employee::rank() const {
	return _rank;
}

bool Employee::isFree() const {
	return _free;
}
