#!/bin/bash

read dir
cd $dir
if [ $? -eq 0 ]
then

	#  guid = $(ls -aln | head -2 | tail -1 | awk '{ $0 = $4 }')
	# gw = $(ls -aln | head -2 | tail -1 | awk '  $0 = /....w.*/   ')
	# ow = $(ls -aln | head -2 | tail -1 | awk '  $0 = /.......w./ ')
	if [ $(ls -aln | head -2 | tail -1 | awk '  $0 = /.......w./ ') ]
	then 
		
		cat /etc/passwd |  sed 's/:.*//' /etc/passwd 
		
	else	

		if [ $(ls -aln | head -2 | tail -1 | awk '  $0 = /....w.*/   ') ]
		then
    		  cat /etc/group | awk  -F':' -v guid=$(ls -aln | head -2 | tail -1 | awk -F' ' ' $0=$4 ')  ' { if  ($3 == guid) $0=$4 } '
		 
			cat /etc/passwd |  awk  -F':' -v guid=$(ls -aln | head -2 | tail -1 | awk -F' ' ' $0=$4 ')  ' $4 == guid ' | awk -F':' '$0=$1'
		
		else 
		if [ $(ls -aln | head -2 | tail -1 | awk '  $0 = /..w*/   ') ]	
		then
			cat /etc/passwd |  awk  -F':' -v uid=$(ls -aln | head -2 | tail -1 | awk -F' ' ' $0=$3 ')  ' $4 == uid ' | awk -F':' '$0=$1'			
		fi	
		fi
	fi
	
fi
