CPP = g++ -std=c++14
INCLUDES = -I include
LIBDIR = -L lib
LIBS = -lboost_system -lcrypto -lssl -lcpprest
OUT = -o bin/Socials4Geeks
OBJS = #TODO: Дописать все файлы, которые планируем собирать

all: ${OBJS}
	${CPP} ${OPTIONS} ${OBJS} ${OUT} ${LIBDIR} ${LIBS}

%.o: %.cpp
	${CPP} ${INCLUDES} -c $*.cpp ${INCLUDES}

clear:
	rm -rf bin/*
	rm -rf *.o
