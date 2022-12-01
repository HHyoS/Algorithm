#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <vector>
#include <set>
#include <memory.h>
#define CMD_INIT 1
#define CMD_HIRE 2
#define CMD_FIRE 3
#define CMD_UPDATE_STUDENT 4
#define CMD_UPDATE_TEAM 5
#define CMD_BEST_STUDENT 6


using namespace std;



struct Node {
    int mID;
    int mTeam;
    Node* before;
    Node* next;
};


Node student[100001];
Node info[6][6][2];
void init()
{
    memset(student, 0, sizeof(student));
    memset(info, 0, sizeof(info));
    for (int a = 1; a < 6; ++a) {
        for (int b = 1; b < 6; ++b) {
            info[a][b][0].next = &info[a][b][1];
            info[a][b][0].mID = -1;
            info[a][b][1].before = &info[a][b][0];
            info[a][b][1].mID = -1;

        }
    }
}

void hire(int mID, int mTeam, int mScore)
{
       student[mID].before = info[mTeam][mScore][1].before;
       student[mID].next = &info[mTeam][mScore][1];
       student[mID].mTeam = mTeam;
       student[mID].mID = mID;
       info[mTeam][mScore][1].before->next = &student[mID];
       info[mTeam][mScore][1].before = &student[mID];
}

void fire(int mID)
{
    student[mID].before->next = student[mID].next;
    student[mID].next->before = student[mID].before;
}

void updateStudent(int mID, int mScore)
{
    int mTeam = student[mID].mTeam;
    fire(mID);

    hire(mID, mTeam, mScore);
}

void updateTeam(int mTeam, int mChangeScore)
{
    Node tmp[6][2];
    for (int a = 1; a < 6; ++a) {
        tmp[a][0].next = &tmp[a][1];
        tmp[a][0].mID = -1;
        tmp[a][1].before = &tmp[a][0];
        tmp[a][1].mID = -1;
    }

    for (int a = 1; a < 6; ++a) {
        if (info[mTeam][a][0].next == &info[mTeam][a][1]) {
            continue;
        }
        int temp = a + mChangeScore;
        if (temp > 5) {
            temp = 5;
        }
        else if (temp < 1) {
            temp = 1;
        }

        Node* start = info[mTeam][a][0].next;
        Node* end = info[mTeam][a][1].before;

        

        Node* front = tmp[temp][1].before;
        front->next = start;
        start->before = front;
        end->next = &tmp[temp][1];
        tmp[temp][1].before = end;
        

    }
    for (int a = 1; a < 6; ++a) {
        if (tmp[a][0].next == &tmp[a][1]) {
            info[mTeam][a][0].next = &info[mTeam][a][1];
            info[mTeam][a][1].before = &info[mTeam][a][0];
        }
        else {
            Node* start = tmp[a][0].next;
            Node* end = tmp[a][1].before;
            info[mTeam][a][0].next = start;
            start->before = &info[mTeam][a][0];
            info[mTeam][a][1].before = end;
            end->next = &info[mTeam][a][1];
        }
     }

}

int bestStudent(int mTeam)
{


    int idx= -1;
    for (int a = 5; a > 0; --a) {
        if (info[mTeam][a][0].next->mID == -1) continue;
        Node* nNode = info[mTeam][a][0].next;
        while (nNode != &info[mTeam][a][1]) {
            if (idx < nNode->mID)
                idx = nNode->mID;
            nNode = nNode->next;
        }
        break;
    }
    return idx;
}
static bool run()
{
    int numQuery;

    int mID, mTeam, mScore, mChangeScore;

    int userAns, ans;

    bool isCorrect = false;

    scanf("%d", &numQuery);

    for (int i = 0; i < numQuery; ++i)
    {
        int cmd;
        scanf("%d", &cmd);
        switch (cmd)
        {
        case CMD_INIT:
            init();
            isCorrect = true;
            break;
        case CMD_HIRE:
            scanf("%d %d %d", &mID, &mTeam, &mScore);
            hire(mID, mTeam, mScore);
            break;
        case CMD_FIRE:
            scanf("%d", &mID);
            fire(mID);
            break;
        case CMD_UPDATE_STUDENT:
            scanf("%d %d", &mID, &mScore);
            updateStudent(mID, mScore);
            break;
        case CMD_UPDATE_TEAM:
            scanf("%d %d", &mTeam, &mChangeScore);
            updateTeam(mTeam, mChangeScore);
            break;
        case CMD_BEST_STUDENT:
            scanf("%d", &mTeam);
            userAns = bestStudent(mTeam);
            scanf("%d", &ans);
            if (userAns != ans)
            {
                isCorrect = false;
            }
            break;
        default:
            isCorrect = false;
            break;
        }
    }

    return isCorrect;
}

int main()
{
    setbuf(stdout, NULL);
    freopen("input.txt", "r", stdin);

    int T, MARK;
    scanf("%d %d", &T, &MARK);

    for (int tc = 1; tc <= T; tc++)
    {
        int score = run() ? MARK : 0;
        printf("#%d %d\n", tc, score);
    }

    return 0;
}
