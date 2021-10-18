# SETTING UP ARM TOOLCHAIN ON UNIX (UBUNTU)

## Connect to your droplet
ssh root@...

## Installing the compiler (gcc-linaro)
wget https://releases.linaro.org/components/toolchain/binaries/7.3-2018.05/arm-linux-gnueabi/gcc-linaro-7.3.1-2018.05-x86_64_arm-linux-gnueabi.tar.xz
wget https://releases.linaro.org/components/toolchain/binaries/7.3-2018.05/arm-linux-gnueabi/sysroot-glibc-linaro-2.25-2018.05-arm-linux-gnueabi.tar.xz
tar -xf gcc-linaro-7.3.1-2018.05-x86_64_arm-linux-gnueabi.tar.xz
tar -xf sysroot-glibc-linaro-2.25-2018.05-arm-linux-gnueabi.tar.xz
mv gcc-linaro-7.3.1-2018.05-x86_64_arm-linux-gnueabi.tar.xz gcc-linaro
mv sysroot-glibc-linaro-2.25-2018.05-arm-linux-gnueabi.tar.xz sysroot
unlink gcc-linaro-7.3.1-2018.05-x86_64_arm-linux-gnueabi.tar.xz
unlink sysroot-glibc-linaro-2.25-2018.05-arm-linux-gnueabi.tar.xz

## Installing emulator
sudo apt-get update
apt-get install qemu-user

## Configuring
cd sysroot
pwd
`copy the first pwd output`
cd ../gcc-linaro/bin
pwd
`copy the second pwd output`

### Modify the bashrc:
vim ~/.bashrc
PATH="$PATH:`second pwd output goes here`"
export LINARO_SYSROOT="`first pwd output goes here`"
:wq

### Don't forget to reload the bashrc!
. ~/.bashrc

## Test
`Create the most simple hello-world program and save it into main.c file`
arm-linux-gnueabi-gcc -marm main.c -o main
qemu-arm -L $LINARO_SYSROOT ./main
`Now you should see "Hello world!"`
