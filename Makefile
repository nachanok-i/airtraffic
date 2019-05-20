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

EXECUTABLES= planeControl$(EXECEXT)

all : $(EXECUTABLES)

flightGenerator.o : flightGenerator.c flightGenerator.h
	gcc -c flightGenerator.c

validate.o : validate.c validate.h
	gcc -c validate.c

planeInformation.o : planeInformation.c planeInformation.h flightGenerator.h
	gcc -c planeInformation.c flightGenerator.c

futureCollision.o : futureCollision.c futureCollision.h flightGenerator.h
	gcc -c futureCollision.c flightGenerator.c

planeUtility.o : planeUtility.c flightGenerator.h
	gcc -c planeUtility.c flightGenerator.c



planeControl.o : planeControl.c futureCollision.h flightGenerator.h planeUtility.h validate.h datatype.h
	gcc -c planeControl.c futureCollision.c flightGenerator.c planeUtility.c validate.c

planeControl$(EXECEXT) : planeControl.o futureCollision.o flightGenerator.o planeUtility.o validate.o
	gcc -o planeControl$(EXECEXT) planeControl.o futureCollision.o flightGenerator.o planeUtility.o validate.o


clean : 
	-rm *.o
	-rm $(EXECUTABLES)
