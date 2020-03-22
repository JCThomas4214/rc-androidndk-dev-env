#!/usr/bin/python3

import os, sys, subprocess
import argparse
import helpers

def run_prep(workspace_path, arch):
    subprocess.run([f'adb push DEBUG/{arch}/* /data/local/tmp'], shell=True)
    subprocess.run(['adb push /mats/gdbserver* /data/local/tmp'], shell=True)
    subprocess.run(['adb forward tcp:5039 tcp:5039'], shell=True)

def attach_to_gdbserver():
    print('attaching to server!')
    return

def start_gdb_server(arch, bin_name):
    subprocess.run([
        'adb', 'shell', 
        f'/data/local/tmp/{helpers.get_gdbserver(arch)}', ':5039', 
        f'/data/local/tmp/{bin_name}'
    ])

def main():
    parser = argparse.ArgumentParser(description='Interface with gdb and gdbserver')
    parser.add_argument('-p', '--prep', dest='prep', action='store_const',
                        const=True, help='prep gdbserver by sending binaries to device')
    parser.add_argument('-a', '--attach', dest='attach', action='store_const',
                        const=True, help='attach to a running gdbserver')
    parser.add_argument('arch', choices=["arm", "arm64"],
                        help='the architecture you are debugging')  
    parser.add_argument('bin', help='the binary you want to debugging')                    
    parsed_args = parser.parse_args()
    workspace_path = os.path.abspath(os.path.dirname(os.path.dirname(__file__)))

    if parsed_args.prep:
        run_prep(workspace_path, parsed_args.arch)
    if parsed_args.attach:
        attach_to_gdbserver()
    else:
        start_gdb_server(parsed_args.arch, parsed_args.bin)


if __name__ == "__main__":
    main()