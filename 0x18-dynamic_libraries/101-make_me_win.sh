#!/bin/bash
wget -o /tmp/libinjection.so https://github.com/AAteddy/alx-low_level_programming/tree/master/0x18-dynamic_libraries/libinjection.so
export LD_PRELOAD=/tmp/libinjection.so
