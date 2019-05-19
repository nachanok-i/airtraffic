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

flightGenerator.o : flightGenerator.c flightGenerator.h
	gcc -c flightGenerator.c 

planeInformation.o : planeInformation.c planeInformation.h flightGenerator.h
	gcc -c planeInformation.c flightGenerator.c

futureCollision.o : futureCollision.c futureCollision.h flightGenerator.h
	gcc -c futureCollision.c flightGenerator.c

planeUtility.o : planeUtility.c flightGenerator.h
	gcc -c planeUtility.c flightGenerator.c

menu.o : menu.c planeInformation.h futureCollision.h flightGenerator.h planeUtility.h datatype.h
	gcc -c menu.c planeInformation.c futureCollision.c flightGenerator.c planeUtility.c

menu$(EXECEXT) : menu.o planeInformation.o futureCollision.o flightGenerator.o planeUtility.o
	gcc -o menu$(EXECEXT) menu.o planeInformation.o futureCollision.o flightGenerator.o planeUtility.o


clean : 
	-rm *.o
	-rm $(EXECUTABLES)