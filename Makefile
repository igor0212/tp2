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

# Utilities
Utilities.o: ${INCLUDE_DIR}/Utilities.hpp ${SRC_DIR}/utility/Utilities.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/utility/Utilities.cpp -o ${BUILD_DIR}/Utilities.o

# tp2
tp2.o: ${INCLUDE_DIR}/tp2.hpp ${SRC_DIR}/tp2.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c ${SRC_DIR}/tp2.cpp -o ${BUILD_DIR}/tp2.o

# main
main.o: ${INCLUDE_DIR}/tp2.hpp main.cpp
	${CC} ${CFLAGS} -I ${INCLUDE_DIR}/ -c main.cpp -o ${BUILD_DIR}/main.o

# app
main: Utilities.o tp2.o main.o 
	${CC} ${CFLAGS} -o tp2 ${BUILD_DIR}/*.o

# Rule for cleaning files generated during compilation. 
# Call 'make clean' to use it 
clean: 
	rm -rf ${BUILD_DIR}/*.o    

clean_windows:
	del /S "%dir%\build\*.o"    

run:
	./tp2 exemplo1.txt

run_windows:
	./tp2.exe exemplo1.txt