if [ $# -eq 1 ]
then
	N=$1
else
	N=500
fi
ARG=$(shuf -i 0-10000000 -n $N | tr "\n" " ")
echo $ARG
CMD="./push_swap $ARG | wc -l"
STEPS=$(eval $CMD)
echo $STEPS
CMD="./push_swap $ARG | ./checker_linux $ARG"
eval $CMD
