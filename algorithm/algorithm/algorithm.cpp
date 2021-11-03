#include <iostream>
#include <queue>

using namespace std;

class Job {
public:
    int workIndex;      // 작업 구분을 위한 변수
    int requestTime;    // 고객 서비스 요청 시간
    int serviceTime;    // 고객이 요청한 서비스를 처리하는데 드는 시간
    int startTime;      // 고객의 서비스가 시작되는 시간
    int endTime;        // 고객의 서비스가 종료되는 시간
public:
    Job(int index, int i, int j) {
        workIndex = index;
        requestTime = i;
        serviceTime = j;
        startTime = 0;
        endTime = 0;
    }
};

// priority Queue에 들어가는 값의 비교를 위해 사용
struct compare {
    bool operator()(Job* a, Job* b) {
        //     ★ 문제 1 --------------------------------------
        //        우선순위 큐의 넣기 위해서 Job의 크기 비교 기준을 제시 
        return a->serviceTime > b->serviceTime;
        //      -----------------------------------------------★
    }
};

// 일 처리를 매니징하고 컨트롤하는 클래스
class Jobschedule {
    // 고객의 요청 정보들을 담는 컨테이너
    vector<Job*> InputJobs;
    // 먼저 처리해야 하는 작업들을 고려해서 담는 컨테이너
    priority_queue<Job*, vector<Job*>, compare> WaitJob;
    // 최종적으로 순서대로 처리되는 작업들을 담는 컨테이너
    vector<Job*> JobSchedule;
    int count;              // 현재 처리중인 작업의 인덱스
    Job* cJob;
    int serviceStartTime;   // 현재 처리중인 작업 시작 시간
    int serviceEndTime;     // 현재 처리가 끝난 작업 시작 시간
    int TotalProcessTime;   // 현재까지의 각 요청에 대한 요청부터 처리까지 걸린 시간
public:
    Jobschedule(vector<vector<int>> jobs) {
        count = 0;
        cJob = NULL;
        serviceStartTime = 0;
        serviceEndTime = 0;
        TotalProcessTime = 0;
        for (int i = 0; i < jobs.size(); i++) {
            InputJobs.push_back(new Job(i + 1, jobs[i][0], jobs[i][1]));
        }
    }
    ~Jobschedule() {
        for (int i = 0; i < InputJobs.size(); i++) {
            delete InputJobs[i];
        }
    }
    void JobSearch(int Time) {
        while (count < InputJobs.size()) {
            if (InputJobs[count]->requestTime <= Time) //cJob->serviceTime)
            {
                WaitJob.push(InputJobs[count]);
                count++;
            }
            else
                break;
        }
    }
    void JobWork() {
        while (!WaitJob.empty()) {
            cJob = WaitJob.top();
            WaitJob.pop();

            //     ★ 문제 2 --------------------------------------
            //        우선순위 큐에서 대기하고 있는 요청들을 빼내서 
            //        JobSchedule에 넣을 수 있도록 한다. 
            //        1) cJob의 멤버 변수들(startTime, endTime)의 값을 채운다. 
            //        2) serviceStartTime과 serviceEndTime도 값을 채운다.
            //        3) 고객들의 각 요청에 대한 "요청 시간 부터 
            //          서비스가 처리된 시간"까지의 시간들의 합을 
            //          TotalProcessTime에 담는다.
            //      ----------------------------------------------★
            cJob->startTime = serviceEndTime;
            cJob->endTime = cJob->startTime + cJob->serviceTime;
            serviceStartTime = cJob->startTime;
            serviceEndTime = cJob->endTime;
            TotalProcessTime += cJob->endTime - cJob->requestTime;
            JobSchedule.push_back(cJob);
            JobSearch(serviceEndTime);
        }
    }
    void JobInit() {
        count = 0;
        cJob = InputJobs[count];
        WaitJob.push(cJob);
        count++;
        JobWork();
    }
    void PrintJobSchedule() {
        for (int i = 0; i < JobSchedule.size(); i++) {
            cout << "[ Work Index : " << JobSchedule[i]->workIndex << " ]" << endl;
            cout << " 1. Work Request Time : " << JobSchedule[i]->requestTime << endl;
            cout << " 2. Work Start Time : " << JobSchedule[i]->startTime << endl;
            cout << " 3. Work End Time :" << JobSchedule[i]->endTime << endl;
            cout << " 4. Total Processing Time : " << JobSchedule[i]->endTime - JobSchedule[i]->requestTime << endl;
        }
        cout << "------------------------------------" << endl;
        cout << "Total Processing Average Time : " << (float)TotalProcessTime / JobSchedule.size() << endl;
    }
};

int main()
{
    printf("■ [문제2] 코드 작성  \n■ 수험번호: 수험번호 기재 \n■ 성    명: 성명 기재\n");
    printf("\n■  우선순위 큐 응용 ■ \n");


    //vector<vector<int>> jobs = { {0,5}, {1,4},{2,5},{3,3},{4,3}, {5,3},{6,4},{7,3},{8,5} };
    vector<vector<int>> jobs = { {0,5}, {1,6},{2,4},{3,3} };

    Jobschedule jobWork(jobs);
    jobWork.JobInit();
    jobWork.PrintJobSchedule();

    int a;
    cin >> a;
}