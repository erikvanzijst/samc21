FROM ubuntu:18.04
MAINTAINER Erik van Zijst <erik.van.zijst@gmail.com>
LABEL Description="Embedded ARM GNU C compiler and OpenOCD"

RUN apt-get update -y
RUN apt-get install -y \
    python3 \
    build-essential \
    gcc-arm-none-eabi \
    git \
    openocd
