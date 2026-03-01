#!/usr/bin/env bash
set -euox pipefail
main() {
    wget -O ./third_party/catch.3.13.0.tar.gz \
        "https://github.com/catchorg/Catch2/archive/refs/tags/v3.13.0.tar.gz"
}
main
