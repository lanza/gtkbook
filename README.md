## Steps to get this to work
1. `brew install ninja cmake gtk`
2. `git clone https://github.com/lanza/gtkbook`
3. `cd gtkbook`
4. `cmake -G Xcode -B build`
5. `open build/gtkbook.xcodeproj`
6. Change the Xcode target from ZERO_CHECK to hellogtk
7. cmd+r

## To add another c file and binary
1. Add a new file called whatever.c (you can do this in Xcode)
2. Open CMakeLists.txt (also doable in Xcode)
3. Add a line at the end -- `add_program(whatever)`
4. Push cmd+b. Xcode will trigger CMake to regenerate the Xcode project before
   building.
5. Select the new Xcode target.
