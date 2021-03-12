#include "Server.h"
const std::string Server::get_model() {
	return model;
}
const int Server::get_core() {
	return core;
}
const int Server::get_memory() {
	return memory;
}
const int Server::get_cost_hardware() {
	return cost_hardware;
}
const int Server::get_cost_daily() {
	return cost_daily;
}
//�����������Ĵ洢�ṹ
bool build_server(std::vector<Server>& n_server, int n, std::ifstream& infile) {
    //����ÿ������������
    std::string t_model;
    int t[4];
    char buffer[256];
    std::stringstream ss;
    std::string t_tmp;
    for (int i = 0; i < n; ++i) {
        infile.getline(buffer, 256);
        ss.clear();
        //ȡ���ͺ�
        ss << buffer;
        ss >> t_model;
        t_model = t_model.substr(1, t_model.length() - 2);
        //ȡ��ʣ�²���
        for (int j = 0; j < 4; ++j) {
            ss >> t[j];
            ss >> t_tmp;
        }
        ss.str("");
        Server cur(t_model, t[0], t[1], t[2], t[3]);
        //���ݽṹ���ϣ�֮��Ľ���ջ�ڴ��hash��
        n_server.push_back(cur);
    }
    return n_server.size() == n ? 1 : 0;
}