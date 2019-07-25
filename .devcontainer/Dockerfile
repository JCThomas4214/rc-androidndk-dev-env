FROM ubuntu:18.04

# Avoid warnings by switching to noninteractive
ENV DEBIAN_FRONTEND=noninteractive

# Configure apt and install packages
RUN apt-get update \
    && apt-get -y install --no-install-recommends apt-utils 

# Verify git, process tools, lsb-release (common in install instructions for CLIs) installed
RUN apt-get -y install git procps lsb-release 
    
# Install any missing dependencies for enhanced language service
RUN apt-get -y install libicu[0-9][0-9]

# Install tools
RUN apt-get -y install build-essential cppcheck valgrind python-dev python-pip curl unzip tar adb 

RUN mkdir -p /mats/cmake && curl -o /mats/cmake/cmake-2.8.12.2.tar.gz --create-dirs https://cmake.org/files/v2.8/cmake-2.8.12.2.tar.gz \
    && tar -C /mats/cmake -xvf /mats/cmake/cmake-2.8.12.2.tar.gz \
    && make /mats/cmake/cmake-2.8.12.2 && make /mats/cmake/cmake-2.8.12.2 install \
    && rm -rf /mats/cmake/* \
    && curl -o /mats/cmake/cmake-3.13.5-Linux-x86_64.tar.gz --create-dirs https://cmake.org/files/v3.13/cmake-3.13.5-Linux-x86_64.tar.gz \
    && tar -C /mats/cmake -xvf /mats/cmake/cmake-3.13.5-Linux-x86_64.tar.gz \
    && mv /mats/cmake/cmake-3.13.5-Linux-x86_64/bin/cmake /usr/bin/cmake \
    && mv /mats/cmake/cmake-3.13.5-Linux-x86_64/share/cmake-3.13 /usr/share/ \
    && rm -rf /mats/cmake


## Install tools for gdbserver and gdbclient download and extract
RUN curl -L -o /mats/scripts/scripts.tar.gz --create-dirs https://android.googlesource.com/platform/development/+archive/master/scripts.tar.gz \
    && tar -C /mats/scripts -xvf /mats/scripts/scripts.tar.gz \
    && mv /mats/scripts/gdbclient.py /mats \
    && curl -L -o /mats/ndk/android-ndk-r20-linux-x86_64.zip --create-dirs https://dl.google.com/android/repository/android-ndk-r20-linux-x86_64.zip \
    && unzip /mats/ndk/android-ndk-r20-linux-x86_64.zip -d /mats/ndk \
    && mv /mats/ndk/android-ndk-r20/prebuilt/android-arm/gdbserver /mats/gdbserver \
    && mv /mats/ndk/android-ndk-r20/prebuilt/android-arm64/gdbserver /mats/gdbserver64 \
    && rm -f /mats/ndk/android-ndk-r20-linux-x86_64.zip \
    && rm -rf /mats/gdb \
    && rm -rf /mats/scripts

RUN mkdir /workspace
WORKDIR /workspace
 
# Clean up
RUN apt-get autoremove -y \
    && apt-get clean -y \
    && rm -rf /var/lib/apt/lists/*

# Switch back to dialog for any ad-hoc use of apt-get
ENV DEBIAN_FRONTEND=dialog

# Set the default shell to bash rather than sh
ENV SHELL /bin/bash


