#include "Call.h"

int Call::rank() {
	return _rank;
}

void Call::promoteRank() {
	if (_rank < (int)CallHandler::PRODUCTMANAGER) {
		++_rank;
	}
}

Call::Call(int rank) {
	_rank = rank;
}

void Call::reply(Employee *replier) {
	_replier = replier;
}

void Call::complain() {
	_replier->cannotHandle(this);
}

void Call::disconnect() {
	_replier->callHandled(this);
}
