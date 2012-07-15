#include "ProductManager.h"

ProductManager::ProductManager(const char *name) : Employee(CallHandler::PRODUCTMANAGER, name) {

}

void ProductManager::receiveCall(Call *call) {
	_free = false;
	call->reply(this);
	cout << "Product manager " << _name << " is handling call: " << call 
		<< " -- rank -- " << call->rank() << endl;
}

void ProductManager::callHandled(Call *call) {
	_free = true;
	cout << "Product Manager " << _name << " finished handling call: " << call << endl;
}

void ProductManager::cannotHandle(Call *call) {
	_free = true;
	cout << "Product Manager " << _name << " received complaint from call: " << call
		<< " just give up the call" << endl;
}
