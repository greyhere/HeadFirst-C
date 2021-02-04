## Compile steps (for Linux or Unix only)

1. Create `hfcal.o` object file with `-fPIC` flag. The `hfcal.h` header file is in ./includes 

    * For UK version
    ```
    gcc -I./includes -fPIC -c hfcal_UK.c -o hfcal.o
    ```
    * For US version, just replace `hfcal_UK.c` with `hfcal_US.c`

2. Create dynamic library from `hfcal.o` and store it in ./libs

```
gcc -shared hfcal.o -o ./libs/libhfcal.so
```

3. Create `elliptical.o` object file

```
gcc -I./includes -c elliptical.c -o elliptical.o
```

4. Finally, create `elliptical` executable using `elliptical.o` and `hfcal.so` shared object file

```
gcc elliptical.o -L./libs -lhfcal -o elliptical
```

---
## Using `make`
I've included `Makefile` so, you can comlile it using `make`

1. Create appropriate `hfcal.o` object file
    * For UK version
    ```
    make libUK
    ```
    * For US version
    ```
    make libUS
    ```

2. generate executable
```
make elliptical
```


## Running program

1. Set and export `LD_LIBRARY_PATH` variable

```
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./libs
```

2. Then, run the program

```
./elliptical
```

---

Now, if you want to change version you don't have to recompile `elliptical` codes
just compile required library codes using steps 1 & 2 of Compile steps.

If you want to use make then follow step 1 & re-generate `libhfcal.so` shared object file
```
make libhfcal.so
```

---

Note: If you store `libhfcal.so` library in one of the standart library directories,
then you don't have to set and export `LD_LIBRARY_PATH` variable.

This command copies `libhfcal.so` into one of the standard library directory
```
cp -v ./libs/libhfcal.so /usr/local/lib
```
