#Using CMake

We can generate the `Makefile` based on the definition above using the following command create a `build` directory to store the generated files by CMake:

```
mkdir build
cd build/
cmake ..
```

Now we can run files to build the binary.

cmake --build . --target Task_2