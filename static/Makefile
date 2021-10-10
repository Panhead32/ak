аll: MarriageAgency

MarriageAgency: MarriageAgency.o libMarriageAgency.a
	g++ -o MarriageAgency MarriageAgency.o -L . -l MarriageAgency

MarriageAgency.o: MarriageAgency.cpp
	g++ -Wall -c MarriageAgency.cpp

libMarriageAgency.a: FileDB.o Customer.o
	ar cr libMarriageAgency.a FileDB.o Customer.o

FileDB.o: FileDB.cpp FileDB.h
	g++ -Wall -c FileDB.cpp

Customer.o: Customer.cpp Customer.h
	g++ -Wall -c Customer.cpp

clean:
	rm -f *.o *.a *.so MarriageAgency
