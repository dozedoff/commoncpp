commoncpp
=========

Common C++ classes used in other projects.

### Dependencies
* Boost Build
* Boost Library
* Log4cplus
* Openssl (for SHA256)
* GraphicsMagic C++
* Gtest

##### Fedora 20:
```
yum install boost-build.noarch boost-devel.x86_64 log4cplus-devel.x86_64 openssl-devel.x86_64 GraphicsMagick-c++-devel.x86_64 gtest-devel.x86_64
```

### Build
Run ```bjam``` in the project root directory to build and run the tests.
