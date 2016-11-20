# iyzipay-c++
This software provides unofficial C++ client for users of iyzipay API.
More information about iyzipay API: https://www.iyzico.com/
##1. Introduction

You can sign up for an iyzico account at https://iyzico.com

##2. Dependencies

 - Qt (core, gui and network modules) 4.8 or greater
 - qmake
 - GNU g++ compiler
 - QJson 0.7 (libqjson 0.7.1 package on ubuntu) or greater

##3. Installation

Firstly, create a build directory and cd into it:
```
   mkdir build
   cd build
```
run qmake in order to generate Makefile:
```
    qmake ../iyzipay-client.pro -r -spec linux-g++-64
```
In order to build application run following command in terminal:

```
    make
```


