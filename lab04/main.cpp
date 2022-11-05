#include<iostream>
#include<string>
#include<cstring>
#include<sys/types.h>
#include<dirent.h>
#include<vector>
#include<fstream>
#include<sstream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<ctime>

using namespace std;

//生成随机字符
char get_rand_char()
{
	int temp1=rand()%26;
	char temp2='a'+temp1;
	return temp2;
}

//生成随机输入
void make_input1(string str)
{

	ofstream in1;
	in1.open("input1.txt",ios::out);
	in1.close();

	vector<string> rem;

	int i=0;
	string buf;
	stringstream ss(str);
	while(ss>>buf)
	{
		rem.push_back(buf);
		i++;
	}

	for(int j=0;j<i;j++)
	{
		if(rem[j].substr(0,3)=="int")
		{
			int a,b;
			int pos1=rem[j].find_first_of("(");
			int pos2=rem[j].find_first_of(",");
			int pos3=rem[j].find_first_of(")");

			a=stoi(rem[j].substr(pos1+1,pos2));
			b=stoi(rem[j].substr(pos2+1,pos3));
			int temp=a+rand()%(b-a+1);

			ofstream ofs;
			ofs.open("input1.txt",ios::app);
			if(!ofs)
			{
				cout<<"file opening failed!"<<endl;
				exit(-1);
			}
			else{
				if(j==i-1)
				{
					ofs<<temp;
				}
				else ofs<<temp<<" ";
			}
			ofs.close();
		}
		else if(rem[j].substr(0,4)=="char")
		{
			char temp=get_rand_char();

			ofstream ofs;
			ofs.open("input1.txt",ios::app);
			if(!ofs)
			{
				cout<<"file opening failed!"<<endl;
				exit(-1);
			}
			else{
				if(j==i-1)
				{
					ofs<<temp;
				}
				else ofs<<temp<<" ";
			}
			ofs.close();
		}
		else if(rem[j].substr(0,6)=="string")
		{
			int a,b;
			int pos1=rem[j].find_first_of("(");
			int pos2=rem[j].find_first_of(",");
			int pos3=rem[j].find_first_of(")");

			//得到一个string的随机长度
			a=stoi(rem[j].substr(pos1+1,pos2));
			b=stoi(rem[j].substr(pos2+1,pos3));
			int t=a+rand()%(b-a+1);
			
			//调用随机char生成的函数来生成string
			string temp="";
			for(int k=0;k<t;k++)
			{
				temp+=get_rand_char();
			}

			ofstream ofs;
			ofs.open("input1.txt",ios::app);
			if(!ofs)
			{
				cout<<"file opening failed!"<<endl;
				exit(-1);
			}
			else{
				if(j==i-1)
				{
					ofs<<temp;
				}
				else ofs<<temp<<" ";
			}
			ofs.close();
		}
	}
}

void make_input2(string str)
{
	ofstream in2;
	in2.open("input2.txt",ios::out);
	in2.close();

	vector<string> rem;

	int i=0;
	string buf;
	stringstream ss(str);
	while(ss>>buf)
	{
		rem.push_back(buf);
		i++;
	}

	for(int j=0;j<i;j++)
	{
		if(rem[j].substr(0,3)=="int")
		{
			int a,b;
			int pos1=rem[j].find_first_of("(");
			int pos2=rem[j].find_first_of(",");
			int pos3=rem[j].find_first_of(")");

			a=stoi(rem[j].substr(pos1+1,pos2));
			b=stoi(rem[j].substr(pos2+1,pos3));
			int temp=a+rand()%(b-a+1);

			ofstream ofs;
			ofs.open("input2.txt",ios::app);
			if(!ofs)
			{
				cout<<"file opening failed!"<<endl;
				exit(-1);
			}
			else{
				if(j==i-1)
				{
					ofs<<temp;
				}
				else ofs<<temp<<" ";
			}
			ofs.close();
		}
		else if(rem[j].substr(0,4)=="char")
		{
			char temp=get_rand_char();

			ofstream ofs;
			ofs.open("input2.txt",ios::app);
			if(!ofs)
			{
				cout<<"file opening failed!"<<endl;
				exit(-1);
			}
			else{
				if(j==i-1)
				{
					ofs<<temp;
				}
				else ofs<<temp<<" ";
			}
			ofs.close();
		}
		else if(rem[j].substr(0,6)=="string")
		{
			int a,b;
			int pos1=rem[j].find_first_of("(");
			int pos2=rem[j].find_first_of(",");
			int pos3=rem[j].find_first_of(")");

			//得到一个string的随机长度
			a=stoi(rem[j].substr(pos1+1,pos2));
			b=stoi(rem[j].substr(pos2+1,pos3));
			int t=a+rand()%(b-a+1);
			
			//调用随机char生成的函数来生成string
			string temp="";
			for(int k=0;k<t;k++)
			{
				temp+=get_rand_char();
			}

			ofstream ofs;
			ofs.open("input2.txt",ios::app);
			if(!ofs)
			{
				cout<<"file opening failed!"<<endl;
				exit(-1);
			}
			else{
				if(j==i-1)
				{
					ofs<<temp;
				}
				else ofs<<temp<<" ";
			}
			ofs.close();
		}
	}
}

void myCommand(char* cmd)
{
	FILE* file;
	file = popen(cmd, "r");
	while(fgets(cmd, (int)strlen(cmd), file) != nullptr) {
	}
	pclose(file);
}

