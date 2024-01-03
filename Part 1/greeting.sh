#!/bin/bash

temph=`date | cut -c12-13`
dat=`date +"%A %d in %B of %Y (%r)"`

if [ $temph -lt 12 ]
then
    msg="Good Morning $LOGNAME, Have a nice day!"
elif [ $temph -ge 12 -a $temph -le 16 ]
then
    msg="Good Afternoon $LOGNAME"
elif [ $temph -gt 16 -a $temph -le 20 ]
then
    msg="Good Evening $LOGNAME"
else
    msg="Hello $LOGNAME!"
fi

# Delete the greetingmsg file if it exists
if [ -e greetingmsg ]
then
    rm greetingmsg
fi

# Output the greeting message to greetingmsg file
echo -e "$msg\nToday is $dat" > greetingmsg
