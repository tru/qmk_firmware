#!/bin/sh

docker run -uroot -ekeyboard=ergodox_ez -ekeymap=blowrak_programming -v /Users/tobiashieta/code/qmk_firmware:/qmk qmk:latest
