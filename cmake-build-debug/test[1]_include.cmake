if(EXISTS "/Users/francescomazzola/Project/Finanza/cmake-build-debug/test[1]_tests.cmake")
  include("/Users/francescomazzola/Project/Finanza/cmake-build-debug/test[1]_tests.cmake")
else()
  add_test(test_NOT_BUILT test_NOT_BUILT)
endif()