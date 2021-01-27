#! /bin/bash

# Имя пользователя, текущее время, дата, текущий каталог, число процессов в системе, время работы

echo "current session statistic"
echo "current username : $USER"
echo "current date : `date`"
echo "current directory : `pwd`"
echo "count of processes : `ps -e | wc -l` "
echo "running time : `uptime -p`"
