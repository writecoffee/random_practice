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

	Call call1_1(CallHandler::FRESHER);
	Call call1_2(CallHandler::FRESHER);
	Call call1_3(CallHandler::FRESHER);
	Call call1_4(CallHandler::FRESHER);
	Call call1_5(CallHandler::FRESHER);
	Call call2(CallHandler::TECHLEAD);
	Call call3(CallHandler::TECHLEAD);
	Call call4(CallHandler::PRODUCTMANAGER);

	handler.dispatchCall(&call1_1);
	handler.dispatchCall(&call1_2);
	handler.dispatchCall(&call1_3);
	handler.dispatchCall(&call1_4);
	handler.dispatchCall(&call1_5);
	handler.dispatchCall(&call2);
	handler.dispatchCall(&call3);
	handler.dispatchCall(&call4);

	call1_1.disconnect();
	call2.complain();
	call3.disconnect();

	// Call Handler updates and dispatch Call4 to ProductManager
	handler.update();
	call4.disconnect();

	// Call Handler updates and dispatch Call2 to ProductManager
	handler.update();

	// Complain again, product manager just give up ...
	call2.complain();

	// ...

	return 0;
}
