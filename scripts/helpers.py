#!/usr/bin/python3

# Get the binary wildcard from the selected envrionment
def get_bin_name(env):
    return {
        'TEST': '*_test',
        'DEBUG': '*_bin',
        'RELEASE': '*_bin'
    }[env]
# Get the ABI from the select achitecture
def get_abi(arch):
    return {
        'arm': 'armeabi-v7a',
        'arm64': 'arm64-v8a'
    }[arch]
# Get the API level ...
def get_api(api):
    return 'android-16'
# Get gdbserver from arch
def get_gdbserver(arch):
    return {
        'arm': 'gdbserver',
        'arm64': 'gdbserver64'
    }[arch]