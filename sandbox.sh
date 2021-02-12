#!/bin/bash
cd "$(dirname "$0")" || exit
mkdir -p temp
cp test/dummylib/*.h temp/
cp ./src/*.h temp/
