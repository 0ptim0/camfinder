#ifndef FACE_H
#define FACE_H

#include <opencv4/opencv2/dnn.hpp>

class FaceDetector {
public:
    explicit FaceDetector();
    std::vector<cv::Rect> detectFaceRectangles(const cv::Mat &frame);

private:
    cv::dnn::Net network_;
    const int input_image_width_;
    const int input_image_height_;
    const double scale_factor_;
    const cv::Scalar mean_values_;
    const float confidence_threshold_;
};

#endif  //  FACE_H
