echo "Enter a number: " 
read n 
g=$n
i=`expr $n - 1` 
while [ $i -ge 1 ] 
do 
  n=`expr $n \* $i` 
  i=`expr $i - 1` 
done
echo "The factorial of given number is $g! =  $n" 

