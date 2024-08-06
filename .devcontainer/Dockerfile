FROM gcc
FROM python

# Install the xz-utils and other packages
RUN apt-get update && apt-get install -y xz-utils\
                                         build-essential gdb gdbserver g++\
                                         clang\
                                         lcov\
                                         ninja-build\
                                         astyle\
                                         cmake make\
                                         clang clang-tidy\
                                         zip unzip\
                                         wget curl\
                                         git\
                                         doxygen graphviz\
                                         python3 python3-pip\
                                         astyle\
                                         perl

WORKDIR /workspaces/brompton/

COPY requirements.txt /workspaces/brompton/python/requirements.txt
RUN python3 -m pip install -r /workspaces/brompton/python/requirements.txt
