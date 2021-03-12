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

//����������Ĵ洢�ṹ
bool build_vmachine(std::vector<Vmachine>& m_vmachine, int m, std::ifstream& infile) {
    //����ÿ�����������
    std::string t_model;
    int t[3];
    char buffer[256];
    std::stringstream ss;
    std::string t_tmp;
    for (int i = 0; i < m; ++i) {
        infile.getline(buffer, 256);
        ss.clear();
        //ȡ���ͺ�
        ss << buffer;
        ss >> t_model;
        t_model = t_model.substr(1, t_model.length() - 2);
        //ȡ��ʣ�²���
        for (int j = 0; j < 3; ++j) {
            ss >> t[j];
            ss >> t_tmp;
        }
        ss.str("");
        Vmachine cur(t_model, t[0], t[1], t[2]);
        //���ݽṹ���ϣ�֮��Ľ���ջ�ڴ��hash��
        m_vmachine.push_back(cur);
    }
    return m_vmachine.size() == m ? 1 : 0;
}