cmake_minimum_required(VERSION 3.26)
project(Paradygmaty_programowania_PROJECT_3 C)

set(CMAKE_C_STANDARD 90)

add_executable(Paradygmaty_programowania_PROJECT_3 main.c
        queue/queue.h
        queue/queue.c
        cars/data.h
        cars/data.c
        workplaces/data.h
        workplaces/data.c
        repairs/data.h
        repairs/data.c
        interface/interface.h
        interface/interface.c
        workplaces/interface.c
        workplaces/interface.h
        common.c
        common.h
        cars/interface.c
        cars/interface.h
        repairs/interface.c
        repairs/interface.h
)