FROM ubuntu:24.04

ARG DEBIAN_FRONTEND=noninteractive

# Core build toolchain
RUN apt-get update && apt-get install -y --no-install-recommends \
    wget \
    curl \
    build-essential \
    g++-14 \
    cmake \
    ninja-build \
    gdb \
    git \
    ca-certificates \
    sudo \
    && rm -rf /var/lib/apt/lists/*

# Promote GCC-14 to default (Ubuntu 24.04 ships GCC-13 as default)
RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-14 100 \
                         --slave   /usr/bin/g++ g++ /usr/bin/g++-14 \
                         --slave   /usr/bin/gcov gcov /usr/bin/gcov-14 \
    && update-alternatives --install /usr/bin/cc  cc  /usr/bin/gcc-14 100 \
    && update-alternatives --install /usr/bin/c++ c++ /usr/bin/g++-14 100

# ubuntu:24.04 ships a built-in 'ubuntu' user at UID/GID 1000.
# Grant it passwordless sudo and use it — no groupadd/useradd needed.
RUN echo "ubuntu ALL=(ALL) NOPASSWD:ALL" > /etc/sudoers.d/ubuntu \
    && chmod 0440 /etc/sudoers.d/ubuntu

RUN mkdir -p /vscode && chown ubuntu:ubuntu /vscode

USER ubuntu