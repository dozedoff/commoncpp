#!/bin/sh
sudo apt-get install libboost-all-dev liblog4cplus-dev libgraphicsmagick++1-dev libssl-dev libgtest-dev
sudo apt-get install cd /usr/src/gtest && sudo cmake CMakeLists.txt -Dgtest_disable_pthreads=ON && sudo make && sudo chmod o+x libgtest* && sudo mv libgtest* /usr/lib/
