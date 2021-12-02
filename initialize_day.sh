#!/bin/bash

#Function for -h options, displaying the help
Help()
{
    echo 
    echo "####################################################"
    echo
    echo "This is a script I made for AOC 2021!"
    echo "To use it, just follow the parameter format below"
    echo
    echo "Format: ./initialize_day.sh Day-<XX>"
    echo
    echo "####################################################"
    echo
}

if [ $# -eq 0 ]
    then
        echo "ERROR: No arguments passed"
        echo "please use -h for help"
        exit 1
fi

# Get the options
while getopts ":hd:" option; do
    case $option in
        h) #display Help
            Help
            exit;;

        #d) #Enter the day number
            #Day=$OPTARG;;

        \?) #display error
            echo "Error: Invalid Option, use -h for help"
            exit;;
    esac
done

# Set variables
Day=$1

echo "Making $Day"
mkdir $Day && cd $Day
touch "${Day}_part1.cpp"
touch "${Day}_part2.cpp"
touch "input.in"
cat ../skeleton.cpp > "${Day}_part1.cpp"
cat ../skeleton.cpp > "${Day}_part2.cpp"



