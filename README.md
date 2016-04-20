# zfbsd-ports
Zirias' FreeBSD ports tree. This tree contains ports I'm working on.
They are organized as follows:

 - **new**: ports in here are not in the official FreeBSD ports.
   This could mean *not yet*, but doesn't have to, some ports will probably
   stay here.

 - **current**: these ports are part of the official FreeBSD ports tree.
   They are here because I currently work on them or because I'm the maintainer.

 - **obsolete**: **DO NOT USE THESE!** Ports in this directory are no longer in
   the official FreeBSD ports, and normally, there is a good reason for that.
   **They will probably impair the security of your system.** My reason for
   adding this was just experimentation: Does it work on a recent FreeBSD system?
   So, look here maybe out of historic interest, but be aware of the implications.

Below these directories follow the standard directories for the *primary category*
of the port.

## How to use
Just `git clone` the tree whereever you like. Referenced dependencies will be
looked for in your standard ports tree. Note this is a tree for active work on
the ports, so not every commit will lead to a buildable state. I will, however,
try to only push buildable states.
