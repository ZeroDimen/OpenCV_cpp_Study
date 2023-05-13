#include "opencv2/opencv.hpp"
using namespace cv;

Mat src, src_gray;
Mat dst, detected_edges;
int edgeThresh = 1;
int lowThreshold;
int const max_lowThreshold = 100;
int ratio = 3;
int kernel_size = 3; // ���� �Ӱ谪�� ���� �Ӱ谪�� ���� ����

static void CannyThreshold(int, void*)
{
    blur(src, detected_edges, Size(3, 3)); // ���� ���� �� ���� ���Ÿ� ���� �� ó��
    Canny(detected_edges, detected_edges, lowThreshold,
        lowThreshold * ratio, kernel_size); //ĳ�� ���� ���� �Լ�
    dst = Scalar::all(0);
    src.copyTo(dst, detected_edges);
    imshow("source", src);
    imshow("Canny", dst);
}

int main()
{
    src = imread("lenna.jpg", IMREAD_GRAYSCALE);
    if (src.empty()) // �Է� ������ ���޾��� ��� ����
    {
        return -1;
    }
    dst.create(src.size(), src.type());
    namedWindow("Canny");
    createTrackbar("Min Threshold : ", "Canny", &lowThreshold,
        max_lowThreshold, CannyThreshold); // Ʈ���ٸ� ����� �Լ�
    CannyThreshold(0, 0);
    waitKey(0);
    return 0;
}