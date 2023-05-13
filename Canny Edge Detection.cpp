#include "opencv2/opencv.hpp"
using namespace cv;

Mat src, src_gray;
Mat dst, detected_edges;
int edgeThresh = 1;
int lowThreshold;
int const max_lowThreshold = 100;
int ratio = 3;
int kernel_size = 3; // 하위 임계값과 상위 임계값의 비율 조정

static void CannyThreshold(int, void*)
{
    blur(src, detected_edges, Size(3, 3)); // 에지 검출 전 잡음 제거를 위한 블러 처리
    Canny(detected_edges, detected_edges, lowThreshold,
        lowThreshold * ratio, kernel_size); //캐니 에지 검출 함수
    dst = Scalar::all(0);
    src.copyTo(dst, detected_edges);
    imshow("source", src);
    imshow("Canny", dst);
}

int main()
{
    src = imread("lenna.jpg", IMREAD_GRAYSCALE);
    if (src.empty()) // 입력 영상을 못받았을 경우 종료
    {
        return -1;
    }
    dst.create(src.size(), src.type());
    namedWindow("Canny");
    createTrackbar("Min Threshold : ", "Canny", &lowThreshold,
        max_lowThreshold, CannyThreshold); // 트랙바를 만드는 함수
    CannyThreshold(0, 0);
    waitKey(0);
    return 0;
}