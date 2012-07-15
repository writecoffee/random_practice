#ifndef __CALL_H_
#define __CALL_H_

#include "CallHandler.h"

class Call {
public:
	void reply();
	void disconnect();
	int rank();
	void promoteRank();
	Call(int rank);

private:
	int _rank;
};

#endif
