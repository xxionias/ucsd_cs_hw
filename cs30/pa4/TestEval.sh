#!bin/bash
./pa4test -h
echo $?
./pa4test --help
echo $?
./pa4test f f
echo $?
./pa4test -q
echo $?
./pa4test infile -r
echo $?
./pa4test infile -u
echo $?
./pa4test -r -u
echo $?
./pa4test -u -r
echo $?
./pa4test -x -o
echo $?
./pa4test -x -c
echo $?
./pa4test -x -s
echo $?
./pa4test -o -c
echo $?
./pa4test -o -s
echo $?
./pa4test -c -s
echo $?
./pa4test -o -x
echo $?
./pa4test -c -x
echo $?
./pa4test -s -x
echo $?
./pa4test -c -o
echo $?
./pa4test -s -o
echo $?
./pa4test -s -c
echo $?
./pa4test -x -o -c
echo $?
./pa4test -x -o -s
echo $?
./pa4test -x -c -s
echo $?
./pa4test -o -c -s
echo $?
./pa4test --hex --octal
echo $?
./pa4test --hex ---ascii
echo $?
./pa4test --hex --string
echo $?
./pa4test --octal ---ascii
echo $?
./pa4test --octal --string
echo $?
./pa4test ---ascii --string
echo $?
./pa4test --octal --hex
echo $?
./pa4test ---ascii --hex
echo $?
./pa4test --string --hex
echo $?
./pa4test ---ascii --octal
echo $?
./pa4test --string --octal
echo $?
./pa4test --string ---ascii
echo $?
./pa4test --hex --octal ---ascii
echo $?
./pa4test --hex --octal --string
echo $?
./pa4test --hex ---ascii --string
echo $?
./pa4test --octal ---ascii --string
echo $?
./pa4test -l -b
echo $?
./pa4test --little-endian --big-endian
echo $?
./pa4test infile -help -r
echo $?
./pa4test infile -help -u
echo $?
./pa4test -x -c infile -help -r
echo $?
./pa4test -x -ascii infile -r
echo $?
./pa4test -x -c infile -help -u
echo $?
./pa4test -x -ascii infile -u
echo $?
./pa4test -x -c -l -b
echo $?
./pa4test -x -c -l -b infile
echo $?
./pa4test -x -c -l -b -help
echo $?
./pa4test -x -c -l -b infile -h
echo $?
./pa4test -l -b infile -help -r
echo $?
./pa4test -b -little-endian infile -r
echo $?
./pa4test -l -b infile -help -u
echo $?
./pa4test -b -little-endian infile -u
echo $?
./pa4test -x -c -l -b -r
echo $?
./pa4test -x -c -l -b infile -r
echo $?
./pa4test -x -c -l -b -r infile
echo $?
./pa4test -x -l -r infile
echo $?
./pa4test -x -c -l -b -u
echo $?
./pa4test -x -c -l -b infile -u
echo $?
./pa4test -x -c -l -b -u infile
echo $?
./pa4test -x -l -u infile
echo $?
./pa4test -x -c -l -b -help -r
echo $?
./pa4test -x -c -l -b infile -help --range
echo $?
./pa4test -x -c -l -b -help -r infile
echo $?
./pa4test -x -l -r infile -help
echo $?
./pa4test -x -c -l -b -help -u
echo $?
./pa4test -x -c -l -b infile -help --undump
echo $?
./pa4test -x -c -l -b -help -u infile
echo $?
./pa4test -x -l -u infile -help
echo $?
