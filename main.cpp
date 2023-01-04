#include <iostream>
#include <opencv4/opencv2/opencv.hpp>

#include "face.hpp"

int main(int argc, char **argv) {
    cv::VideoCapture cap(0);
    FaceDetector face_detector;
    double dWidth = cap.get(cv::CAP_PROP_FRAME_WIDTH);
    double dHeight = cap.get(cv::CAP_PROP_FRAME_HEIGHT);
    cv::namedWindow("Web");
    cv::Mat frame;
    while (true) {
        cap.read(frame);
        auto rectangles = face_detector.detectFaceRectangles(frame);
        cv::Scalar color(255, 105, 205);
        int frame_thickness = 4;
        for (const auto &r : rectangles) {
            cv::rectangle(frame, r, color, frame_thickness);
        }
        cv::imshow("Web", frame);
        if (cv::waitKey(10) == 27) {
            break;
        }
    }
    cv::destroyAllWindows();
    cap.release();
    return 0;
}
