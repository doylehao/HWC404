// hwc.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <cstdio>
#include "Server.h"
#include "Vmachine.h"

int main() {
    //打开数据集
    std::ifstream infile;
    infile.open("test.txt", std::ios::in);//test文件
    //infile.open("training-1.txt", std::ios::in);//training1文件
    
    char buffer[256];
    if (!infile.is_open()) {
        std::cerr << "failed to open data." << std::endl;
        return -1;
    }
    // while(!infile.eof()){
    //     infile.getline(buffer, 256, '\n');
    //     std::cout << buffer << std::endl;

    // }

    //记录总服务器数量n和服务器数据
    infile.getline(buffer, 256, '\n');
    int n = atoi(buffer);//取出服务器数量n
    std::cout << n << std::endl;
    std::vector<Server> n_server;
    if (!build_server(n_server, n, infile)) {//存放服务器数据
        std::cerr << "build server error!" << std::endl;
    }
    //测试服务器数据是否正确
    std::cout << "test for n_server data" << std::endl;
    for (auto i = n_server.begin(); i != n_server.end(); ++i) {
        std::cout << i->get_model() << "\t" << i->get_core() << "\t" << i->get_memory() << "\t" << i->get_cost_hardware() << "\t" << i->get_cost_daily() << std::endl;
    }
    
    //记录总虚拟机数量m和虚拟机数据
    infile.getline(buffer, 256, '\n');
    int m = atoi(buffer);//取出虚拟机数量m
    std::cout << m << std::endl;
    std::vector<Vmachine> m_vmachine;
    if (!build_vmachine(m_vmachine, m, infile)) {//存放虚拟机数据
        std::cerr << "build vmachine error!" << std::endl;
    }
    //测试虚拟机数据是否正确
    std::cout << "test for m_vmachine data" << std::endl;
    for (auto i = m_vmachine.begin(); i != m_vmachine.end(); ++i) {
        std::cout << i->get_model() << "\t" << i->get_core() << "\t" << i->get_memory() << "\t" << i->get_two_support() << std::endl;
    }

    infile.close();
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
