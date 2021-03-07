set(SRCS
    imgManager.cc 
    motor.cc 
    SignalHandler.cc
)

add_library(pi_src ${SRCS})
target_link_libraries(pi_src ${OpenCV_LIBS} wiringPi pthread crypt rt)

add_subdirectory(tests)