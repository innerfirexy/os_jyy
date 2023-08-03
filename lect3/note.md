Legacy BIOS 把第一个可引导设备的第一个512字节加载到物理内存7c00位置

Firmwere load MBR 0x7c00

虽然最多只有446字节

让chatgpt写一个mbr上的 hello world

有没有可能我们真的去看从CPU Reset 以后每一条指令的执行（到底是什么？做了什么？
公理：你想到的就一定有人做到

- 模拟方案：QEMU
    - QEMU, a fast and portable dynamic translator
    - Android virtual devie, VirtualBox, 背后都是它🗼
- 真机方案：JTAG (Joint Test Action Group) debugger

# 16位 汇编
定义一个512字节的扇区