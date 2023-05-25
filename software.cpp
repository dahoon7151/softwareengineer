#include "software.h"



using namespace std;

void doTask() {

    MemberList members;
    Member* pNewMember = NULL;

    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;

    while (!is_program_exit) {

        cout << "1.1 ȸ�� ����\n";
        cout << "1.2 ȸ�� Ż��\n";
        cout << "2.1 �α���\n";
        cout << "2.2 �α׾ƿ�\n";
        cout << "3.1 ä������ ���\n";
        cout << "3.2 ��ϵ� ä������ ��ȸ\n";
        cout << "4.1 ä�� ���� �˻�\n";
        cout << "4.2 ä�� ����\n";
        cout << "4.3 ���� ���� ��ȸ\n";
        cout << "5.1 ���� ���� ���\n";
        cout << "6.1 ����\n";

        cin >> menu_level_1;
        cin.ignore();
        cin >> menu_level_2;
        switch (menu_level_1) {
        case 1:
        {
            Register* control_Reg = new Register();
            switch (menu_level_2) {
            case 1: //1.1 ȸ������, 1 hankook 3456 hk pwd1 /OR/ 2 98765 hn pwd2
            {

                control_Reg->startInterface();
                cout << "type 1 to register as a company member\ntype 2 to register as a User";
                int input = -1;
                cin >> input;
                if (input == 1) {

                    control_Reg->addAccount(members, input);

                    cin.ignore();

                }
                else {
                    control_Reg->addAccount(members, input);
                    cin.ignore();
                }
                members.showAll(); //�� �� �ǳ�??
                break;
            }
            case 2://1.2 ȸ�� Ż��
            {

                break;
            }
            }
            break;
        }
        case 2:
        {
            switch (menu_level_2) {
            case 1: //2.1 �α���, hk pwd1
            {

            }
            case 2: //2.2 �α׾ƿ�, hk
            {

            }
            }
            break;
        }
        case 3:
        {
            switch (menu_level_2) {
            case 1: //3.1 ä�� ���� ���
            {

            }
            case 2: //3.2 ��ϵ� ä�� ���� ��ȸ
            {

            }

            }
            break;
        }
        case 4:
        {
            switch (menu_level_2) {
            case 1: //4.1 ä�� ���� �˻�
            {

            }
            case 2: //4.2 ä�� ����
            {

            }
            case 3: //4.3 ���� ���� ��ȸ
            {
                Application* control_application = new Application();
                control_application->call_startInterface(&members);
            }
            case 4: //4.4 ���� ���
            {
                //fread��¼�� ������(business Number �б�)
                CancelApply* control_cancelApply = new CancelApply();
                control_cancelApply->call_startInterface(&members, businessNum);
            }

            }
            break;
        }
        case 5:
        {
            switch (menu_level_2) {
            case 1: // 5.1 ���� ���� ���
            {
                Statistic* control_statistic = new Statistic();
                control_statistic->call_startInterface(&members);
            }
            }
            break;
        }
        case 6:
        {
            switch (menu_level_2) {
            case 1: // 6.1 ����
            {
                program_exit();
                is_program_exit = 1;
                break;

            }
            }
            break;
        }
        }
    }
}





// join()
void join() {

}


void program_exit() {
    cout << "sibal";
}


void MemberList::addMember(Member* member) {
    memberList[numMembers++] = member;
}

void MemberList::deleteMember(string _name) {
    for (int i = 0; i < numMembers; i++) {
        if (memberList[i]->Names()) {
            memberList[i]->Names();
        }
    }
}

void MemberList::showAll() {
    for (int i = 0; i < numMembers; i++) {
        memberList[i]->show();
    }
}









