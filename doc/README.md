Dollar Core
=============

Setup
---------------------
Dollar Core is the original Dollar client and it builds the backbone of the network. It downloads and, by default, stores the entire history of Dollar transactions (which is currently more than 100 GBs); depending on the speed of your computer and network connection, the synchronization process can take anywhere from a few hours to a day or more.

To download Dollar Core, visit [dollarcore.org](https://dollarcore.org/en/releases/).

Running
---------------------
The following are some helpful notes on how to run Dollar Core on your native platform.

### Unix

Unpack the files into a directory and run:

- `bin/dollar-qt` (GUI) or
- `bin/dollard` (headless)

### Windows

Unpack the files into a directory, and then run dollar-qt.exe.

### macOS

Drag Dollar Core to your applications folder, and then run Dollar Core.

### Need Help?

* See the documentation at the [Dollar Wiki](https://en.dollar.it/wiki/Main_Page)
for help and more information.
* Ask for help on [#dollar](http://webchat.freenode.net?channels=dollar) on Freenode. If you don't have an IRC client use [webchat here](http://webchat.freenode.net?channels=dollar).
* Ask for help on the [DollarTalk](https://dollartalk.org/) forums, in the [Technical Support board](https://dollartalk.org/index.php?board=4.0).

Building
---------------------
The following are developer notes on how to build Dollar Core on your native platform. They are not complete guides, but include notes on the necessary libraries, compile flags, etc.

- [Dependencies](dependencies.md)
- [macOS Build Notes](build-osx.md)
- [Unix Build Notes](build-unix.md)
- [Windows Build Notes](build-windows.md)
- [OpenBSD Build Notes](build-openbsd.md)
- [NetBSD Build Notes](build-netbsd.md)
- [Gitian Building Guide](gitian-building.md)

Development
---------------------
The Dollar repo's [root README](/README.md) contains relevant information on the development process and automated testing.

- [Developer Notes](developer-notes.md)
- [Release Notes](release-notes.md)
- [Release Process](release-process.md)
- [Source Code Documentation (External Link)](https://dev.visucore.com/dollar/doxygen/)
- [Translation Process](translation_process.md)
- [Translation Strings Policy](translation_strings_policy.md)
- [Travis CI](travis-ci.md)
- [Unauthenticated REST Interface](REST-interface.md)
- [Shared Libraries](shared-libraries.md)
- [BIPS](bips.md)
- [Dnsseed Policy](dnsseed-policy.md)
- [Benchmarking](benchmarking.md)

### Resources
* Discuss on the [DollarTalk](https://dollartalk.org/) forums, in the [Development & Technical Discussion board](https://dollartalk.org/index.php?board=6.0).
* Discuss project-specific development on #dollar-core-dev on Freenode. If you don't have an IRC client use [webchat here](http://webchat.freenode.net/?channels=dollar-core-dev).
* Discuss general Dollar development on #dollar-dev on Freenode. If you don't have an IRC client use [webchat here](http://webchat.freenode.net/?channels=dollar-dev).

### Miscellaneous
- [Assets Attribution](assets-attribution.md)
- [Files](files.md)
- [Fuzz-testing](fuzzing.md)
- [Reduce Traffic](reduce-traffic.md)
- [Tor Support](tor.md)
- [Init Scripts (systemd/upstart/openrc)](init.md)
- [ZMQ](zmq.md)

License
---------------------
Distributed under the [MIT software license](/COPYING).
This product includes software developed by the OpenSSL Project for use in the [OpenSSL Toolkit](https://www.openssl.org/). This product includes
cryptographic software written by Eric Young ([eay@cryptsoft.com](mailto:eay@cryptsoft.com)), and UPnP software written by Thomas Bernard.
