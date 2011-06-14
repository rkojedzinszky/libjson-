#
# Regular cron jobs for the libjson package
#
0 4	* * *	root	[ -x /usr/bin/libjson_maintenance ] && /usr/bin/libjson_maintenance
