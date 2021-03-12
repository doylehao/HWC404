#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
class Server {
private:
    std::string model{ "" };//�ͺ�
    int core = 0;//cpu����
    int memory = 0;//�ڴ��С
    int cost_hardware = 0;//Ӳ���ɱ�
    int cost_daily = 0;//ÿ���ܺĳɱ�
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
//�����������Ĵ洢�ṹ
bool build_server(std::vector<Server>& n_server, int n, std::ifstream& infile);
