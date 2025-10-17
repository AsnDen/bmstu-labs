#!/bin/bash

if [ -z $1 ]; then
	echo "Пожалуйста, введите ваше имя"
	exit 1
else
	echo "Привет, $1!"
fi
