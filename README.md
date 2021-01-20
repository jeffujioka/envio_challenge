# Repository for me to commit the work done throughout the development of Envio's coding challenge.

# Requirements
* Docker (tested on version 19.03)

# Setup
Create the docker image before running any of the scripts listed in the section below.
To build the docker image, execute the following script.
```shell
$ docker-build-image.sh
```

You can check if the docker image has been successfully created by executing the command below.

```shell
$ docker run -it --rm gcc-10.2_with_cmake-3.18.2 bash -c 'echo "everything is all right!"'
```

You shall see the message: _everything is all right!_

**Initialize the git submodule (googletest)**
```shell
$ git submodule init
$ git submodule update
```

## Scripts

At the project's root directory

### To build
```shell
$ ./docker-run.sh ./prj_build.sh
```
### To install
```shell
$ ./docker-run.sh ./prj_install.sh
```
### To build and install
```shell
$ ./docker-run.sh ./prj_build_install.sh
```
### To clean the build directory and the output folder**
```shell
$ ./docker-run.sh ./prj_clean.sh
```

### To run the tests
:warning: make sure you have installed [[1]](#To-build-and-install) it
```shell
$ ./docker-run.sh ./runtests.sh
```
