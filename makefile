# *****************************************************
# Julio Vega
# Example of Makefile
# *****************************************************
# NOTES: it uses '>' as prefix of my recipes (.RECIPEPREFIX is set in line 11)
# since all actions of every Makefile's rule are identified by tabs and I do not
# use tabs in my file editor. Otherwise, I will get the 'missing separator' error.
#
# To check whether a tab character is used, run: cat -e -t -v Makefile
# It shows the presence of tabs (-t) with ^I and line endings (-e) with $
# *****************************************************

CC = g++
CFLAGS = -Wall -g
.RECIPEPREFIX = >

main: main.o Sensor.o CLInterface.o QtInterface.o Interface.o Dashboard.o LoginInterface.o CLLoginInterface.o User.o CLIUtils.o Database.o CLDashboard.o CLMenuBar.o MenuBar.o
>$(CC) $(CFLAGS) -o main main.o Sensor.o CLInterface.o QtInterface.o Interface.o Dashboard.o LoginInterface.o CLLoginInterface.o User.o CLIUtils.o Database.o CLDashboard.o CLMenuBar.o MenuBar.o

main.o: main.cpp Sensor.h CLInterface.h Interface.h 
>$(CC) $(CFLAGS) -c main.cpp

Sensor.o: Sensor.h

Database.o: Database.h User.h

User.o: User.h

LoginInterface.o: LoginInterface.h CLLoginInterface.h User.h Database.h

CLIUtils.o: CLIUtils.h User.h

CLLoginInterface.o: LoginInterface.h CLLoginInterface.h CLIUtils.h Database.h

CLDashboard.o: Dashboard.h CLDashboard.h MenuBar.h CLMenuBar.h CLIUtils.h User.h

Dashboard.o: Dashboard.h CLDashboard.h MenuBar.h User.h

CLMenuBar.o: MenuBar.h CLMenuBar.h CLIUtils.h

MenuBar.o: MenuBar.h CLMenuBar.h

CLInterface.o: CLInterface.h Interface.h Dashboard.h LoginInterface.h CLIUtils.h

QtInterface.o: QtInterface.h Interface.h Dashboard.h LoginInterface.h

Interface.o: Interface.h Dashboard.h LoginInterface.h

clean:
>rm *.o main terminalSize.txt
