sorting: driver.o
	g++ -o sorting driver.o

driver.o: driver.cpp arrayList.h
	g++ -c driver.cpp

clean:
	rm *.o sorting
