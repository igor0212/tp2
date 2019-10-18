CC=g++
C=gcc
#CFLAGS=-std=c++11 -Wall
CFLAGS=

BUILD_DIR = ./build
SRC_DIR = ./src
INCLUDE_DIR = ./include
 
all: main 

####################################################
#                                                  #
#                       APP                        #
#                                                  #
####################################################

# Graph
Graph.o: ${INCLUDE_DIR}/Graph.hpp ${SRC_DIR}/models/Graph.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/models/Graph.cpp -o ${BUILD_DIR}/Graph.o

# GraphUtilities
GraphUtilities.o: ${INCLUDE_DIR}/GraphUtilities.hpp ${SRC_DIR}/utility/GraphUtilities.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/utility/GraphUtilities.cpp -o ${BUILD_DIR}/GraphUtilities.o

# SwapUtilities
SwapUtilities.o: ${INCLUDE_DIR}/SwapUtilities.hpp ${SRC_DIR}/utility/SwapUtilities.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/utility/SwapUtilities.cpp -o ${BUILD_DIR}/SwapUtilities.o

# CommanderUtilities
CommanderUtilities.o: ${INCLUDE_DIR}/CommanderUtilities.hpp ${SRC_DIR}/utility/CommanderUtilities.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/utility/CommanderUtilities.cpp -o ${BUILD_DIR}/CommanderUtilities.o

# tp2
tp2.o: ${INCLUDE_DIR}/tp2.hpp ${SRC_DIR}/tp2.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/tp2.cpp -o ${BUILD_DIR}/tp2.o

# main
main.o: ${INCLUDE_DIR}/tp2.hpp main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c main.cpp -o ${BUILD_DIR}/main.o

# app
main: Graph.o GraphUtilities.o SwapUtilities.o CommanderUtilities.o tp2.o main.o 
	${CC} ${CFLAGS} -o tp2 ${BUILD_DIR}/*.o

# Rule for cleaning files generated during compilation. 
# Call 'make clean' to use it 
clean: 
	rm -rf ${BUILD_DIR}/*.o    

clean_windows:
	del /S "%dir%\build\*.o"    

run:
	./tp2 equipe.txt

run_windows:
	./tp2.exe equipe.txt