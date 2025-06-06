# =================================
# Build and test environment for CI
# =================================

FROM ubuntu:24.04 as cpp-docker-common

ARG DEBIAN_FRONTEND=noninteractive
ARG CLANG_COMPILER_VERSION=17
ARG CMAKE_VERSION=4.0.0
ENV PATH="${PATH}:/cmake-${CMAKE_VERSION}-linux-x86_64/bin/:"

RUN apt-get update && apt-get -y dist-upgrade && apt-get -y install --fix-missing \
  binutils \
  build-essential \
  bzip2 \
  cppcheck \
  ccache \
  doxygen \
  graphviz \
  git \
  lsb-release \
  ninja-build \
  pipx \
  python3 \
  python3-pip \
  python3-setuptools \
  python3-venv \
  shellcheck \
  ssh \
  software-properties-common \
  sudo \
  tar \
  valgrind \
  wget

RUN wget https://github.com/Kitware/CMake/releases/download/v${CMAKE_VERSION}/cmake-${CMAKE_VERSION}-linux-x86_64.sh  \
    && chmod +x cmake-${CMAKE_VERSION}-linux-x86_64.sh  \
    && ./cmake-${CMAKE_VERSION}-linux-x86_64.sh --include-subdir --skip-license \
    && rm cmake-${CMAKE_VERSION}-linux-x86_64.sh
RUN bash -c "$(wget -O - https://apt.llvm.org/llvm.sh)"

RUN apt-get -y install --fix-missing clang-format clang-tidy clang-${CLANG_COMPILER_VERSION} llvm-${CLANG_COMPILER_VERSION} llvm-${CLANG_COMPILER_VERSION}-dev libclang-${CLANG_COMPILER_VERSION}-dev \
    && apt-get autoremove -y && apt-get clean

RUN mkdir iwyu && cd iwyu \
    && git clone --branch clang_${CLANG_COMPILER_VERSION} https://github.com/include-what-you-use/include-what-you-use.git \
    && mkdir build && cd build \
    && cmake -G "Ninja" -DCMAKE_PREFIX_PATH=/usr/lib/llvm-${CLANG_COMPILER_VERSION} ../include-what-you-use \
    && sudo ninja install \
    && cd ../.. \
    && rm -rf iwyu


# =================================
# DEV environment for local machine
# =================================

FROM cpp-docker-common as cpp-docker-dev

ARG DEV_USER=dev
ENV PATH="${PATH}:/home/${DEV_USER}/.local/bin/"

RUN apt-get -y install --fix-missing vim \
    && apt-get autoremove -y && apt-get clean

# Dev user for inside the container
RUN groupadd -f -g 1000 ${DEV_USER} && \
  useradd --non-unique -m -u 1000 -g 1000 -d /home/${DEV_USER} -s /bin/bash ${DEV_USER} && \
  usermod -a -G adm,cdrom,sudo,dip,plugdev ${DEV_USER} && \
  echo "${DEV_USER}:${DEV_USER}" | chpasswd && \
  echo "${DEV_USER}   ALL=(ALL:ALL) ALL" >> /etc/sudoers

COPY ccache.conf /etc/.

USER ${DEV_USER}
WORKDIR /home/${DEV_USER}

RUN sed -i 's/\\h/docker/;s/01;32m/01;33m/' /home/${DEV_USER}/.bashrc \
  && mkdir /home/${DEV_USER}/git

RUN pipx install conan


FROM cpp-docker-common as cpp-docker-ci

ARG CI_USER=ci
ENV PATH="${PATH}:/home/${CI_USER}/.local/bin/"

# Dev user for inside the container
RUN groupadd -f -g 1000 ${CI_USER} && \
  useradd --non-unique -m -u 1000 -g 1000 -d /home/${CI_USER} -s /bin/bash ${CI_USER} && \
  usermod -a -G adm,cdrom,sudo,dip,plugdev ${CI_USER} && \
  echo "${CI_USER}:${CI_USER}" | chpasswd && \
  echo "${CI_USER}   ALL=(ALL:ALL) ALL" >> /etc/sudoers

COPY ccache.conf /etc/.
USER ${CI_USER}
RUN pipx install conan
WORKDIR /home/${CI_USER}
