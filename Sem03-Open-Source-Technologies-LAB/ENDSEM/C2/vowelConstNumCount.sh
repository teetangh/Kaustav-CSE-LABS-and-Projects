#!/bin/sh

echo -n "Enter a line of text: "
read string

numCount=$(echo $string | grep -o "[0-9]" | wc --lines)
vowCount=$(echo $string | grep -o -i "[aeiou]" | wc --lines)
consCount=$(echo $string | grep -o -i "[bcdfghjklmnpqrstvwxyz]" | wc --lines)

echo "The given string has $vowCount vowels, $consCount consonants and $numCount numbers in it."
