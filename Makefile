OBJS 	= SKAHashTable.o SKAList.o main.o
SOURCE	= SKAHashTable.cpp SKAList.cpp main.cpp
HEADER  = SKAHashTable.hpp SKAList.hpp
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

# clean house
clean:
	rm -f $(OBJS) $(OUT)

# do a bit of accounting
count:
	wc $(SOURCE) $(HEADER)
