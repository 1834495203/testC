cmake_minimum_required(VERSION 3.25)
project(testC C)

set(CMAKE_C_STANDARD 11)

add_executable(testC main.c tree/treeQuiz.c tree/treeQuiz.h queue/queueQuiz.c queue/queueQuiz.h base/base.h queue/queueData.h)
