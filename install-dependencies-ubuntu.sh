#!/bin/sh
sudo apt-get install -y libboost-filesystem-dev libboost-system-dev liblog4cplus-dev libgraphicsmagick++1-dev libssl-dev libgtest-dev
cd /usr/src/gtest && sudo cmake CMakeLists.txt -Dgtest_disable_pthreads=ON && sudo make && sudo chmod o+x libgtest* && sudo mv libgtest* /usr/local/lib/
