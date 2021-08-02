# Cross C++
Cross platform C++ CMake boilerplate with commonly used scientific libraries.

<img src="https://upload.wikimedia.org/wikipedia/commons/1/18/ISO_C%2B%2B_Logo.svg" width = "16"> <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/1/13/Cmake.svg/900px-Cmake.svg.png" width = "16"> <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/b/b0/NewTux.svg/800px-NewTux.svg.png" width ="16"> <img src="https://upload.wikimedia.org/wikipedia/commons/5/5f/Windows_logo_-_2012.svg" width = "16"> <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/2/22/MacOS_logo_%282017%29.svg/512px-MacOS_logo_%282017%29.svg.png" width = "16">


![GitHub forks](https://img.shields.io/github/forks/siddharthdeore/CrossCPP?style=flat-square)
![GitHub Repo stars](https://img.shields.io/github/stars/siddharthdeore/CrossCPP?style=flat-square)
![GitHub commit activity](https://img.shields.io/github/commit-activity/w/siddharthdeore/CrossCPP?style=flat-square)


## Libraries 
- [Eigen](https://eigen.tuxfamily.org/index.php?title=Main_Page)
- [Boost C++ Libraries](https://www.boost.org/)

# Getting Started
## Boost Installation 
-  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/b/b0/NewTux.svg/800px-NewTux.svg.png" width ="14">  <b>Linux</b>
    ```sh
    sudo apt-get update
    sudo apt-get install libboost-all-dev
    ```
---
-  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/2/22/MacOS_logo_%282017%29.svg/512px-MacOS_logo_%282017%29.svg.png" width = "14">  <b>MacOS</b> 

    To install boost on MacOS with macports
    ```sh
    sudo port install boost 
    ```
    or with homebrew
    ```sh
    brew install boost
    ```
---
-  <img src="https://upload.wikimedia.org/wikipedia/commons/5/5f/Windows_logo_-_2012.svg" width = "14">    <b>Windows</b> 
  
    - Download boost source code from https://www.boost.org/users/download/
    - Extract boost to prefered location e.g. for boost 1.76.0 extract  the downloaded archive at "C:\Program Files\boost_1_76_0"
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

# Build Instruction

```sh
git clone https://github.com/siddharthdeore/CrossCPP.git --depth 1 <your-reopo-name>
cd <your-reopo-name>
mkdir build
cd build
cmake ..
```
Push project to remote repository
```sh
git commit --amend .
```


Proposed source code directory structure.
```sh
├───bin                         # target executables and libraries
│   ├───Debug
│   └───Release
│
├───cmake                       # cmake modules
│
├───build                       # build files (eg. makefile or .sln)
│
├───utils                       # utilities
│
├───libraries                   # target libraries
│   ├───RigidBody
│   │   ├───src
│   │   └───include
│   │   
│   ├───Rotation
│   |     :
│   └───my_lib_n
│
├───Projects 
│
├───examples
│   ├───01_eigen
│   ├───02_boost_header_only       
│   ├───03_boost_chrono       
│   └───04_Rigid_Body
│
├───external                    # external libraries
│   ├───eigen
│   ├───other_external_lib
│   |     :
│   └───fancy_library
│
└───CMakeLists.txt              # cmake entry point

```

## Maintainers
This repository is maintained by:
|<img src="https://github.com/siddharthdeore.png" width="32">| [siddharth deore](https://github.com/siddharthdeore)|
|--|--|
