# GPE@20210310

* A. UVa: 10912 - Simple Minded Hashing
* B. UVa: 10042 - Smith Numbers
* C. UVa: 10203 - Snow Clearing
* D. UVa: 10104 - Euclid Problem
* E. UVa: 793 - Network Connections
* F. UVa: 10249 - The Grand Dinner

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
