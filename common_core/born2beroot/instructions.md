# Commands

I. Groups and users:
- Create a new group:	```sudo groupadd groupname```
- List all groups:	```cat /etc/group```
- Assign a user to a group:	
- Create a new user	```sudo adduser username```
- Assign/change a password for a user	```passwd username```
- Change password policies	```sudo nano /etc/security/pwquality.conf```
- Change password age, warnings …	```sudo nano /etc/login.defs```
- Look for a user	```cat /etc/pqsswd | grep user```
- Delete a user	```userdel username```

II. Firewalls and SSH:

- Allow port with ufw	sudo ufw ```allow portnumber or servicename```
- List all active rules with ufw	```sudo ufw status```
- Delete a rule with ufw	```sudo delete numberofrole```
- Check status, manage a service	```sudo systemctl option (status, enable, restart … ) servicename```
- Change ssh port	```sudo nano /etc/ssh/sshd_config```
- Connect to a vm using ssh	```ssh username@ip -p port```
- Kill any service running at a specific port	```fuser -k pid/tcp or by stopping the service.```


III. System  and Sudo Policies:

- Change hostname	```sudo hostnamectl set-hostname``` 
- Change Sudo policies	```sudo cat /etc/sudoers```


# Bonus

1 . Set up the additional partitions during the installation of the OS.

2. To install Wordpress with MariaDB and Lighttpd in your Virtual Machine:
	- Install php & its dependicies:

	+ Using a package manager such as dnf, ```install mariadb-server``` and enable / start it.
     + Manage it using ‘mysql’ command using sudo.
     + Database creation:	```Create database dbname```
     + grant db permissions to a user: ```Grant all on dbname.* to user@localhost identified by ‘strOng/passw0rd’```.
     + Connect to db with the user assigned	Mysql -u user - p dbname;