#ifndef software_h
#define software_h

#include <iostream>

// **************************************************************************
// **************************************************************************
// ��� ����
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

using namespace std;


// **************************************************************************
// **************************************************************************
// �Լ� ����
void doTask();
void join();
void program_exit();


// **************************************************************************
// **************************************************************************
// Ŭ���� ����


// ===== Member class
class Member {
private:
    string ID;
    int PW;
	RecruitInfo *recruitInfo[MAX_STRING];
	int type = -1;

	int workNum[MAX_STRING];
	string workName[MAX_STRING];

public:
    virtual void saveInfo() = 0;
    virtual void deleteInfo() = 0;
    virtual bool checkID() = 0;
    virtual void addApplicant() = 0;

	virtual void listStat(Member member);
	int getType();
	RecruitInfo getRecruitInfo(int i);
	string getWorkName(int i);
	int getWorkNum(int i);
	void setWorkName(int i, string name);
	void setWorkNum(int i, int number);
};

int Member::getType() {
	return type;
}

RecruitInfo Member::getRecruitInfo(int i) {
	return recruitInfo[i];
}
string Member::getWorkName(int i) {
	return workName[i];
}
int Member::getWorkNum(int i) {
	return workNum[i];
}
void Member::setWorkName(int i, string name) {
	workName[i] = name;
}
void Member::setWorkNum(int i, int number = 1) {
	workNum[i] = number;
}




// ===== Company class
class Company
{
private:
    string CompanyName;

public:
    void addNewRecruitInfo();
    void showRecruitInfo();
    void editREcruitInfo(); // XXX
    void deleteRecruitInfo(); // XXX
    void expireRecruitInfo(); // XXX
    void sendMessage();

};




// ===== User class : Member
class User : Member //�Ϲ� ȸ��
{
private:
    //ID
    //PWD �� ���
    string memberName;
    int RegisterationNumber; //�ֹι�ȣ

public:
	void listApply(RecruitInfo* recruitInfo[], int n);
	
	void cancelApply(User user, int businessNumber1) = 0; // ȸ�� �Լ� : ������ ���
	
	void listStat(Member member);
};


// =====companyStaff class : Member
class companyStaff : Member
{
private:
    //ID
    //PWD
    string companyName;
    int BusinessNumber;

public:
	void listStat(Member member);
};



// ===== RecruitInfo class
class RecruitInfo : Company
{
private:
	string CompanyName; // 1) ȸ���̸�
	int BusinessNumber; // 2) ����� ��ȣ
	string task; // 3) ����
	int applyNumber; // 4) �ο���
	string deadline; //5) ��û ������
	int taskApplied = 0;



public:
	void getDetail(); //XXX (UI_showDetail, getDetail ���� �ؾ���)
	void addApply(); // ��� ����( �ܺ�_selectApply(), UI_apply(), addApply()
	void getRecruitInfoList();
	void editRecruitInfoList(); //XXX
	void deleteRecruitInfoList(); //XXX
	void checkAppNum();
	void deleteApplyList(); // XXX
	void getCompList();
	void getTaskList();

	string getTask();
	int getBusinessNumber();
	int getApplyNumber();
	string getCompanyName();
	string getDeadline();
	void getApply(RecruitInfo* recruitInfo[]);
	void cancelApplyList(RecruitInfo* recruitInfo[], string name, int number, string work);
};

string RecruitInfo::getTask() {
	return task;
}
int RecruitInfo::getBusinessNumber() {
	return BusinessNumber;
}
int RecruitInfo::getApplyNumber() {
	return applyNumber;
}
string RecruitInfo::getCompanyName() {
	return CompanyName;
}
string RecruitInfo::getDeadline() {
	return deadline;
}











class ApplicationUI { // boundary
private:

public:
	virtual void startApplication() = 0;
	virtual void startCancel() = 0;
};

class Application { // control
private:
	ApplicationUI* applicationUI;

public:
	void showList(User user);
	void showCancel(int businessNumber);
	void startInterface();

};


class StatisticUI {
private:
	
public:
	void startStatistic(Member member);
};//user�� virtual ��� ������...

class Statistic {
private:
	StatisticUI* statisticUI;

public:
	void startInterface(Member member);
	void getStat(Member member);
};










#endif /* software_h */