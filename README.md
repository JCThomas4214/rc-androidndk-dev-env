# Remote-Container Android Native Development 

## Quick Start Ubuntu
```sh
sudo apt install docker.io code
code --install-extension ms-vscode-remote.remote-containers
git clone https://gitlab.com/Jason-Thomas/rc-androidndk-dev-env.git && cd rc-androidndk-dev-env/src
git clone https://android.googlesource.com/platform/external/googletest //NOTE: this is master
cd ..
```
## Quick Start Windows
1. Download and install [VSCode](https://code.visualstudio.com/)
2. Download and install the Remote-Container extention from the VSCode pluggin store (or install the extension in powershell)
```sh
code --install-extension ms-vscode-remote.remote-containers
```
3. Download and install [Docker Desktop](https://www.docker.com/products/docker-desktop) and make sure you login with your username (not email) and password
4. Git clone the necessary repos
```sh
git clone https://gitlab.com/Jason-Thomas/rc-androidndk-dev-env.git && cd rc-androidndk-dev-env/src
git clone https://android.googlesource.com/platform/external/googletest //NOTE: this is master
cd ..
```

### After Quick Start
1. Start VSCode and "Open Folder..." to the cloned repo
2. Once the project is open a notification toast will appear in the bottom right corner of the VSCode window. Click "Reopen in Container"
  - Alternatively you can click the green button at the bottom left of the vscode window and click the same option
3. Wait Patiently... It may take 5-10 minutes depending on your hardware and network connection
4. Once VSCode is loaded as normal you will be able to execute Clean, Build, Compile, and Full tasks for the project

### VSCode Tasks
Click the button labeled "Tasks" in the bottom blue bar to view tasks to execute. The task heirarchy is the following.
```sh
├─ Full
│   ├─ Build
│   └─ Move    
│       └─ Compile
└─ Clean           
```

## Debugging with gdbserver
Using breakpoints in VScode works! VScode will attach to a gdbserver running on a connected android device. The "GDB Attach (port: 5039)" launch configuration will do most of the work for you. 
1. Attach an Android device
2. Make sure you have access to the device with 'adb devices'
  - If you do not, it may be b/c you need to periferal access to the VM that's running docker (Windows) or there's a problem with the container config (Look in .devcontainer/.devcontainer.json)
3. Select a breakpoint and run the launch configuration in the debug tab
  - The launch config will first push the specified compiled binary/gdbserver(64), then 'adb forward' port 5039 so to have access to the running server over adb. The server will now run and you will see output in the VScode terminal tab.
4. Restart the debug cycle using cntl+shift+F5 or the green restart button as the host gdb will not attach on first run
NOTE: Currently gdbserver64 is being run statically, you will need to manually specify the 32-bit version in task.json if needed. Only works out of the box over adb but can be configured to operate over IP from the device. 

## Future
- docker size optimization

### Sources
- https://code.visualstudio.com/docs/remote/containers
- https://cmake.org/cmake/help/v3.15/
- https://developer.android.com/ndk/guides/cmake
