FROM ubuntu:18.04

# Avoid warnings by switching to noninteractive
ENV DEBIAN_FRONTEND=noninteractive

ARG USERNAME=ndkdev
ARG USER_UID=1000
ARG USER_GID=$USER_UID

RUN groupadd --gid $USER_GID $USERNAME \
    && useradd -s /bin/bash --uid $USER_UID -g $USERNAME --create-home $USERNAME

RUN dpkg --add-architecture i386
# Configure apt and install packages
RUN apt-get update \
    && apt-get -y install --no-install-recommends apt-utils \
    # Verify git, process tools, lsb-release (common in install instructions for CLIs) installed
    && apt-get -y install git procps lsb-release \
    # Install any missing dependencies for enhanced language service
    && apt-get -y install libicu[0-9][0-9] \
    # Install tools
    && apt-get -y install build-essential cppcheck valgrind python3-dev python3-pip curl unzip tar adb sudo \
    # Add sudo support for the non-root user
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME

RUN mkdir /workspace && chown ndkdev:ndkdev /workspace && \
    mkdir /mats && chown ndkdev:ndkdev /mats
WORKDIR /workspace
USER $USERNAME

RUN pip3 install --user pylint

RUN curl -o /mats/cmake/cmake-3.17.0-Linux-x86_64.tar.gz --create-dirs -LJO https://github.com/Kitware/CMake/releases/download/v3.17.0/cmake-3.17.0-Linux-x86_64.tar.gz \
    && tar -C /mats/cmake -xvf /mats/cmake/cmake-3.17.0-Linux-x86_64.tar.gz \
    && sudo mv /mats/cmake/cmake-3.17.0-Linux-x86_64/bin/cmake /usr/bin/ \
    && sudo mv /mats/cmake/cmake-3.17.0-Linux-x86_64/share/cmake-3.17 /usr/share/ \
    && rm -rf /mats/cmake

## Install tools for gdbserver and gdbclient download and extract
RUN curl -L -o /mats/scripts/scripts.tar.gz --create-dirs https://android.googlesource.com/platform/development/+archive/master/scripts.tar.gz \
    && tar -C /mats/scripts -xvf /mats/scripts/scripts.tar.gz \
    && mv /mats/scripts/gdbclient.py /mats \
    && curl -L -o /mats/ndk/android-ndk-r21-linux-x86_64.zip --create-dirs https://dl.google.com/android/repository/android-ndk-r21-linux-x86_64.zip \
    && unzip /mats/ndk/android-ndk-r21-linux-x86_64.zip -d /mats/ndk \
    && mv /mats/ndk/android-ndk-r21/prebuilt/android-arm/gdbserver/gdbserver /mats/gdbserver \
    && mv /mats/ndk/android-ndk-r21/prebuilt/android-arm64/gdbserver/gdbserver /mats/gdbserver64 \
    && sudo cp -r /mats/ndk/android-ndk-r21/python-packages/* /usr/local/lib/python2.7/dist-packages \
    && rm -f /mats/ndk/android-ndk-r21-linux-x86_64.zip \
    && rm -rf /mats/gdb \
    && rm -rf /mats/scripts
ENV PATH="/mats/ndk/android-ndk-r21/toolchains/llvm/prebuilt/linux-x86_64/bin:$PATH"

# Clean up
RUN sudo apt-get autoremove -y \
    && sudo apt-get clean -y \
    && sudo rm -rf /var/lib/apt/lists/*

# Switch back to dialog for any ad-hoc use of apt-get
ENV DEBIAN_FRONTEND=dialog

# Set the default shell to bash rather than sh
ENV SHELL /bin/bash