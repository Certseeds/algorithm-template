#!/usr/bin/env bash
set -eoux pipefail
###
# @Author: nanoseeds
# @Date: 2020-07-27 21:48:41
###
cmake_path="cmake_build_path"
scratch=""
function cmake_build() {
  cmake -E make_directory ./"${cmake_path}"
  cd ./"${cmake_path}"
  cmake .. -DCMAKE_BUILD_TYPE=DEBUG
  cmake --build . --config DEBUG --parallel $(nproc)
  # now at ./../cmake_build_path
}
function set_scratch() {
  cd ..
  scratch="$(pwd)/${cmake_path}"
  trap finish EXIT
}
function main() {
  set_scratch
  cmake_build
  ctest # or make test
  cd ..
  # now at ./../
}
function finish() {
  rm -rf "${scratch}"
}
# now in ./

main
