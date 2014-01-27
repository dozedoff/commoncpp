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

##### Ubuntu 13.10:
```
sudo apt-get install libboost-all-dev liblog4cplus-dev libgraphicsmagick++1-dev libssl-dev libgtest-dev
```

gtest only seems to ship in source form on Ubuntu, so you will need to compile and copy it:
```
sudo apt-get install cmake && cd /usr/src/gtest && sudo cmake CMakeLists.txt -Dgtest_disable_pthreads=ON && sudo make && sudo chmod o+x libgtest* && sudo mv libgtest* /usr/lib/
```

### Build
Run ```bjam``` in the project root directory to build and run the tests.
