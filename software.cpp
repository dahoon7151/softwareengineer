
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

    fprintf_s(out_fp, "1.1. 회원가입\n"); fprintf(out_fp, "%s %s %s %s\n", name, SSN, ID, password);
}



















void ApplicationUI::startApplication() {
    fprintf(out_fp, "4.3. 지원 정보 조회\n");
    Application startInterface();
}

void ApplicationUI::startCancel() {
    fprintf(out_fp, "4.4. 지원 취소\n");
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
    fprintf(out_fp, "5.1. 지원 정보 통계\n");
    //신호를 전달
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
    int num = 0;//개수 샐 곳
    string workName[MAX_STRING] = { NULL };//업무별로 출력하기 위함(업무 이름)
    int workNum[MAX_STRING] = { NULL };
    int i, l = 0;
    while (member.getRecruitInfo(i) != NULL) {
        for (int j = 0; j <= i; j++) {
            if (member.getRecruitInfo(i)->getTask() == workName[j]) {
                setWorkNum(j);
                continue;
            }//만약 이름이 이미 있으면 workNum에 개수 하나 올리고
            else {
                setWorkName(l,(member.getRecruitInfo(j)->getTask));
                l++;
            }//아니면 업무 기록해준다
        }
        i++;
    }
    return;
}
void companyStaff::listStat(Member member) {
    //위와 비슷하게 나올듯?
    int num = 0;//개수 샐 곳
    string workName[MAX_STRING] = { NULL };//업무별로 출력하기 위함(업무 이름)
    int workNum[MAX_STRING] = { NULL };
    int i, l = 0;
    while (member.getRecruitInfo(i) != NULL) {
        for (int j = 0; j <= i; j++) {
            if (member.getRecruitInfo(i)->getTask() == workName[j]) {
                setWorkNum(j);
                continue;
            }//만약 이름이 이미 있으면 workNum에 개수 하나 올리고
            else {
                setWorkName(l, (member.getRecruitInfo(j)->getTask));
                l++;
            }//아니면 업무 기록해준다
        }
        i++;
    }
    return;
}
