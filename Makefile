# Makefile for airtraffic project
# Created by Nachanok Issarapruk (Tap) ID 61070503410

ifeq ($(OSTYPE),WINDOWS)
	EXECEXT =.exe
	COMP	=__MINGCC__
	PLATFORM	=mingw
else
	EXECEXT =
	COMP	=__GCC__
	PLATFORM	=linux
endif

EXECUTABLES= menu$(EXECEXT) index$(EXECEXT) 

all : $(EXECUTABLES)

futureCollision.o :	futureCollision.c
	gcc -c futureCollision.c

flightGenerator.o : flightGenerator.c
	gcc -c flightGenerator.c

planeInformation.o : planeInformation.c
	gcc -c planeInformation.c

index.o : index.c flightGenerator.h planeInformation.h
	gcc -c index.c flightGenerator.o planeInformation.o

index$(EXECEXT) : index.o flightGenerator.o planeInformation.o
	gcc -o index$(EXECEXT) flightGenerator.o planeInformation.o


clean : 
	-rm *.o
	-rm $(EXECUTABLES)