#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
class Vmachine
{
private:
	std::string model{ "" };//�ͺ�
	int core = 0;//cpu����
	int memory = 0;//�ڴ��С
	int two_support = 0;//�Ƿ�֧��˫�ڵ㲿��
public:
	Vmachine(std::string t_model = "", int t_core = 0, int t_memory = 0, int t_two_support = 0)\
		: model(t_model), core(t_core), memory(t_memory), two_support(t_two_support)\
	{};
	const std::string get_model();
	const int get_core();
	const int get_memory();
	const int get_two_support();
};

//����������Ĵ洢�ṹ
bool build_vmachine(std::vector<Vmachine>& m_vmachine, int m, std::ifstream& infile);