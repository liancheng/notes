###########
KVM性能优化
###########

:date: 2013/10/22
:speaker: 邱剑（美团）

http://mos.meituan.com

私有云+开放云

CPU

*   Context switch: IntelVT-x
*   Cache: qemu进程绑定至特定的core或node（taskset）

Memory

*   Addressing: EPT

    http://en.wikipedia.org/wiki/Second_Level_Address_Translation

*   (Transparent) HugePage

    khugepaged

    http://lwn.net/Articles/423584/

*   KSM (Kernel Same-page Merging)

    ksmd

    http://en.wikipedia.org/wiki/Kernel_SamePage_Merging_(KSM)

    https://access.redhat.com/site/documentation/en-US/Red_Hat_Enterprise_Linux/6/html/Virtualization_Administration_Guide/chap-KSM.html

IO

Paravirtualization/Virtio

*   Storage

    *   virtio-blk (PCI): /dev/vd\ *x*
    *   virtio-SCSI: /dev/sd\ *x*
    *   Page cache

        *   Host FS page cache
        *   Qemu blk driver writeback cache
        *   Guest FS page cache

        五种缓存模式

*   Network

    *   virtio-net
