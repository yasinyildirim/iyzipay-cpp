# iyzipay-c++
This software provides unofficial C++ client for users of iyzipay API.
More information about iyzipay API: https://www.iyzico.com/
##1. Introduction

You can sign up for an iyzico account at https://iyzico.com

##2. Dependencies

 - Qt (core, gui and network modules) 4.8 or greater
 - qmake
 - GNU g++ compiler
 - QJson 0.8 (libqjson 0.8.1 package on ubuntu) or greater

##3. Installation
####3.1 Using qmake
Firstly, create a build directory (which should not be inside the project directory) and cd into it:
```
   mkdir build
   cd build
```
create symbolic link to Certificates/ folder (The folder contains ssl certificates):
```
   ln -s ../iyzipay-cpp/Certificates
```
run qmake in order to generate Makefile:
```
    qmake ../iyzipay-cpp/iyzipay-client.pro -r -spec linux-g++-64
```
In order to build application run following command in terminal:

```
    make
```
Running application:
```
    ./iyzipay-client 
```
####3.2 Using Qt Creator IDE
* Right click on "iyzipay-client.pro" file, select "Open with QT Creator".
* Switch to "Poject mode" by clicking "Project" tab on left (or you can use ctrl + 5)
* Set your Debug and Release build paths in "Poject mode" settings
* Build and Run using IDE


