#pragma once
#include <QThread>
#include <core/matx.hpp>
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/utility.hpp"
/*
 * 
 */
class StereoMatch :public QThread
{
	Q_OBJECT
public:
	StereoMatch();
	~StereoMatch();
	void run();
	enum { STEREO_BM = 0, STEREO_SGBM = 1, STEREO_HH = 2, STEREO_VAR = 3, STEREO_3WAY = 4 };

private:

	std::string img1_filename = "";
	std::string img2_filename = "";
	std::string intrinsic_filename = "";
	std::string extrinsic_filename = "";
	std::string disparity_filename = "";
	std::string point_cloud_filename = "";
	int alg = STEREO_SGBM;
	int SADWindowSize; 
	int numberOfDisparities;
	float scale;
	bool no_display;
signals:
	void openMessageBox(QString, QString);
private:
	void saveXYZ(const char* filename, const cv::Mat& mat);
};
