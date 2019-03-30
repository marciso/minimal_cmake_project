#!/bin/bash

rsync_opts='-var'
die() { echo "ERROR: $*" 2>&1 ; exit 1 ; }

src_dir=$(cd $(dirname "$(readlink -f "$0")") && git rev-parse --show-toplevel)
dst_dir=${1?:missing 1st argument: destination directory (full path)}  # project name = basename(dst_dir)

test -n "${dst_dir}" || die "first argument empty, expected destination directory"
test -e "${dst_dir}" && die "destination directory already exists; choose a different destination or remove the directory"

dst_dir_=${dst_dir%%/}
new_name=${dst_dir_##*/}

test -n "${new_name}" || die "could not get new project name"

mkdir -p "${dst_dir}"
rsync ${rsync_opts} --exclude=.git/ --exclude=.*.un~ --exclude=*.sh "${src_dir}/" "${dst_dir}/"
rsync ${rsync_opts} "${src_dir}/rename.sh" "${dst_dir}/rename.sh"

( cd "${dst_dir}"; ./rename.sh "${new_name}" ; )

rm -v "${dst_dir}/rename.sh"

( cd "${dst_dir}" && git init && git add -v . && git commit -v -m "${new_name} started" )
