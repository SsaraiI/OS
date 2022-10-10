fileName="p*.c"
#printf "name\t\tScore\n"
for i in $fileName
do
    prog_name=$(echo $i | cut -d'.' -f1)
    gcc -o $prog_name $i |& grep -i 'warning' $i 2>/dev/null
    if [ -f $prog_name ]
    then
        ans=$(./$prog_name)
        if [ $ans -eq 20 ]
        then
            cnt=10
        else
            cnt=7
        fi
    else 
        cnt=5
    fi
    printf "%s\t\t%s\n" $i $cnt
done