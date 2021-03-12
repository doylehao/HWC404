#include "Vmachine.h"
const std::string Vmachine::get_model() {
	return model;
}
const int Vmachine::get_core() {
	return core;
}
const int Vmachine::get_memory() {
	return memory;
}
const int Vmachine::get_two_support() {
	return two_support;
}

//建立虚拟机的存储结构
bool build_vmachine(std::vector<Vmachine>& m_vmachine, int m, std::ifstream& infile) {
    //加载每个虚拟机数据
    std::string t_model;
    int t[3];
    char buffer[256];
    std::stringstream ss;
    std::string t_tmp;
    for (int i = 0; i < m; ++i) {
        infile.getline(buffer, 256);
        ss.clear();
        //取出型号
        ss << buffer;
        ss >> t_model;
        t_model = t_model.substr(1, t_model.length() - 2);
        //取出剩下参数
        for (int j = 0; j < 3; ++j) {
            ss >> t[j];
            ss >> t_tmp;
        }
        ss.str("");
        Vmachine cur(t_model, t[0], t[1], t[2]);
        //数据结构集合，之后改进成栈内存和hash表
        m_vmachine.push_back(cur);
    }
    return m_vmachine.size() == m ? 1 : 0;
}