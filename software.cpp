
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



















void ApplicationUI::startApplication() {
    fprintf(out_fp, "4.3. ���� ���� ��ȸ\n");
    Application startInterface();
}

void ApplicationUI::startCancel() {
    fprintf(out_fp, "4.4. ���� ���\n");
    Application showCancel();
}


void Application::startInterface() {
    applicationUI = new ApplicationUI();
}

void Application::showCancel(int businessNumber) {
    Member cancelApply();
}
void Application::showList(User user) {
    int i = 0;
    while (user.* recruitInfo[i]->getBusinessNumber() != NULL) {
        user.listApply(RecruitInfo** recruitInfo, i);
        i++;
    }
}




void User::listApply(RecruitInfo* recruitInfo[], int n) {
    string a, b, d;
    int c= 0;
    a = recruitInfo[n]->getCompanyName();
    b = recruitInfo[n]->getTask();
    c = recruitInfo[n]->getBusinessNumber();
    d = recruitInfo[n]->getDeadline();
    fprintf_s(out_fp, "%s, %s, %d, %s", a,b,c,d);
}

void User::cancelApply(User user, int businessNumber1) {
    int i = 0;
    string cancel[2];
    while (user.getRecruitInfo(i) != NULL) {
        if (user.getRecruitInfo(i)->getBusinessNumber() == businessNumber1) {
            
            cancel[0] = user.getRecruitInfo(i)->getCompanyName();
            cancel[1] = user.getRecruitInfo(i)->getBusinessNumber();
            cancel[2] = user.getRecruitInfo(i)->getTask();
            fprintf_s(out_fp, "%s, %d, %s", cancel[0], cancel[1], cancel[2]);

            user.recruitInfo[i] = user.getRecruitInfo(i + 1);
            i++;
            while (user->recruitInfo[i].getBusinessNumber != NULL) {
                i++;
                user.recruitInfo[i] = user.getRecruitInfo(i + 1);
            }
        }
        i++;
    }
}



//=================================================================
//=================================================================


void StatisticUI::startStatistic(Member member) {
    fprintf(out_fp, "5.1. ���� ���� ���\n");
    //��ȣ�� ����
    Statistic getStat(Member member);
}

void Statistic::startInterface(Member member) {
    statisticUI = new StatisticUI();
}

void Statistic::getStat(Member member) {
    int i = 0;
    if (member.getType() == 1) {
        User listStat(Member member);
        while (member.getWorkNum(i) != NULL) {
            fprintf_s(out_fp, "%s %d", member.getWorkName(i), member.getWorkNum(i));
        }
    }
    else {
        companyStaff listStat(Member member);
        while (member.getWorkNum(i) != NULL) {
            fprintf_s(out_fp, "%s %d", member.getWorkName(i), member.getWorkNum(i));
        }
    }
}

void User::listStat(Member member) {
    int num = 0;//���� �� ��
    string workName[MAX_STRING] = { NULL };//�������� ����ϱ� ����(���� �̸�)
    int workNum[MAX_STRING] = { NULL };
    int i, l = 0;
    while (member.getRecruitInfo(i) != NULL) {
        for (int j = 0; j <= i; j++) {
            if (member.getRecruitInfo(i)->getTask() == workName[j]) {
                setWorkNum(j);
                continue;
            }//���� �̸��� �̹� ������ workNum�� ���� �ϳ� �ø���
            else {
                setWorkName(l,(member.getRecruitInfo(j)->getTask));
                l++;
            }//�ƴϸ� ���� ������ش�
        }
        i++;
    }
    return;
}
void companyStaff::listStat(Member member) {
    //���� ����ϰ� ���õ�?
    int num = 0;//���� �� ��
    string workName[MAX_STRING] = { NULL };//�������� ����ϱ� ����(���� �̸�)
    int workNum[MAX_STRING] = { NULL };
    int i, l = 0;
    while (member.getRecruitInfo(i) != NULL) {
        for (int j = 0; j <= i; j++) {
            if (member.getRecruitInfo(i)->getTask() == workName[j]) {
                setWorkNum(j);
                continue;
            }//���� �̸��� �̹� ������ workNum�� ���� �ϳ� �ø���
            else {
                setWorkName(l, (member.getRecruitInfo(j)->getTask));
                l++;
            }//�ƴϸ� ���� ������ش�
        }
        i++;
    }
    return;
}
