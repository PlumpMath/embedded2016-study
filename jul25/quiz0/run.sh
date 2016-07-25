#!/bin/sh

# Check commands exist
if ! hash qemu-arm > /dev/null; then
    echo "ERROR: command 'qemu-arm' not found, please install qemu first!!"
    exit 1
fi

if ! hash arm-linux-gnueabihf-gcc > /dev/null; then
    echo "ERROR: command 'arm-linux-gnueabihf-gcc' not found, please install it first!!"
    exit 1
fi

# rebuild and execute
make clean
make
qemu-arm bubblesort
