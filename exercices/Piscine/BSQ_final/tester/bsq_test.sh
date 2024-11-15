echo ""
echo "*---- BSQ TESTER ----*"
echo ""
echo "SET DENTISITY : 50%"
for i in 20 50 100 200 500 750 1000 10000;
do
	let "a=($i / 2)"
	./board.pl $i $i $a > map

	time ./bsq map | grep "real"
#	time ./bsq map
	
	echo "Size : $i x $i"
	echo "$a"
	rm map
done
echo ""
echo "TESTING DONE"

