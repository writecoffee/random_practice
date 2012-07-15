#include "Fresher.h"

Fresher::Fresher(const char *name) : Employee(CallHandler::FRESHER, name) {

}

void Fresher::receiveCall(Call *call) {
	_free = false;
	cout << "Fresher " << _name << " is handling call: " << call 
		<< " -- rank -- " << call->rank() << endl;
}

void Fresher::callHandled(Call *call) {
	_free = true;
}

void Fresher::cannotHandle(Call *call) {
	call->promoteRank();
	_callHandler->dispatchCall(call);
	_free = true;
}
