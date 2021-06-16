#!bin/bash
./myxd nofile
./myxd ../pa3/cantTouchThis
./myxd ~/../public/pa4test
./myxd -x ~/../public/pa4test
./myxd -o ~/../public/pa4test
./myxd -c ~/../public/pa4test
./myxd -s ~/../public/pa4test
./myxd -x ~/../public/pa4test -r 8655:9839
./myxd -c ~/../public/pa4test -r 8655:9839
./myxd -o ~/../public/pa4test -r 8655:9839
./myxd -s ~/../public/pa4test -r 8655:9839
./myxd -x ~/../public/pa4test -r 7570:8128
./myxd -c ~/../public/pa4test -r 7570:8128
./myxd -o ~/../public/pa4test -r 7570:8128
./myxd -s ~/../public/pa4test -r 7570:8128
./myxd -x ~/../public/pa4test -r 2702:7680
./myxd -c ~/../public/pa4test -r 2702:7680
./myxd -o ~/../public/pa4test -r 2702:7680
./myxd -s ~/../public/pa4test -r 2702:7680
./myxd -x ~/../public/pa4test -r 997:4195
./myxd -c ~/../public/pa4test -r 997:4195
./myxd -o ~/../public/pa4test -r 997:4195
./myxd -s ~/../public/pa4test -r 997:4195
./myxd -x ~/../public/pa4test -r 4403:9857
./myxd -c ~/../public/pa4test -r 4403:9857
./myxd -o ~/../public/pa4test -r 4403:9857
./myxd -s ~/../public/pa4test -r 4403:9857
./myxd ~/../public/pa4test > mydump
./myxd -u myundump mydump
