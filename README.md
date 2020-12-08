# Kunpeng Zlib Acceleration Engine

- [Introduction](#introduction)
- [License](#license)
- [Requirements](#requirements)
- [Installation Instructions](#installation-instructions)
- [Test Performace](#test-performace)
- [Contribution guidelines](#contribution-guidelines)
- [More Information](#more-information)
- [Copyright](#copyright)

## Introduction

Kunpeng Zlib Acceleration Engine is to build performance competitiveness of common software libraries on the Kunpeng platform.

Kunpeng Zlib Acceleration Engine，which is a new technology within Hisilicon Kunpeng 920 processors，provides a hardware-enabled foundation for  compression. It significantly increases the performance across cloud, big data, and storage applications and  platforms.  By using  Kunpeng Zlib Acceleration Engine, you can:

- Have higher-performance compression and decompression
- Maximize CPU utilization

The compression and decompression algorithm supported by Kunpeng Acceleration Engine are:  gzip/zlib 

## License

It is licensed under the zlib License(https://www.zlib.net/zlib_license.html ). For more information, see the LICENSE file. 

## Requirements

- CPU: Kunpeng 920 
- Support Operating System: 
  - CentOS 7.6  4.14.0-115.el7a.0.1.aarch64 version
  - SuSE 15.1 4.12.14-195-default arch64 version
  - NeoKylin 7.6 4.14.0-115.5.1.el7a.06.aarch64 version
  - EulerOS 2.8 4.19.36-vhulk1907.1.0.h410.eulerosv2r8.aarch64 version
  - BCLinux-R7-U6-Server-aarch64 version
  - Kylin 4.0.2 (juniper) 4.15.0-70-generic version
  - Kylin release 4.0.2 (SP2) 4.19.36-vhulk1907.1.0.h403.ky4.aarch64 version
  - UniKylin Linux release 3(Core)  4.18.0-80.ky3.kb21.hw.aarch64 version
  - Ubuntu 18.04.1 LTS 4.15.0-29-generic version   

## Installation Instructions

Clone the Github repository containing the Kunpeng Accelerator Engine Driver:

```
git clone https://github.com/kunpengcompute/KAEzip
```

Download the release version of Kunpeng Accelerator Engine Driver from:

<https://github.com/kunpengcompute/KAEdriver/releases> 

Firstly, build and install the accelerator driver:
Note: To build the Kunpeng Accelerator Engine Driver, install the `kernel-devel` package first.

```
tar -zxf Kunpeng_KAE_driver.tar.gz
cd kae_driver
make
make install
modprobe uacce
modprobe hisi_qm
modprobe hisi_zip
```

Secondly, install the accelerator library:

```
cd warpdrive
sh autogen.sh 
./configure 
make 
make install
```

Then Install KAEzip library:

Download [zlib-1.2.11.tar.gz](https://www.zlib.net/zlib-1.2.11.tar.gz) at KAEzip/open_source.

```
cd KAEzip
sh setup.sh install
```

for more install guid and user guid, get information at:
<https://www.huaweicloud.com/kunpeng/software/kaezip.html>

## Test Performace

```
cd test
make
export LD_LIBRARY_PATH=/usr/local/kaezip/lib
./kaezip_perf -m 8 -l 1024 -n 1000
./kaezip_perf -m 8 -l 1024 -n 1000 -d
```
## Contribution guidelines

If you want to contribute to KAEzip, please use GitHub [issues](https://github.com/kunpengcompute/KAEzip/issues/new) for tracking requests and bugs.

## More Information

For further assistance and QA, contact Huawei Support at:

<https://www.huaweicloud.com/kunpeng/software/kaezip.html> 

## Copyright

Copyright © 2018 Huawei Corporation. All rights reserved.
