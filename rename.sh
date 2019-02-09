
die() { echo "$*" 2>&1 ; exit 1 ; }

new_name=${1?:missing 1st argument: project name}

test -n "${new_name}" || die "empty project name"

#make cleanall

rename -v project_name "${new_name}" **/*

sed -i -e "s/project_name/${new_name}/" **/*
