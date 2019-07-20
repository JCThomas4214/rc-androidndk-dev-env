FROM python:3

# Install pylint
RUN pip install pylint

# Avoid warnings by switching to noninteractive
ENV DEBIAN_FRONTEND=noninteractive

# Configure apt and install packages
RUN apt-get update \
    && apt-get -y install --no-install-recommends apt-utils 

# Verify git, process tools, lsb-release (common in install instructions for CLIs) installed
RUN apt-get -y install git procps lsb-release 
    
# Install any missing dependencies for enhanced language service
RUN apt-get -y install libicu[0-9][0-9]

## Install tools for gdbserver and gdbclient download and extract
RUN apt-get -y install curl unzip tar adb \
    && curl -L -o /mats/scripts/scripts.tar.gz --create-dirs https://android.googlesource.com/platform/development/+archive/master/scripts.tar.gz \
    && tar -C /mats/scripts -xvf /mats/scripts/scripts.tar.gz \
    && mv /mats/scripts/gdbclient.py /mats \
    && curl -L -o /mats/gdb/arm-linux-android-gdb+gdbserver.zip --create-dirs http://gnutoolchains.com/android/7.4.1/arm-linux-android-gdb+gdbserver.zip \
    && unzip /mats/gdb/arm-linux-android-gdb+gdbserver.zip -d /mats/gdb \
    && mv /mats/gdb/gdbserver /mats \
    && curl -L -o /mats/ndk/r20/android-ndk-r20-linux-x86_64.zip --create-dirs https://dl.google.com/android/repository/android-ndk-r20-linux-x86_64.zip \
    && unzip /mats/ndk/r20/android-ndk-r20-linux-x86_64.zip -d /mats/ndk/r20 \
    # && /mats/ndk/r20/android-ndk-r20/build/tools/make-standalone-toolchain.sh --system=linux-x86_64 --arch=arm --platform=android-16 --install-dir=/mats/ndk/r20 \
    # && cp /usr/bin/r10e/bin/arm-linux-androideabi-gcc* /usr/bin && cp /usr/bin/r10e/bin/arm-linux-androideabi-g++ /usr/bin \
    && rm -rf /mats/gdb \
    # && rm -rf /mats/ndk \
    && rm -rf /mats/scripts

RUN mkdir /workspace
WORKDIR /workspace

# Install Python dependencies from requirements.txt if it exists
COPY .devcontainer/requirements.txt.temp requirements.txt* /workspace/
RUN if [ -f "requirements.txt" ]; then pip install -r requirements.txt && rm requirements.txt*; fi
   
# Install C++ tools
RUN apt-get -y install build-essential cmake cppcheck valgrind
    
# Clean up
RUN apt-get autoremove -y \
    && apt-get clean -y \
    && rm -rf /var/lib/apt/lists/*

# Switch back to dialog for any ad-hoc use of apt-get
ENV DEBIAN_FRONTEND=dialog

# Set the default shell to bash rather than sh
ENV SHELL /bin/bash


