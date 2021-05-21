cmake_minimum_required(VERSION 3.17)
project(AVL_Trees)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(src)

add_executable(AVL_Trees
        src/CBinaryNode.tpp
        src/CBinaryNode.h
        src/CBinaryNodeTree.tpp
        src/CBinaryNodeTree.h
        src/CBinaryTreeInterface.h
        src/CBST.tpp
        src/CBST.H
        src/CMakeLists.txt
        src/CPersonInfo.cpp
        src/CPersonInfo.h
        src/main.cpp
        src/PersonBankInfo.txt
        src/PrecondViolatedExcept.cpp
        src/PrecondViolatedExcept.h
        README.md)
