cat /etc/passwd \
| cut -d '#' -f1 \
| cut -d ':' -f1 \
| awk "NR % 2 == 0" \
| rev \
| sort -r \
| awk "NR==${FT_LINE1}, NR==${FT_LINE2}" \
| tr "\n" "," \
| sed 's/,/, /g' \
| sed 's/, $/./'
