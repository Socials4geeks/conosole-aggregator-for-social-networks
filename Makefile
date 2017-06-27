CPP = g++
OPTIONS = -std=c++11 -g -Wall
INCLUDES = -I include -I/usr/local/opt/openssl/include
LIBDIR = -L /usr/local/lib -L/usr/local/opt/openssl/lib
LIBS = -lboost_system -lssl -lcpprest
OUT = -o bin/ConNect
OBJS = dev/core/session.o dev/core/core.o dev/core/implementer.o dev/core/interfaces/interface_vk.o dev/core/interfaces/interfaces.o dev/core/interfaces/interface_basic.o dev/core/interfaces/interface_telegram.o dev/core/interfaces/interface_typical.o dev/core/authorization/auth_by_login_password.o dev/core/authorization/authorization.o dev/core/storages/storage.o dev/core/storages/file.o dev/core/API/APIs.o dev/core/API/API_interface_vk.o dev/core/API/API_interface_telegram.o dev/core/API/API_telegram.o dev/core/API/API_vk.o dev/core/API/API_interface.o dev/core/basic_functional.o dev/tools/config_parser.o dev/main.o dev/application.o dev/types.o

all: ${OBJS}
	${CPP} ${OPTIONS} ${OBJS} ${OUT} ${LIBDIR} ${LIBS}

%.o: %.cpp
	${CPP} ${OPTIONS} ${INCLUDES} -c $*.cpp -o $*.o

clear:
	rm -f bin/${OUT}
	find . -name '*.o' | xargs rm
