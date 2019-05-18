README.txt

Air Traffic Control System Simulation
	Presently we are working on build program structure by building algorithm for each file
follow by the booklet from last time.
We builded "futureCollision.c","planeInformation.c","generateFlight.c","validate.c".
We have tested all of them and these module work just fine by create "menu.c"
to run these module.

This is our progress toward the program
	choice 1 - Information and status of available runway
		We have not work on any function about runway yet.
	choice 2 – Plane information generator
		This function work well.
	choice 3 – Plane movement simulator
		This function work well but we did not connect it to choice 2.
	this use to test algorithm of how well it currently work
	choice 4 – Display information of currenly active planes
		This function work well. (Algorithm testing)
	choice 5 – Potential future plane collision detector display
		This function work well. (Algorithm testing)
	choice 6 – Send command to specific plane
		We have not work on this.
But we have not connect every functions from each choices together so each one of them work seperately
and we have not use "validate.c" yet because we still working on choice 6 which is recieving command from user.

Troubleshoot
	1."generteFlight.c" - random function did not work well because it did not random at all. it keep printing the same plane information. We got a solution from but we still figure it and finally we solve it by using sran() in "menu.c".
	2."Makefile" - we have too much file when we creating it so we have a problem of combining it together because we include header file multiple times.
	Solved using #ifndef from your lab.
	3. We can't combine every function together because we have not enought time and we have not finish all of the choices so we test it by using "menu.c".
	4. But from all we have now we can combine it when we create "planeControl.c" function and control all the function in every file.


