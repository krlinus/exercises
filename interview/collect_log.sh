for h in 01 05 10 15 20 25 30
do
    for colo in gq1 ne1 bf1 sg3 ir2
    do
        host ad00${h}.yax.${colo}.yahoo.com > /dev/null
        if [ $? -ne 0 ]
        then echo "Skipping ad00${h}.yax.${colo}.yahoo.com"
        else
            scp ad00${h}.yax.${colo}.yahoo.com:~/partner_id_counts3 ./ad00${h}.yax.${colo}.log
        fi
    done
done

