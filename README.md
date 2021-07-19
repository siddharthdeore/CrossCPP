# Cross C++
Cross Platform C++ CMake toolchain Boilerplate Template with commonly used scientific libraries.

## Libraries
- [Eigen](https://eigen.tuxfamily.org/index.php?title=Main_Page)
- [Boost C++ Libraries](https://www.boost.org/)
## Getting Started
```sh
git clone https://github.com/siddharthdeore/CrossCPP.git
cd CrossCPP
mkdir build
cd build
cmake ..
```
### 
### <b> Boost Installation </b>
### <b>Linux</b>
```sh
sudo apt-get update
sudo apt-get install libboost-all-dev
```
### <b>Windows</b>
 - Download boost source code from https://www.boost.org/users/download/
 - Extract boost to prefered location e.g. for boost 1.76.0 extract at "C:\Program Files\boost_1_76_0"
 - change current direcectory to boost extracted directory
```dos
cd "C:\Program Files\boost_1_76_0"
bootstrap.bat
b2
```
This will build both debug and release static libraries for default architecture, and at the end will notify location of compiler include paths, and linker library path. 
For detail build instruction refer [Boost Build Guide](https://www.boost.org/build/doc/html/bbv2/overview/invocation.html). Set windows envirnoments as follow :

| Variable | Value |
--|--
|BOOST_ROOT          | "C:\Program Files\boost_1_76_0"|
|BOOST_INCLUDEDIR    | "C:\Program Files\boost_1_76_0"|
|BOOST_LIBRARYDIR    | "C:\Program Files\boost_1_76_0\stage\lib"|


# Maintainers
This repository is maintained by:
| [<img src="https://github.com/siddharthdeore.png" width="40">](https://github.com/siddharthdeore)| [@siddharthdeore](https://github.com/siddharthdeore)|
--|--
