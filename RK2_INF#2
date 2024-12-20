#!/bin/bash

if["$#" - ne 2]; then
echo "Please , write directory and file extention."
exit 1
fi

DIRECTORY = \$1
EXTENSION = \$2

if[!- d "$DIRECTORY"]; then
echo "Derectory not found."
exit 1
fi

FILES = $(find "$DIRECTORY" - type f - name "*.$EXTENSION")

if[-z "$FILES"]; then
echo "Files with extention $EXTENSION not found."
else
echo "Founded files wuth extention $EXTENSION:"
echo "$FILES"
fi
