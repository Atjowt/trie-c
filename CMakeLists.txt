cmake_minimum_required(VERSION 3.0.0)
project(trie-c VERSION 0.2.0 LANGUAGES C)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_library(trie-c src/trie.c)
target_include_directories(trie-c PUBLIC include)
