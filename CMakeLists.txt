CMAKE_MINIMUM_REQUIRED(VERSION 3.15)

set(PROJ_NAME camfinder)
find_package(OpenCV REQUIRED)

include_directories(
    ./
    /usr/local/include/opencv4
)

set(FACE_DETECTION_CONFIGURATION "${PROJECT_SOURCE_DIR}/assets/face_detection/deploy.prototxt")
set(FACE_DETECTION_WEIGHTS "${PROJECT_SOURCE_DIR}/assets/face_detection/res10_300x300_ssd_iter_140000_fp16.caffemodel")


file(GLOB SRC
"main.cpp"
"face.cpp"
)

add_executable(${PROJ_NAME} ${SRC})

target_compile_definitions(${PROJ_NAME} PRIVATE  FACE_DETECTION_CONFIGURATION="${FACE_DETECTION_CONFIGURATION}")
target_compile_definitions(${PROJ_NAME} PRIVATE  FACE_DETECTION_WEIGHTS="${FACE_DETECTION_WEIGHTS}")
target_link_libraries(${PROJ_NAME} ${OpenCV_LIBS})
