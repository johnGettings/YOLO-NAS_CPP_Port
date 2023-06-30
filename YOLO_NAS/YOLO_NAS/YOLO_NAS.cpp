#include <iostream>
//#include <sstream>
#include <opencv2/opencv.hpp>

int main()
{

        cv::namedWindow("Display Webcam", cv::WINDOW_AUTOSIZE);
        cv::VideoCapture cap;
        cap.open(0);

        if (!cap.isOpened()) {
            std::cerr << "Couldn't open camera" << std::endl;
            return -1;
        }

        cv::Mat frame;

        for (;;) {
            cap >> frame;
            if (frame.empty()) break;

            // Mirroring image
            cv::Mat frame_flipped;
            cv::flip(frame, frame_flipped, 1);


            // Display
            cv::imshow("Display Webcam", frame_flipped);

            // Display new frame every 20 ms (50 fps)
            if ((char)cv::waitKey(20) >= 0) break;
        }
        return 0;


    //int width = frame.size().width;
    //int height = frame.size().height;





    //From internet, not tested

    //cv::Mat imageBGR = cv::imread(imageFilepath, cv::ImreadModes::IMREAD_COLOR);
    //cv::Mat resizedImageBGR, resizedImageRGB, resizedImage, preprocessedImage;
    //cv::resize(imageBGR, resizedImageBGR,
    //    cv::Size(inputDims.at(2), inputDims.at(3)),
    //    cv::InterpolationFlags::INTER_CUBIC);
    //cv::cvtColor(resizedImageBGR, resizedImageRGB,
    //    cv::ColorConversionCodes::COLOR_BGR2RGB);
    //resizedImageRGB.convertTo(resizedImage, CV_32F, 1.0 / 255);

    //cv::Mat channels[3];
    //cv::split(resizedImage, channels);
    //// Normalization per channel
    //// Normalization parameters obtained from
    //// https://github.com/onnx/models/tree/master/vision/classification/squeezenet
    //channels[0] = (channels[0] - 0.485) / 0.229;
    //channels[1] = (channels[1] - 0.456) / 0.224;
    //channels[2] = (channels[2] - 0.406) / 0.225;
    //cv::merge(channels, 3, resizedImage);
    //// HWC to CHW
    //cv::dnn::blobFromImage(resizedImage, preprocessedImage);
}
