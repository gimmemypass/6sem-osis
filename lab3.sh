# !/bin/bash

value=$(<file.txt)
declare -a lines

while read line
do
	lines+=("$line")
done < "file.txt"

i=0
for line in "${lines[@]}"
do
#	echo "$line" | sed 's/[\r\.\?\!]\s*[a-zа-я]/\U&/g' | sed 's/[a-zа-я]/\u&/'
	newLine=`echo "$line" | sed 's/[\r\.\?\!]\s*[a-zа-я]/\U&/g'`
	if [[ $i == 0 ]] 
	then
		newLine=`echo "$newLine" | sed 's/[a-zа-я]/\u&/'`
	elif [[ `echo "$prevLine" | sed '/[\.\?\!]\s*$/!d'` != "" ]]
	then
		newLine=`echo "$newLine" | sed 's/[a-zа-я]/\u&/'`
	fi
	echo "$newLine"
	prevLine="$newLine"
	i=$i+1
	
done