//处理文件夹
void do_folder(string path)
{
	//处理输入
	string input=path+"/"+"stdin_format.txt";

	ifstream ifs;
	ifs.open(input.c_str(),ios::in);

	string s;
	getline(ifs,s);
	ifs.close();

	make_input1(s);make_input2(s);

	//获取文件夹内的cpp名
	DIR* dirStream;
	dirStream = opendir(path.c_str());

	struct dirent* dirInfo;
	vector<string> c_name;
	while((dirInfo=readdir(dirStream))!=0)
	{
		if(strcmp(dirInfo->d_name,".")!=0&&strcmp(dirInfo->d_name,"..")!=0)
		{
			if(strcmp(dirInfo->d_name,"stdin_format.txt")!=0&&strcmp(dirInfo->d_name,"input.txt")!=0)
			{
				cout<<"FOLDER NAME"<<dirInfo->d_name<<endl;
				c_name.push_back(dirInfo->d_name);
			}
		}
	}
	closedir(dirStream);

	//cout<<c_name.size()<<endl;
	int rrr=0;
	//每一对cpp跑一遍看结果
	for(int i=0;i<c_name.size();i++)
	{
		for(int j=i+1;j<c_name.size();j++)
		{
			//第一遍
			char cmd1_i[2048];
			char cmd1_j[2048];
			string cm1_i="g++ "+path+"/"+c_name[i]+" -o "+"cpp1";
			string cm1_j="g++ "+path+"/"+c_name[j]+" -o "+"cpp2";
			strcpy(cmd1_i, cm1_i.c_str());
			myCommand(cmd1_i);
			strcpy(cmd1_j, cm1_j.c_str());
			myCommand(cmd1_j);

			char cmd2_i[2048];
			char cmd2_j[2048];
			string cm2_i="./cpp1 <input1.txt> output1.txt";
			string cm2_j="./cpp2 <input1.txt> output2.txt";
			strcpy(cmd2_i, cm2_i.c_str());
			myCommand(cmd2_i);
			strcpy(cmd2_j, cm2_j.c_str());
			myCommand(cmd2_j);

			//读取文件内容
			ifstream ifs1;
			ifs1.open("output1.txt",ios::in);
			string s1="";
			char c;
			while(!ifs1.eof())
			{
				ifs1>>c;
				s1+=c;
			}
			ifs1.close();
			
			ifstream ifs2;
			ifs2.open("output2.txt",ios::in);
			string s2="";
			while(!ifs2.eof())
			{
				ifs2>>c;
				s2+=c;
			}
			ifs2.close();

			bool flag1=0;
			if(s1.size()!=s2.size())flag1=0;
			else{
				for(int x=0;x<s1.size();x++)
				{
					flag1=1;
					if(s1[x]!=s2[x])
					{
						flag1=0;break;
					}
				}
			}

			//第二遍
			cm2_i="./cpp1 <input2.txt> output1.txt";
			cm2_j="./cpp2 <input2.txt> output2.txt";
			strcpy(cmd2_i, cm2_i.c_str());
			myCommand(cmd2_i);
			strcpy(cmd2_j, cm2_j.c_str());
			myCommand(cmd2_j);

			//读取文件内容
			ifstream ifs3;
			ifs3.open("output1.txt",ios::in);
			//string s3="";
			while(!ifs3.eof())
			{
				ifs3>>c;
				s1+=c;
			}
			ifs3.close();
			
			ifstream ifs4;
			ifs4.open("output2.txt",ios::in);
			//string s4="";
			while(!ifs4.eof())
			{
				ifs4>>c;
				s2+=c;
			}
			ifs4.close();

			bool flag2=0;
			if(s1.size()!=s2.size())flag2=0;
			else{
				for(int x=0;x<s1.size();x++)
				{
					flag2=1;
					if(s1[x]!=s2[x])
					{
						flag2=0;break;
					}
				}
			}

			if(flag1==1&&flag2==1)
			{
				ofstream f;
				f.open("output/equal.csv",ios::app);
				f<<path<<"/"<<c_name[i]<<","<<path<<"/"<<c_name[j]<<"\n";
				f.close();
			}
			else{
				ofstream f;
				f.open("output/inequal.csv",ios::app);
				f<<path<<"/"<<c_name[i]<<","<<path<<"/"<<c_name[j]<<"\n";
				f.close();
			}
		}
	}
}


int main(int argc, const char* argv[])
{
	srand(time(0));

	DIR* dirStream;
	const char* pat="input/";
	dirStream = opendir(pat);

	//读取所有文件名
	struct dirent* dirInfo;
	vector<string> f_name;
	while((dirInfo=readdir(dirStream))!=0)
	{
		if(strcmp(dirInfo->d_name,".")!=0&&strcmp(dirInfo->d_name,"..")!=0)
		{
			//cout<<"FOLDER NAME"<<dirInfo->d_name<<endl;
			f_name.push_back(dirInfo->d_name);
		}
	}

	int fcreat=mkdir("output",S_IRWXU);
	ofstream equal_f;
	equal_f.open("output/equal.csv",ios::app);
	equal_f<<"file1"<<","<<"file2"<<"\n";
	equal_f.close();
	ofstream inequal_f;
	inequal_f.open("output/inequal.csv",ios::app);
	inequal_f<<"file1"<<","<<"file2"<<"\n";
	inequal_f.close();

	

	for(int i=0;i<f_name.size();i++)
	{
		string path=pat+f_name[i];
		do_folder(path);
	}

	return 0;
}