if [[ ! -d build ]]; then
 mkdir build
 mkdir build/debug
 mkdir build/release
fi

gcc -Wall -std=gnu11 -ggdb src/debug_printf.c -o build/debug/debug_printf.exe
