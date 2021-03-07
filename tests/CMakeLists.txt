#add_executable( surf surf.cc )
#target_link_libraries( surf ${OpenCV_LIBS} )

#add_executable( stitich stitich.cc )
#target_link_libraries( stitich ${OpenCV_LIBS} )

#add_executable( io_simple io_simple.cc )
#target_link_libraries( io_simple ${OpenCV_LIBS} )

add_executable( io_simple io_simple.cc )
target_link_libraries( io_simple wiringPi pthread crypt rt)

