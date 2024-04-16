#!/bin/bash

d=$(basename $1)
cp IMAGES/$d .
./test_image $d $2 $3
b=$(basename $d .pbm)
n=$(echo $b"_Normal.eps")
s=$(echo $b"_Segment.eps")
b2=$(echo $b"_Bezier2.eps")
b3=$(echo $b"_Bezier3.eps")
mv $n IMAGES_EPS/$n
mv $s IMAGES_EPS/$s
mv $b2 IMAGES_EPS/$b2
mv $b3 IMAGES_EPS/$b3
rm $d