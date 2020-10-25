## Steps to get this to work
1. `brew install ninja cmake gtk`
2. `git clone https://github.com/lanza/gtkbook`
3. `cd gtkbook`
4. `cmake -G Xcode -B build`
5. `open build/gtkbook.xcodeproj`
6. Change the Xcode target from ZERO_CHECK to hellogtk
7. cmd+r

## To add another c file and binary
1. Add a new file called whatever.c
2. Open CMakeLists.txt
3. Add a line at the end -- `add_program(whatever)`
4. rerun `cmake -G Xcode -B build`
5. Maybe reoopen Xcode? Sometimes it can detect the change.
