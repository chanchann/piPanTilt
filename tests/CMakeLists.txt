# add_executable( surf surf.cc )
# target_link_libraries( surf ${OpenCV_LIBS} )

# add_executable( stitich stitich.cc )
# target_link_libraries( stitich ${OpenCV_LIBS} )

# add_executable( io_simple io_simple.cc )
# target_link_libraries( io_simple wiringPi pthread crypt rt)

# add_executable( capture capture.cc )
# target_link_libraries( capture ${OpenCV_LIBS} )

# add_executable( capture_latest capture_latest.cc )
# target_link_libraries( capture_latest ${OpenCV_LIBS} )

add_executable( stitch_detail stitch_detail.cc )
target_link_libraries( stitch_detail ${OpenCV_LIBS} )
