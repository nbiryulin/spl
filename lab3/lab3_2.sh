#!/bin/bash

touch tmp 
echo "a" > tmp
echo "b" > tmp
if [ $? -ne 0 ] 
then 
	for i in {1..$(ls | wc -l)}
	do
		if [ $(ls -l | awk -v i=$i 'NR==i' | awk '  $0 = /.......w./ ') ]
		then 
			ls -1 | awk -v i=$i 'NR==i'
		else
			if [ $(ls -l | awk -v i=$(ls | wc -l) 'NR==i' | awk ' $0 = /....w.*/ ') ] 
			then	
				VAR=$(ls -l | awk -v i=$(ls | wc -l) 'NR==i' | awk '$0=$4')	
				if [[ groups == *$VAR*  ]]
				then
					ls -1 | awk -v i=$i 'NR==i'
				fi	
			else
				if [ $(ls -l | awk -v i=$i 'NR==i' | awk ' $0 = /..w*/  ') ] 
				then
					if [ $(whoami | grep $(ls -l | awk -v i=$(ls | wc -l) 'NR==i' | awk '$0=$3')) ]	
					then
						ls -1 | awk -v i=$i 'NR==i'
					fi
				fi
			fi
		fi
	done
fi