void apply() {
    char user_type[MAX_STRING], name[MAX_STRING], SSN[MAX_STRING], address[MAX_STRING], ID[MAX_STRING], password[MAX_STRING];
    FILE* in_fp = fopen(INPUT_FILE_NAME, "r+");
    FILE* out_fp = fopen(OUTPUT_FILE_NAME, "w+");
    fscanf(in_fp, "%s %s %s %s", name, SSN, ID, password);

    Application startApplication();
}
void statistic() {
    char user_type[MAX_STRING], name[MAX_STRING], SSN[MAX_STRING], address[MAX_STRING], ID[MAX_STRING], password[MAX_STRING];
    FILE* in_fp = fopen(INPUT_FILE_NAME, "r+");
    FILE* out_fp = fopen(OUTPUT_FILE_NAME, "w+");
    fscanf_s(in_fp, "%s %s %s %s", name, SSN, ID, password);

    StatisticUI startStatistic();

    fprintf_s(out_fp, "1.1. ȸ������\n"); fprintf(out_fp, "%s %s %s %s\n", name, SSN, ID, password);
}





























//MemberList�� Member��ü�� �ٷ� ���� ���������� ������(Member ���� �ִ� �͵鿡 ���� �����ϰ�?)
//�ٵ� �̰� ���� �������� �𸣰ڽ��ϴ�... �˼��մϴ� �ٶ�� ���� ���� �� ���� ����...

void ApplicationUI::startInterface(MemberList* memberlist) {
    fprintf(out_fp, "5.1.���� ���� ���\n");
    //��ȣ�� ����
    ApplicationUI * ui_application = new ApplicationUI(this, memberlist);
}

ApplicationUI::ApplicationUI(Application* Apply, MemberList* memberlist) {
    Application* control_application = Apply;
    this->startInterface(memberlist);
}

void ApplicationUI::startApplication(MemberList*memberlist) {
    fprintf(out_fp, "4.3. ���� ���� ��ȸ\n");
    Application * control_application -> showList(memberlist);
}




void Application::call_startInterface(MemberList*memberlist) {
    ui_application = new ApplicationUI(this, memberlist);
}

void Application::showList(MemberList* memberlist) {
    int i = 0;
    while (memberlist.recruitInfo[i]->getBusinessNumber() != NULL) {
        string *arr = memberlist.listApply(memberlist.recruitInfo, i);
        fprintf_s(out_fp, "%s, %s, %s, %s", arr[0], arr[1], arr[2], arr[3]);
        i++;
    }
}



string* User::listApply(RecruitInfo* recruitInfo[], int n) {
    string a, b, c,d;
    string apply[3] ;
    a = recruitInfo[n]->getCompanyName();
    b = recruitInfo[n]->getTask();
    c = recruitInfo[n]->getBusinessNumber();
    d = recruitInfo[n]->getDeadline();
    return apply;
    //fprintf_s(out_fp, "%s, %s, %d, %s", a,b,c,d);//�̷��� �ϰ����!
}



//=================================================================



void CancelApplyUI::startInterface(MemberList* member, int businessNumber) {
    fprintf(out_fp, "4.4.���� ���\n");
    //��ȣ�� ����
    CancelApplyUI* ui_cancelApply = new CancelApplyUI(this, member, businessNumber);
}

CancelApplyUI::CancelApplyUI(CancelApply* Apply, MemberList* memberlist, int businessNumber) {
    CancelApply* control_CancelApply = Apply;
    this->startInterface(memberlist, businessNumber);
}

void CancelApplyUI::startCancel(MemberList* memberlist, int businessNumber) {
    CancelApply* control_cancelApply ->showCancel(memberlist, businessNumber); //�̰� �� ���̷����...
}

void CancelApply::call_startInterface(MemberList* memberlist, int businessNumber) {
    ui_cancelApply = new CancelApplyUI(this, memberlist, businessNumber);
}

void CancelApply::showCancel(MemberList* memberlist, int businessNumber) {
    memberlist->cancelApply(memberlist, businessNumber);//���� member��ü �ȿ� �ִ� cancelApply �Ѵٴ� �ǹ�...
    string* cancel = memberlist->cancelApply(memberlist, businessNumber);
    fprintf_s(out_fp, "%s, %d, %s", cancel[0], cancel[1], cancel[2]);
}

