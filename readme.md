## 

docker run -itd --privileged --cap-add=SYS_PTRACE --security-opt seccomp=unconfined -p 9000:22 -p 9001:9001 -v /home/ubuntu/piPanTilt:/home/piPanTilt victorhcm/opencv:3.2.0-python3.4 /bin/bash
