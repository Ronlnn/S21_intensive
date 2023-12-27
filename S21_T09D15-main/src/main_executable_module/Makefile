CC = gcc
CFLAGS =  -Wall -Werror -Wextra

all: main_executable_module


build_with_dynamic:  data_process.so data_io.o decision.o main_executable_module.o
	$(CC) $(CFLAGS) -L. -ldata_process data_io.o  decision.o main_executable_module.o -o ../../build/Quest_6

build_with_static: main_executable_module.o decision.o data_process.o data_stat.a data_io.o
	$(CC) $(CFLAGS)  -L. -ldata_stat main_executable_module.o data_process.o data_io.o decision.o -o ../../build/Quest_5

main_executable_module: main_executable_module.o data_io.o data_stat.o data_process.o decision.o
	$(CC) main_executable_module.o data_io.o data_stat.o data_process.o decision.o -o ../../build/Quest_3

main_executable_module.o: main_executable_module.c ../data_libs/data_io.h ../data_libs/data_stat.h ../data_module/data_process.h ../yet_another_decision_module/decision.h
	$(CC) $(CFLAGS) -c main_executable_module.c

data_io.o:
	$(CC) $(CFLAGS) -c ../data_libs/data_io.c

data_stat.o:
	$(CC) $(CFLAGS) -c ../data_libs/data_stat.c

data_process.o:
	$(CC) $(CFLAGS) -c ../data_module/data_process.c

decision.o:
	$(CC) $(CFLAGS) -c ../yet_another_decision_module/decision.c

data_stat.a: ../data_libs/data_stat.c
	$(CC) $(CFLAGS) -c ../data_libs/data_stat.c 
	ar rc libdata_stat.a data_stat.o
	ranlib libdata_stat.a

data_process.so: ../data_module/data_process.c 
	$(CC) $(CFLAGS) -c -fPIC ../data_libs/data_stat.c
	$(CC) $(CFLAGS) -c -fPIC ../data_module/data_process.c
	$(CC) -shared -o libdata_process.so data_process.o data_stat.o
	cp libdata_process.so ../../build/

clean:
	rm -rf *.o main_executable_module

rebuild: clean all