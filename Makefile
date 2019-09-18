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

# MeetingUtilities
MeetingUtilities.o: ${INCLUDE_DIR}/MeetingUtilities.hpp ${SRC_DIR}/utility/MeetingUtilities.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/utility/MeetingUtilities.cpp -o ${BUILD_DIR}/MeetingUtilities.o

# tp1
tp1.o: ${INCLUDE_DIR}/tp1.hpp ${SRC_DIR}/tp1.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/tp1.cpp -o ${BUILD_DIR}/tp1.o

# main
main.o: ${INCLUDE_DIR}/tp1.hpp main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c main.cpp -o ${BUILD_DIR}/main.o

# app
main: Graph.o GraphUtilities.o SwapUtilities.o MeetingUtilities.o tp1.o main.o 
	${CC} ${CFLAGS} -o tp1 ${BUILD_DIR}/*.o

# Rule for cleaning files generated during compilation. 
# Call 'make clean' to use it 
clean: 
	rm -rf ${BUILD_DIR}/*.o    

clean_windows:
	del /S "%dir%\build\*.o"    

run:
	./tp1 equipe.txt

run_windows:
	./tp1.exe equipe.txt