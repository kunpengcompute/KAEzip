# Kunpeng Zlib Acceleration Engine

- [Introduction](#introduction)
- [License](#license)
- [Requirements](#requirements)
- [Installation Instructions](#installation-instructions)
- [More Information](#more-information)
- [Copyright](#Copyright)

## Introduction

Kunpeng Zlib Acceleration Engine，which is a new technology within Hisilicon Kunpeng 920 processors，provides a hardware-enabled foundation for  compression. It significantly increases the performance across cloud, big data, and storage applications and  platforms.  By using  Kunpeng Zlib Acceleration Engine, you can:

- Have higher-performance compression and decompression
- Maximize CPU utilization

The compression and decompression algorithm supported by Kunpeng Acceleration Engine are:  gzip/zlib 

## License

It is licensed under the zlib License(https://www.zlib.net/zlib_license.html ). For more information, see the LICENSE file. 

## Requirements

- CPU: Kunpeng 920 
- Operating System: 
  - CentOS 7.6  4.14.0-115.el7a.0.1.aarch64 version
  - SuSE 15.1 4.12.14-195-default arch64 version
  - NeoKylin 7.6 4.14.0-115.5.1.el7a.06.aarch64 version
  - EulerOS 2.8 4.19.36-vhulk1907.1.0.h410.eulerosv2r8.aarch64 version

## Installation Instructions

Clone the Github repository containing the Kunpeng Accelerator Engine Driver:

```
git clone https://github.com/kunpengcompute/KAEzip
```

There are two version of zlib you can choose to enable acceleration. If zlib version is 1.2.11, follow installation as below:

```
cd KAEzip
tar -zxf zlib-1.2.11.tar.gz 
cd zlib-1.2.11
patch -Np1 < ../kunpeng_zlib_1.0.0.patch
./configure --prefix=/usr/local/zlib
make clean && make 
make install
```

 If zlib version is 1.2.7, follow installation as below:

```
cd KAEzip 
rpm -i zlib-1.2.7-18.el7.src.rpm 
mv /root/rpmbuild/SOURCES/zlib-1.2* . 
tar -jxvf zlib-1.2.7.tar.bz2 
cd zlib-1.2.7/ 
patch -Np1 < ../zlib-1.2.5-minizip-fixuncrypt.patch 
patch -Np1 < ../zlib-1.2.7-z-block-flush.patch 
patch -Np1 < ../zlib-1.2.7-fix-serious-but-very-rare-decompression-bug-in-inftr.patch 
patch -Np1 < ../zlib-1.2.7-Fix-bug-where-gzopen-gzclose-would-write-an-empty-fi.patch 
patch -Np1 < ../kunpeng_zlib_centos7.6_1.0.1.patch 
./configure --prefix=/usr/local/zlib  
make clean && make   
make install
```

Note: The `zlib-1.2.7-18.el7.src.rpm` package was download from <https://www.centos.org/>.

## More Information

For further assistance, contact Huawei Support at:

<https://support.huawei.com>

## Copyright

Copyright © 2018 Huawei Corporation. All rights reserved.