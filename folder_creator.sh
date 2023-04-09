#! /bin/bash

counter=0
while [ $counter -le 2 ]
do
	mkdir "ex0$counter"
	((counter++))
done

echo ALL DONE