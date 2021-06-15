# GPE@20210512

* A. UVa: 256 - Quirksome Squares
* B. UVa: 10533 - Digit Primes
* C. UVa: 10125 - Sumsets
* D. UVa: 10405 - Longest Common Subsequence
* E. UVa: 10000 - Longest Paths
* F. UVa: 10308 - Roads in the North

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
