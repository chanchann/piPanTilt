## 如何使用wiringpi -- Motor

## docker如何配置 -- 有什么flags  -- 访问GPIO -- 访问摄像头

docker run -itd --privileged --cap-add=SYS_PTRACE --security-opt seccomp=unconfined -p 9000:22 -p 9001:9001 -v /home/ubuntu/piPanTilt:/home/piPanTilt -v /opt/vc:/opt/vc --env LD_LIBRARY_PATH=/opt/vc/lib jermine/opencv:aarch64-ubuntu-3.4.1 /bin/bash

## 如何访问摄像头

https://www.losant.com/blog/how-to-access-the-raspberry-pi-camera-in-docker

https://blog.csdn.net/VerTicalVerTical/article/details/110493428

https://chuckmails.medium.com/enable-pi-camera-with-raspberry-pi4-ubuntu-20-10-327208312f6e

## pi4 ubuntu20 换源

```bash 
echo "deb https://mirrors.ustc.edu.cn/ubuntu-ports/ focal main restricted universe multiverse" > /etc/apt/sources.list
echo "deb https://mirrors.ustc.edu.cn/ubuntu-ports/ focal-updates main restricted universe multiverse" >> /etc/apt/sources.list
echo "deb https://mirrors.ustc.edu.cn/ubuntu-ports/ focal-backports main restricted universe multiverse" >> /etc/apt/sources.list
echo "deb https://mirrors.ustc.edu.cn/ubuntu-ports/ focal-security main restricted universe multiverse" >> /etc/apt/sources.list
```







