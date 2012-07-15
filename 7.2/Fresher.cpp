#include "Fresher.h"

Fresher::Fresher(const char *name) : Employee(CallHandler::FRESHER, name) {

}

void Fresher::receiveCall(Call *call) {
	_free = false;
	call->reply(this);
	cout << "Fresher " << _name << " is handling call: " << call 
		<< " -- rank -- " << call->rank() << endl;
}

void Fresher::callHandled(Call *call) {
	_free = true;
	cout << "Fresher " << _name <<  " finished handling call: " << call << endl;
}

void Fresher::cannotHandle(Call *call) {
	call->promoteRank();
	_free = true;
	cout << "Fresher " << _name << " received complaint from call: " << call
		<< " -- update rank -- " << call->rank() << endl;
	_callHandler->dispatchCall(call);
}
