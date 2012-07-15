#include "Call.h"

int Call::rank() {
	return _rank;
}

void Call::promoteRank() {
	if (_rank <= (int)CallHandler::TOPLEVEL) {
		++_rank;
	}
}

Call::Call(int rank) {
	_rank = rank;
}
