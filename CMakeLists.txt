cmake_minimum_required(VERSION 3.25)
project(testC C)

set(CMAKE_C_STANDARD 11)

add_executable(testC main.c tree/base/treeQuiz.c tree/base/treeQuiz.h queue/base/queueQuiz.c queue/base/queueQuiz.h base/base.h queue/base/queueData.h list/base/listQuiz.c list/base/listQuiz.h list/base/listData.h list/solution/listSolution.c list/solution/listSolution.h tree/base/treeData.h
        train/TrainStart.c
        train/TrainStart.h
        graph/GraphData.c
        graph/GraphData.h
)
