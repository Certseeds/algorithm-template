#!/usr/bin/env bash
set -euox pipefail
main() {
	# 定位到脚本所在目录（third_party）
	local -r self_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
	local -r tp_dir="$self_dir"

	# 开启大小写不敏感匹配以识别 Catch-/catch-
    for path in "$tp_dir"/*; do
        [[ -d "$path" ]] || continue
        local name="$(basename -- "$path")"

        if [[ "$name" == Catch2* ]]; then
            mv "./third_party/$name" "./third_party/catch2"
            echo "Renamed '$name' -> 'catch2'"
            exit 0
        fi
	done
}
main
