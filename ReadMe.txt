In order to run the resonance decay program you must take the following steps:

1.  Open terminal

2.  Place the Final_Project folder in a directory of your choosing. Your Desktop
    is the simplest choice.

3.  Modify the setup.csh file in the directory ../Final_Project/ for the ROOT and
    GSL setup on your computer.

4.  Modify the setup.csh file in the directory ../Final_Project/Executable/ so
    that the EVENT variable points at the directory ../Final_Project/Lib on your
    machine.

5.  On the terminal open a c-shell by typing the command “csh” into the prompt.

6.  Then change the directory to ../Final_Project using the “cd” command.

7.  Type “source setup.csh” and hit return. This will set your ROOT and GSL
    environment variables.

8.  Move to the Lib directory by typing “cd Lib/“ and hitting return.

9. You must compile the shared library, libEvent.so, by typing “make” and then
    return. The compiler will give some warnings regarding overriding base class
    functions.

10. Move to the Executable directory by typing “cd ../Executable” and hitting
    return.

11. Type “source setup.csh” and hit return. This will set the environment variables
    for the libEvent.so shared library.

12. Type “make” and hit return to compile the resonanceDecay.C source code located
    in the /src/ directory.

13. Run the program by typing “./bin/resonanceDecay” and hitting return. The program
    should produce 1000 events (#0-999) and print their decay product information.
    It will also store this data in a root file and place it in the current directory.
    If you followed these instructions carefully, it should be in
    ../Final_Project/Executable. If not, move it to this directory.

14. Analyze the data via the ROOT macro analyzeDecays.C. If your current directory is
    not ../Final_Project/Executable, change to this directory. Type
    “root analyzeDecays.C” and hit enter. This will calculate and display the invariant
    mass of the decay for each event.

15. There is an example run following these instructs called “Example.txt” in the same
    directory as this file for reference.