#!/usr/bin/env bash
set -euox pipefail
main() {
    wget -O ./third_party/catch2.tar.gz \
        "https://github.com/catchorg/Catch2/archive/refs/tags/v3.10.0.tar.gz"
}
main