string* User::cancelApply(MemberList* user, int businessNumber1) {
    int i = 0;
    int a = 0;//��𼭺��� ������ ��ܾ� �ϴ���... index ����
    string cancel[2];
    while (user.getRecruitInfo(i+1) != NULL) {
        if (user.getRecruitInfo(i)->getBusinessNumber() == businessNumber1) {
            cancel[0] = user.getRecruitInfo(i)->getCompanyName();
            cancel[1] = user.getRecruitInfo(i)->getBusinessNumber();
            cancel[2] = user.getRecruitInfo(i)->getTask();
            //fprintf_s(out_fp, "%s, %d, %s", cancel[0], cancel[1], cancel[2]);
            a = i;
        }
        if (a < i) {
            user.recruitInfo[i] = user.getRecruitInfo(i + 1);
        }
        i++;
    }
    return cancel;
}


//=================================================================


void StatisticUI::startInterface(MemberList* member) {
    fprintf(out_fp, "5.1.���� ���� ���\n");
    //��ȣ�� ����
    StatisticUI* ui_statistic = new StatisticUI(this, member);
}

StatisticUI::StatisticUI(Statistic* statistic, MemberList* member) {
    control_statistic = statistic;
    this->startInterface(member);
}

void Statistic::call_startInterface(MemberList* memberlist) {
    StatisticUI* ui_statistic = new StatisticUI(this, memberlist);
}
void Statistic::getStat(MemberList* member) {//MemberList * memberlist�� member�� �����Ѱ�?
    int i = 0;
    if (member.getType() == 1) {
        User listStat(MemberList* member);
        //��������� �ص� ��!! ��� ��𿡴� �־����� ����̶� �׳� ������
        while (member.getWorkNum(i) != NULL) {
            fprintf_s(out_fp, "%s %d", member.getWorkName(i), member.getWorkNum(i));
        }
        //�� ���κ��� �ű�� �����!!
    }
    else {
        companyStaff listStat(MemberList* member);
        while (member.getWorkNum(i) != NULL) {
            fprintf_s(out_fp, "%s %d", member.getWorkName(i), member.getWorkNum(i));
        }
    }//�׷��ٸ� �ٷ� ������ �Ͱ� �����Ѱ�?
}//��ȣ�� �ٽ� �������� ���� ��� �ϴ°�...?


void User::listStat(MemberList* member) {
    int num = 0;//���� �� ��
    int i, l = 0;
    while (member.getRecruitInfo(i) != NULL) {
        for (int j = 0; j <= i; j++) {
            if (member.getRecruitInfo(i)->getTask() == getWorkName(j)) {
                int a = getWorkNum(j);
                setWorkNum(j,a+1);
                continue;
            }//���� �̸��� �̹� ������ workNum�� ���� �ϳ� �ø���
            else {
                setWorkName(l,(member.getRecruitInfo(j)->getTask));
                setWorkNum(l);
                l++;
            }//�ƴϸ� ���� ������ش�
        }
        i++;
    }
    return;
}
void companyStaff::listStat(MemberList* member) {
    //���� ����ϰ� ���õ�?
    int num = 0;//���� �� ��
    int i, l = 0;
    while (member.getRecruitInfo(i) != NULL) {
        for (int j = 0; j <= i; j++) {
            if (member.getRecruitInfo(i)->getTask() == getWorkName(j)) {
                int a = getWorkNum(j);
                int b = getRecruitInfo(i)->getApplyNumber();
                setWorkNum(j, a + b);
                continue;
            }//���� �̸��� �̹� ������ workNum�� ���� �ϳ� �ø���
            else {
                setWorkName(l, (member.getRecruitInfo(j)->getTask));
                setWorkNum(l);
                l++;
            }//�ƴϸ� ���� ������ش�
        }
        i++;
    }
    return;
}

