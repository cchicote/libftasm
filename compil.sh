nasm -f macho64 $1.s -o $1.o
ld $1.o -macosx_version_min 10.8 -lSystem -o $1
./$1
rm -rf $1.o
