#!/bin/sh

docker run -uroot -ekeyboard=ergodox_ez -ekeymap=blowrak_programming -v $(pwd):/qmk qmk:latest
