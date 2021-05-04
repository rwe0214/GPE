# GPE@20210322

* A. UVa: 10110 - Light, more light
* B. UVa: 997 - Show the Sequence
* C. UVa: 10140 - Prime Distance
* D. UVa: 11475 - Extend to Palindromes
* E. UVa: 10032 - Tug of War
* F. UVa: 10090 - Marbles

## Testing

```shell
$ ls
Makefile   Readme.md  solutions  testdata   testoutput

$ make
g++ --std=c++11  -o bin/A solutions/A.cpp
g++ --std=c++11  -o bin/B solutions/B.cpp
g++ --std=c++11  -o bin/C solutions/C.cpp
g++ --std=c++11  -o bin/D solutions/D.cpp
g++ --std=c++11  -o bin/E solutions/E.cpp
g++ --std=c++11  -o bin/F solutions/F.cpp

$ make test
Checking A.test
Checking B.test
Checking C.test
Checking D.test
Checking E.test
Checking F.test
Success, all tests passed.
```
