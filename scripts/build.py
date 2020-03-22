#!/usr/bin/python3

import os, sys, subprocess
import argparse
import helpers

# Toolchain location in the docker container
TOOLCHAIN = '/mats/ndk/android-ndk-r21/build/cmake/android.toolchain.cmake'

# Build the makefiles with cmake
def run_build(workspace_path, arch, env):
    subprocess.run([
        'cmake', f'-DCMAKE_TOOLCHAIN_FILE={TOOLCHAIN}',
        f'-DCMAKE_BUILD_TYPE={env}', f'-DANDROID_ABI={helpers.get_abi(arch)}', f'-DANDROID_NATIVE_API_LEVEL={helpers.get_api(arch)}', 
        '-S', workspace_path, 
        '-B', f'{workspace_path}/src/build'
    ])
# Compile using the makefiles using cmake which points to Android NDK toolchain
def run_compile(workspace_path):
    subprocess.run([
        'cmake', '--build', f'{workspace_path}/src/build', '--', '-j', '6'
    ])
# Move the compiled binaries into and environment folder
def move_bins(workspace_path, arch, env):
    subprocess.run(['mkdir', '-p', f'{workspace_path}/{env}/{arch}'])
    subprocess.run(
        f'find {workspace_path}/src/build -name \'{helpers.get_bin_name(env)}\' -exec cp {{}} {workspace_path}/{env}/{arch} \\;', 
        shell=True
    )


def main():
    parser = argparse.ArgumentParser(description='Compile using the Android NDK')
    parser.add_argument('arch', choices=["arm", "arm64"],
                        help='the architecture to compile')
    parser.add_argument('-d', '--debug', dest='env', action='store_const',
                        const='DEBUG', help='compile debugging')
    parser.add_argument('-t', '--test', dest='env', action='store_const',
                        const='TEST', help='compile testings')
    parser.add_argument('-r', '--release', dest='env', action='store_const',
                        const='RELEASE', help='compile release')
    parsed_args = parser.parse_args()
    workspace_path = os.path.abspath(os.path.dirname(os.path.dirname(__file__)))

    if parsed_args.env:
        run_build(workspace_path, parsed_args.arch, parsed_args.env)
        run_compile(workspace_path)
        move_bins(workspace_path, parsed_args.arch, parsed_args.env)
    else:
        # Compile Test, Debug, and Release
        all_envs = ['TEST', 'DEBUG', 'RELEASE']
        for env in all_envs:
            run_build(workspace_path, parsed_args.arch, env)
            run_compile(workspace_path)
            move_bins(workspace_path, parsed_args.arch, env)
        


if __name__ == "__main__":
    main()