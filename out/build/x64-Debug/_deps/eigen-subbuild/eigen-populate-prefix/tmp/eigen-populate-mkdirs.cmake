# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "E:/STUDIA/projekt-4/out/build/x64-Debug/_deps/eigen-src"
  "E:/STUDIA/projekt-4/out/build/x64-Debug/_deps/eigen-build"
  "E:/STUDIA/projekt-4/out/build/x64-Debug/_deps/eigen-subbuild/eigen-populate-prefix"
  "E:/STUDIA/projekt-4/out/build/x64-Debug/_deps/eigen-subbuild/eigen-populate-prefix/tmp"
  "E:/STUDIA/projekt-4/out/build/x64-Debug/_deps/eigen-subbuild/eigen-populate-prefix/src/eigen-populate-stamp"
  "E:/STUDIA/projekt-4/out/build/x64-Debug/_deps/eigen-subbuild/eigen-populate-prefix/src"
  "E:/STUDIA/projekt-4/out/build/x64-Debug/_deps/eigen-subbuild/eigen-populate-prefix/src/eigen-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "E:/STUDIA/projekt-4/out/build/x64-Debug/_deps/eigen-subbuild/eigen-populate-prefix/src/eigen-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "E:/STUDIA/projekt-4/out/build/x64-Debug/_deps/eigen-subbuild/eigen-populate-prefix/src/eigen-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
