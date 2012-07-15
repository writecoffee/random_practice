#include "CallHandler.h"
#include "Fresher.h"
#include "TechLead.h"
#include "ProductManager.h"

int main() {
	CallHandler handler;
	handler.employ(new Fresher("Lily"));
	handler.employ(new Fresher("Ben"));
	handler.employ(new Fresher("Carlos"));
	handler.employ(new Fresher("David"));
	handler.employ(new Fresher("Thomas"));
	handler.employ(new TechLead("Anglela"));
	handler.employ(new ProductManager("Benson"));
	handler.dispatchCall(new Call(CallHandler::FRESHER));
	handler.dispatchCall(new Call(CallHandler::TECHLEAD));
	handler.dispatchCall(new Call(CallHandler::PRODUCTMANAGER));
	return 0;
}
