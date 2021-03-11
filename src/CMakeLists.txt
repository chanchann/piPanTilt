set(SRCS
    imgManager.cc 
    motor.cc 
    SignalHandler.cc
    server.cc
)

add_library(pi_src ${SRCS})
target_link_libraries(pi_src ${OpenCV_LIBS} wiringPi pthread crypt rt)

add_subdirectory(tests)

add_executable(server server.cc)

target_link_libraries(server 
  ${Boost_FILESYSTEM_LIBRARY}
  ${Boost_SYSTEM_LIBRARY}
  pi_src
)