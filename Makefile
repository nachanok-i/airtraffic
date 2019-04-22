# Makefile for airtraffic project
# Created by Nachanok Issarapruk (Tap) ID 61070503410
# update
ifeq ($(OSTYPE),WINDOWS)
	EXECEXT =.exe
	COMP	=__MINGCC__
	PLATFORM	=mingw
else
	EXECEXT =
	COMP	=__GCC__
	PLATFORM	=linux
endif

EXECUTABLES= menu$(EXECEXT)

all : $(EXECUTABLES)

flightGenerator.o : flightGenerator.c datatype.h
	gcc -c flightGenerator.c 

planeInformation.o : planeInformation.c flightGenerator.h
	gcc -c planeInformation.c

futureCollision.o : futureCollision.c datatype.h
	gcc -c futureCollision.c

menu.o : menu.c flightGenerator.h planeInformation.h futureCollision.h
	gcc -c menu.c flightGenerator.c planeInformation.c futureCollision.h

menu$(EXECEXT) : menu.o flightGenerator.o planeInformation.o futureCollision.o
	gcc -o menu$(EXECEXT) menu.o flightGenerator.o planeInformation.o futureCollision.o


clean : 
	-rm *.o
	-rm $(EXECUTABLES)