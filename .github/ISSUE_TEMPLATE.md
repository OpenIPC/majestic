<!--
Github issues are used for bug reports. For support questions, please use [our telegram](https://openipc.org/about/#resources-and-links).

Please fill the template below as it will greatly help us track down your issue and reproduce it on our side.
Feel free to remove anything which doesn't apply to you and add more information where it makes sense.
-->

# Required information

 * Camera board id:
 * OpenIPC version:
 * Commit:
 * Branch:
 * Tag:
 * installation method: (by manual https://github.com/OpenIPC/openipc-2.1/wiki/install_hisi or another)
 * modified majestic.yaml: yes/no
 * cat /dev/kmsg
 * killall majestic
   ulimit -c unlimited
   echo /tmp/%e.%p.%s.%t.core > /proc/sys/kernel/core_pattern
   majestic
   Core dump file from /tmp/ , e.g. /tmp/majestic.806.11.1619707881.core

# Issue description

A brief description of the problem. Should include what you were
attempting to do, what you did, what happened and what you expected to
see happen.

# Expectations

# Steps to reproduce

 1. Step one
 2. Step two
 3. Step three

# Information to attach

 - [ ] Any relevant log output (`logread -f`)
 - [ ] majestic.yaml configuration (`cat /etc/majestic.yaml`)

