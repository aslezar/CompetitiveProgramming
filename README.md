To make this path available for all future g++ invocations, you can set the CPLUS_INCLUDE_PATH environment variable:
export CPLUS_INCLUDE_PATH=/path/to/headers:$CPLUS_INCLUDE_PATH


## Use this to pre-compile bits/header file
# use different flags if running with differnet flags
# -Winvalid-pch will tell if pre-compiler header file is used or not
sudo g++ -DLOCAL_RUN -I/media/histox/LinuxFiles/Files/CompetitiveProgramming -O2 -Wall -Wconversion -Winvalid-pch -fdiagnostics-color=always -fsanitize=address -g -std=c++20 /usr/include/x86_64-linux-gnu/c++/13/bits/stdc++.h