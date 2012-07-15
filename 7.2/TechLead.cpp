#include "TechLead.h"

TechLead::TechLead(const char *name) : Employee(CallHandler::TECHLEAD, name) {

}

void TechLead::receiveCall(Call *call) {
	_free = false;
	cout << "Tech lead " << _name << " is handling call: " << call 
		<< " -- rank -- " << call->rank() << endl;
}

void TechLead::callHandled(Call *call) {
	_free = true;
}

void TechLead::cannotHandle(Call *call) {
	call->promoteRank();
	_callHandler->dispatchCall(call);
	_free = true;
}
