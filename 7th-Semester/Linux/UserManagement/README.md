
## User Management

```sh
Q. Show all user information
cd /etc
cat passwd
or
cat /etc/passwd

Q. Display only top user info
A. head -5 /etc/passwd

Q.Display last info
A. tail -1 /etc/passwd

```

### Write a command to crate user pokhara with comment pokhara city and user id 550 along with shell csh.

```sh
A. sudo useradd -c "pokhara city" -u 550 -s /bin/csh pokhara

Q. For setting password
A. sudo passwd pokhara

Q. For modify shell
A. sudo usermod -s /bin/bash pokhara

Q. For Delete user
A. sudo userdel pokhara
```

### Create user with following informations

```sh
name :bca
comment : bachelor of computer application
user id: 700
home directory: /downloads/bcary
shell: /bin/bash
expre date: 2020-02-30

A. sudo useradd -c "Bachelor of Computer Application" -u 700 -d /home/debid/Downloads/bca -s /bin/bash -e 2020-02-30 bca
```

### How to create group

```sh
Q. Create a gorup "account"
A. sudo groupadd Account

Q. Create user peter
A. sudo useradd peter

Q. Add userpeter to group account
A. sudo usermod -G Account peter

Q. Create another group library
A. sudo groupadd Library

Q. Add user to both group
A. sudo usermod -a -G Library peter

Q. Change the name of library to Exam
A. sudo groupmod -n Exam Library

```
