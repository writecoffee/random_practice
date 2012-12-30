OBJS = 7.2.o Fresher.o TechLead.o ProductManager.o Employee.o CallHandler.o Call.o
DEBUG = -g
CC = g++
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

7.2: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o 7.2
7.2.o: 7.2.cpp CallHandler.o
	$(CC) $(CFLAGS) 7.2.cpp

Call.o: Call.cpp Call.h
	$(CC) $(CFLAGS) Call.cpp

CallHandler.o: CallHandler.cpp CallHandler.h Call.o Employee.o
	$(CC) $(CFLAGS) CallHandler.cpp

Employee.o: Employee.cpp Employee.h 
	$(CC) $(CFLAGS) Employee.cpp

Fresher.o: Fresher.cpp Fresher.h Employee.o
	$(CC) $(CFLAGS) Fresher.cpp

TechLead.o: TechLead.cpp TechLead.h Employee.o
	$(CC) $(CFLAGS) TechLead.cpp

ProductManager.o: ProductManager.cpp ProductManager.h Employee.o
	$(CC) $(CFLAGS) ProductManager.cpp

clean:
	rm *.o
