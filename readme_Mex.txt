This Library includes :
1. *.mat files for the functions.
2. libImRecognition.cpp a matlab generated c++ file contatining wrapper for matlab functions used in test.cpp
3.libImageRecognition.h a header file for the above .cpp file
4.libImageRecognituion.so a shared library

To Deploy the matlab based library please follow following steps 

1. Make sure Matlab Runtime exists in the server machine.
2. add paths of matlab library files to $LD_LIBRARY_PATH(see the readme.txt for this step)
3. add path of this library to $LD_LIBRARY_PATH
4.add path of VL_FEAT library used in this application to $LD_LIBRARY_PATH
5. compile the test.cpp to test all library paths are set up correctly(use -I flag to include matlab files).
e.g  g++ -c  -ansi -D_GNU_SOURCE -I/usr/local/MATLAB/R2012a/extern/include/cpp -I/usr/local/MATLAB/R2012a/extern/include -DUNIX -DX11 -DGLNXA64 -DGCC -pthread  -O -DNDEBUG  "test.cpp"
     g++ -O -pthread  -o test  test.o -Wl,-rpath-link,/usr/local/MATLAB/R2012a/bin/glnxa64 -L/usr/local/MATLAB/R2012a/runtime/glnxa64  -lmwmclmcrrt -lm  libImRecognition.so		

6.  

