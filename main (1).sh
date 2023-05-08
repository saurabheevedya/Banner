#!/bin/bash

        # addition
        
# read x
# read y 

# sum=$(( $x + $y))
# echo "addition is $sum"


#       even and odd

# read n
# if [ $((n%2)) -eq 0 ]
# then
#     echo " $n is even"
# else
#     echo " $n is odd "
# fi

#       reverse

# read n 
# echo "the vaue is $n "
# n1=$n
# num = 0
# on=$n
# while[ $n -gt 0]
# do
# num=$(expr $num\*10)
# k=$(expr $n % 10)


#    prime

# num=5
# for((i=2;i<=num/2;i++))
# do
#     if [ $((num%i)) -eq 0 ]
#     then 
#         echo "$num is composite number"
#         exit
#     fi
# done
# echo "$num is a prime"


#  palindrome of string or number

# read inp
# reverse=""

# len=${#inp}
# for(( i=$len-1 ; i>=0; i--))
# do
#     reverse="$reverse${inp:$i:1}"
# done
# if [ $inp == $reverse ]
# then
#     echo "$n is palindrome"
# else
#     echo "$n is not palindrome"
# fi


#      reverse 

# read inp
# reverse=""

# len=${#inp}
# for(( i=$len-1 ; i>=0; i--))
# do
#     reverse="$reverse${inp:$i:1}"
# done
# echo $reverse

#    factorial recursively

# factorial(){
#     if (( $1 <= 1 )) 
#     then
#         echo 1
#     else
#         echo $(($1 *$(factorial $(($1 - 1 )))))
#     fi
# }
# read n
# result=$(factorial $n)
# echo "$result"


#   calculating factorial non recursively

# read n

# fact=1

# for((i=2; i<=n; i++))
# {
#     fact=$((fact * i))
# }
# echo $fact

#           Sorting an array

# arr=(34 35 76 12 1 3)
# length=6
# for((i=0;i<length;i++))
# do
#     for((j=i;j<length;j++))
#     do
#         if((${arr[i]}>${arr[j]}))
#         then
#             temp=${arr[i]}
#             arr[i]=${arr[j]}
#             arr[j]=$temp
#         fi
#     done
# done
# echo ${arr[@]}














