if(EXISTS "/Users/francescomazzola/Project/Finanza/cmake-build-debug/test1[1]_tests.cmake")
  include("/Users/francescomazzola/Project/Finanza/cmake-build-debug/test1[1]_tests.cmake")
else()
  add_test(test1_NOT_BUILT test1_NOT_BUILT)
endif()