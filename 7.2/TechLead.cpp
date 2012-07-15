#include "TechLead.h"

TechLead::TechLead(const char *name) : Employee(CallHandler::TECHLEAD, name) {

}

void TechLead::receiveCall(Call *call) {
	_free = false;
	call->reply(this);
	cout << "Tech lead " << _name << " is handling call: " << call 
		<< " -- rank -- " << call->rank() << endl;
}

void TechLead::callHandled(Call *call) {
	_free = true;
}

void TechLead::cannotHandle(Call *call) {
	call->promoteRank();
	_free = true;
	cout << "TechLead " << _name << " receive complaint from call: " << call
		<< " -- update rank -- " << call->rank() << endl;
	_callHandler->dispatchCall(call);
}
