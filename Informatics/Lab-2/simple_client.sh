#!/bin/bash

while true;
do
	read message
	if [[ $message = exit ]]
	 then
		break
	fi
	echo "$message" | nc localhost 12345
done
