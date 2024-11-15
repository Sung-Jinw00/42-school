X=$(echo $FT_NBR1 \
	| tr "'" "0" \
	| tr '\\' "1" \
	| tr '"' "2" \
	| tr '?' "3" \
	| tr '!' "4")
Y=$(echo $FT_NBR2 | tr "mrdoc" "01234")
SOMME=$(echo "$X + $Y")
BASE_13=$(echo "obase=13;ibase=5;$SOMME" | bc)
echo $BASE_13 \
	| tr '0' 'g' \
	| tr '1' 't' \
	| tr '2' 'a' \
	| tr '3' 'i' \
	| tr '4' 'o' \
	| tr '5' ' ' \
	| tr '6' 'l' \
	| tr '7' 'u' \
	| tr '8' 'S' \
	| tr '9' 'n' \
	| tr 'A' 'e' \
	| tr 'B' 'm' \
	| tr 'C' 'f'