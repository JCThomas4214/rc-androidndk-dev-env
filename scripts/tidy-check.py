#!/usr/bin/python3

import os, sys, subprocess
import argparse

def run_tidy(workspace_path, files="*.c", pipe=None):
    # This will search for .c (and .cpp) file that are not in googletest
    # After we find the paths we will execute clang-tidy pointing to the ./build for the compile_commands.json
    proc = subprocess.run(
        # ['find', f'{workspace_path}/src/', '-type', 'f', '-name', f'{files}', '-not', '-path', f'{workspace_path}/src/googletest/*', '-exec', 'ls', f'{{}}', '\\;'],
        f'find {workspace_path}/src/ -type f -name "{files}" -not -path "{workspace_path}/src/googletest/*" -exec clang-tidy -p build {{}} \\;',
        shell=True, check=True, stdout=pipe
    )
    if pipe and len(proc.stdout) > 0:
        exit(1)
    # NOTE: if running tidy on .cpp files after compiling a binary that did not rely on them, the compile_commands.json 
    # will not reflect the includes necessary for tidy and you will get errors indicating include files are missing.

def main():
    parser = argparse.ArgumentParser(description='Check your code with Clang-Tidy!')
    parser.add_argument('-t', '--test', dest='env', action='store_const',
                        const='TEST', help='check tidy on test build (includes .cpp files)')
    parser.add_argument('-c', '--check', dest='check', action='store_const',
                        const=subprocess.PIPE, help='return tidy errorcode for CI')
    parsed_args = parser.parse_args()
    workspace_path = os.path.abspath(os.path.dirname(os.path.dirname(__file__)))

    if parsed_args.env:
        run_tidy(workspace_path, "*.c*", parsed_args.check)
    else:
        run_tidy(workspace_path, pipe=parsed_args.check)

if __name__ == "__main__":
    main()