## Mac OSX Hooks Demo

>  http://tlrobinson.net/blog/2007/12/overriding-library-functions-in-mac-os-x-the-easy-way-dyld_insert_libraries/

1.  `gcc -Wall -o lib_overrides.dylib -dynamiclib lib_overrides.c`
2.  `gcc -Wall -o overrides_test overrides_test.c`
3.  `gcc -Wall -o test test.c`
4.  `DYLD_FORCE_FLAT_NAMESPACE=1 DYLD_INSERT_LIBRARIES=lib_overrides.dylib ./overrides_test`
5.  check `hello.txt`: expected output: `hello world by original fopen`
6.  `DYLD_FORCE_FLAT_NAMESPACE=1 DYLD_INSERT_LIBRARIES=lib_overrides.dylib ./overrides_test`
7.  check `hello.txt`: expected output: `hello world by overrides fopen`
