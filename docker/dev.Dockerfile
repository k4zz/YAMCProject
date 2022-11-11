FROM ubuntu

RUN DEBIAN_FRONTEND="noninteractive"

RUN apt update -y
RUN apt upgrade -y
RUN apt install -y \
        build-essential \
        g++ \
        gdb \
        ninja-build \
        cmake \
        valgrind \