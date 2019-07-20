# Remote-Container Android Native Development 

## Quick Start Ubuntu
```sh
sudo apt install docker.io code
code --install-extension ms-vscode-remote.remote-containers
git clone https://gitlab.com/Jason-Thomas/rm-dev-env.git && cd rm-dev-env/src
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
git clone https://gitlab.com/Jason-Thomas/rm-dev-env.git && cd rm-dev-env/src
git clone https://android.googlesource.com/platform/external/googletest //NOTE: this is master
cd ..
```

### Step by Step
- Start VSCode and "open folder" to the cloned repo
  - Once the project is open a notification toast will appear in the bottom right corner of the VSCode window. Click "Run Project in Container"
  - Wait Patiently... It may take 5-10 minutes depending on your hardware and network connection
- Once VSCode is loaded as normal you will be able to execute Clean, Build, Compile, and Full tasks for the project

### VSCode Tasks
Click the button labeled "Tasks" in the bottom blue bar to view tasks to execute. The task heirarchy is the following.
- Full
  - Build
    - Clean
  - Compile

## Future
- gdbserver and gdbclient for remote native debugging
- separate release, dev, and test builds
- docker size optimization

### Sources
- https://code.visualstudio.com/docs/remote/containers
- https://cmake.org/cmake/help/v3.15/
- https://developer.android.com/ndk/guides/cmake
