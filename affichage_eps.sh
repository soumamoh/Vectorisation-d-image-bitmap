#!/bin/bash

b=$(basename $1)

if [ $2 = "N" ]
then  
    gv IMAGES_EPS/$b"_Normal.eps" &
elif [ $2 = "S" ]
then
    gv IMAGES_EPS/$b"_Segment.eps" &
elif [ $2 = "B2" ]
then
   gv IMAGES_EPS/$b"_Bezier2.eps" &
elif [ $2 = "B3" ]
then
    gv IMAGES_EPS/$b"_Bezier3.eps" &
else
    echo " error : option [ N/S/B2/B3 ]"
fi