#!/usr/bin/python3

import os, sys, subprocess
import argparse

ROOT_PATH =os.path.abspath(os.path.dirname(__file__))
CONTAINER = 'android_ndk_builder'
# The container used to build should always be the latest.
# Make sure when updates happen to the container you push the old container 
# with a version tag and the new container with the latest tag.
DOCKER_CMD = [
    'docker', 'run', '--rm', '-it',
    '-v', f'{ROOT_PATH}:/workspace/',
    '-v', '/etc/group:/etc/group:ro',
    '-u', f'ndkdev:{os.getgid()}',
    f'{CONTAINER}'
]
# Scripts you want to avoid executing directly/printing in help menu
AVOID = ['helpers']

# Find all available commands
def find_commands():
    tmp = []
    for root, dirs, files in os.walk('./scripts'):
        for name in files:
            if name.split('.')[0] not in AVOID:
                tmp.append(name.split('.')[0])
    return tmp

# Returns the path to script
def find_script(command):
    script = None
    for root, dirs, files in os.walk('./scripts'):
        for name in files:
            if command in name and name not in AVOID:
                script = os.path.join(root, name)
    return script

def main():
    parser = argparse.ArgumentParser(description='Entrypoint for Android NDK Env Scripts.')
    parser.add_argument('-p', '--pass', dest='container', action='store_const',
                        const=True, help='run without container')
    parser.add_argument('cmd', choices=find_commands(),
                        help='all Commands you can run')
    parser.add_argument('args', nargs=argparse.REMAINDER,
                        help='arguments for command')            
    parsed_args = parser.parse_args()

    # find the path to the command script
    script = find_script(parsed_args.cmd)
    
    fin_cmd = []
    if not parsed_args.container:
        fin_cmd = fin_cmd + DOCKER_CMD
    fin_cmd = fin_cmd + [script] + parsed_args.args

    subprocess.run(fin_cmd)

if __name__ == "__main__":
    main()