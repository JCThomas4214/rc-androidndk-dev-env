#!/usr/bin/python3

import subprocess
import argparse

def run_tidy(files="*.c"):
    # This will search for .c (and .cpp) file that are not in googletest
    # After we find the paths we will execute clang-tidy pointing to the ./build for the compile_commands.json
    subprocess.run(
        f'find src/ -type f -name \'{files}\' -not -path \'src/googletest/*\' -exec clang-tidy -p build {{}} \\;', 
        shell=True
    )
    # NOTE: if running tidy on .cpp files after compiling a binary that did not rely on them, the compile_commands.json 
    # will not reflect the includes necessary for tidy and you will get errors indicating include files are missing.

def main():
    parser = argparse.ArgumentParser(description='Check your code with Clang-Tidy!')
    parser.add_argument('-t', '--test', dest='env', action='store_const',
                        const='TEST', help='check tidy on test build (includes .cpp files)')
    parsed_args = parser.parse_args()

    if parsed_args.env:
        run_tidy("*.c*")
    else:
        run_tidy()

if __name__ == "__main__":
    main()