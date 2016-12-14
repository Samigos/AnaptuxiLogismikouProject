OBJS 	= SKAHashTable.o SKAList.o main.o Converters.o datafile.o Euclidian.o Ghash.o Hamming.o queryfile.o SKAWriteToFile.o
SOURCE	= SKAHashTable.cpp SKAList.cpp main.cpp Converters.cpp datafile.cpp Euclidian.cpp Ghash.cpp Hamming.cpp queryfile.cpp SKAWriteToFile.cpp
HEADER  = SKAHashTable.hpp SKAList.hpp Converters.hpp datafile.hpp Euclidian.hpp Ghash.hpp Hamming.hpp queryfile.hpp SKAWriteToFile.hpp
OUT  	= lsh
CC	= g++
FLAGS   = -g -c

$(OUT): $(OBJS)
	$(CC)  -g $(OBJS) -o $(OUT)

# create/compile the individual files >>separately<< 
SKAHashTable.o: SKAHashTable.cpp
	$(CC) $(FLAGS) SKAHashTable.cpp 

SKAList.o: SKAList.cpp
	$(CC) $(FLAGS) SKAList.cpp

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

Converters.o: Converters.cpp
	$(CC) $(FLAGS) Converters.cpp 

datafile.o: datafile.cpp
	$(CC) $(FLAGS) datafile.cpp

Euclidian.o: Euclidian.cpp
	$(CC) $(FLAGS) Euclidian.cpp

Ghash.o: Ghash.cpp
	$(CC) $(FLAGS) Ghash.cpp

Hamming.o: Hamming.cpp
	$(CC) $(FLAGS) Hamming.cpp 

queryfile.o: queryfile.cpp
	$(CC) $(FLAGS) queryfile.cpp

SKAWriteToFile.o: SKAWriteToFile.cpp
	$(CC) $(FLAGS) SKAWriteToFile.cpp

# clean house
clean:
	rm -f $(OBJS) $(OUT)

# do a bit of accounting
count:
	wc $(SOURCE) $(HEADER)
