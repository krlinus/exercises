for h in 01 05 10 15 20 25 30
do
    for colo in gq1 ne1 bf1 sg3 ir2
    do
        host ad00${h}.yax.${colo}.yahoo.com > /dev/null
        if [ $? -ne 0 ]
        then echo "Skipping ad00${h}.yax.${colo}.yahoo.com"
        else
            echo processing for ad00${h}.yax.${colo}.yahoo.com
            ssh ad00${h}.yax.${colo}.yahoo.com "rm -f ~/a.out ~/a2.out ~/a3.out"
            echo "copying a4.out"
            scp ./a4.out ad00${h}.yax.${colo}.yahoo.com:~/
            echo "chmoding a4.out"
            ssh ad00${h}.yax.${colo}.yahoo.com "chmod ugo+x ~/a4.out"
            echo "running grep in bg"
            ssh -f ad00${h}.yax.${colo}.yahoo.com "grep -oh \"PartnerId: [0-9]\+\" /home/y/logs/ssp_backend/ssp_backend.2018-05-15-* | ~/a4.out > ~/partner_id_counts3"
        fi
    done
done

