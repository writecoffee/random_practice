#include "ProductManager.h"

ProductManager::ProductManager(const char *name) : Employee(CallHandler::PRODUCTMANAGER, name) {

}

void ProductManager::receiveCall(Call *call) {
	_free = false;
	cout << "product manager " << _name << " is handling call: " << call 
		<< " -- rank -- " << call->rank() << endl;
}

void ProductManager::callHandled(Call *call) {
	_free = true;
}

void ProductManager::cannotHandle(Call *call) {
	_callHandler->dispatchCall(call);
	_free = true;
}
