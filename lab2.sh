# !/bin/bash

rand_value=$(date +%s)
rand_max=32767

rand (){ 
	rand_value=$(($((rand_value*1103515245+12345))%rand_max));
}

screensaver(){
	while true
	do
		clear
		rand
		row=$((rand_value%$(tput lines)))
		col=$((rand_value%$(tput cols)))

		echo -e "\e[${row};${col}H$(date +"%H:%M")"

		sleep 3 
	done
}

screensaver

