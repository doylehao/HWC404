#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
class Server {
private:
    std::string model{ "" };//型号
    int core = 0;//cpu核数
    int memory = 0;//内存大小
    int cost_hardware = 0;//硬件成本
    int cost_daily = 0;//每日能耗成本
public:
    Server(std::string t_model = "", int t_core = 0, int t_memory = 0, int t_cost_hardware = 0, int t_cost_daily = 0)\
        : model(t_model), core(t_core), memory(t_memory), cost_hardware(t_cost_hardware), cost_daily(t_cost_daily)\
    {};
    const std::string get_model();
    const int get_core();
    const int get_memory();
    const int get_cost_hardware();
    const int get_cost_daily();
};
//建立服务器的存储结构
bool build_server(std::vector<Server>& n_server, int n, std::ifstream& infile);
