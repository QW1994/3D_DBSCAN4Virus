//
// Created by scaactk on 7/24/2023.
//
#include <iostream>
#include <string>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>

using namespace std;

int main(int argc, char **argv) {
    typedef pcl::PointXYZRGB PointT;
    pcl::PointCloud<PointT>::Ptr cloud(new pcl::PointCloud<PointT>);
    //pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> single_color(cloud, 0, 255, 0);

    std::string dir = "C:\\Users\\scaactk\\Desktop\\test\\1\\";
    std::string filename = "1.pcd";

    if (pcl::io::loadPCDFile<PointT>((dir + filename), *cloud) == -1) {
        //* load the file
        PCL_ERROR ("Couldn't read PCD file \n");
        return (-1);
    }
    printf("Loaded %d data points from PCD\n",
           cloud->width * cloud->height);

    pcl::visualization::PCLVisualizer viewer("Cloud viewer");
    //viewer.setBackgroundColor(1.0, 1.0, 1.0);

    viewer.setCameraPosition(0, 0, -3.0, 0, -1, 0);
    viewer.addCoordinateSystem(0.3);
    //viewer.addPointCloud<pcl::PointXYZ> (cloud, single_color, "sample cloud");
    viewer.setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "sample cloud");//设置点云大小

    viewer.addPointCloud(cloud);
    while (!viewer.wasStopped())
        viewer.spinOnce(100);
    return (0);
}
