#!/bin/bash

ARCH_KVER=$(uname -mr)
CPU_AMOUNT=$(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l)
VCPU_AMOUNT=$(grep "processor" /proc/cpuinfo | wc -l)
RAM_MAX=$(free --mega | grep "Mem" | awk '{print $2}')
RAM_USED=$(free --mega | grep "Mem"| awk '{print $3}')
RAM_PERC=$(free | grep "Mem" | awk '{printf("%.2f%%"), $3/$2*100}')
DISK_MAX=$(df -h --total | grep "total" | awk '{print $2}')
DISK_USED=$(df -h --total | grep "total" |awk '{print $3}')
DISK_PERC=$(df -k --total | grep "total" | awk '{print $5}')
CPU_LOAD=$(grep 'cpu ' /proc/stat | awk '{usage=($2+$4)*100/($2+$4+$5); printf "%.2f%%", usage}')
LAST_REBOOT=$(who -b | awk '{print $3 " " $4}')
LVM_STATUS=$(if [ $(lsblk | grep "lvm" | wc -l) -eq 0 ]; then echo no; else echo yes; fi)
CONNECTIONS=$(ss -Ht state established | wc -l)
USER_COUNT=$(who | wc -l)
IP=$(hostname -I)
MAC=$(ip link | grep "ether" | awk '{print $2}')
SUDO_CMDS=$(grep COMMAND /var/log/sudo/sudo.log | wc -l)

wall "
         ______________________.frnki________________________
        | 
        |       #Architecture: $ARCH_KVER
        |       #CPU physical: $CPU_AMOUNT
        |       #vCPU: $VCPU_AMOUNT
        |       #Memory Usage: $RAM_USED/${RAM_MAX}MB ($RAM_PERC)
        |       #Disk Usage: $DISK_USED/${DISK_MAX} ($DISK_PERC)
        |       #CPU load: $CPU_LOAD
        |       #Last boot: $LAST_REBOOT
        |       #LVM use: $LVM_STATUS
        |       #Connections TCP: $CONNECTIONS ESTABLISHED
        |       #User log: $USER_COUNT
        |       #Network: IP $IP ($MAC)
        |       #Sudo: $SUDO_CMDS cmd
        |_____________________@42vienna______________________"

