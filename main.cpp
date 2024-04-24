// JAY--DWARKADHISH //

#include <iostream>
#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
#define endl "\n"
map<string, int> topba, topbo;
class node
{
public:
    string s;
    priority_queue<int> pq;
    map<string, int> m1;
    map<int, string> m2;
    int flag;
    node *next;
    node(string s, priority_queue<int> pq, int flag, map<string, int> m, map<int, string> m2)
    { 
        this->s = s;
        this->pq = pq;
        this->next = NULL;
        this->flag = flag;
        this->m1 = m1;
        this->m2 = m2;
    }
};

class player
{

public:
    string date;
    int runs;
    int wickets;

    player(bool b, int match)
    {

        cout << "Please enter the date of the match" << match << " :" << endl;
        cin >> date;
        if (b == true)
        { 
            cout << "Please enter the runs scored by the player:" << endl;
            cin >> runs;
        }
        if (b == false)
        {
            cout << "Please enter the wickets taken by the player:" << endl;
            cin >> wickets;
        }
    }
};

void insertTail(string s, priority_queue<int> pq, node *&tail, int flag, map<string, int> m1, map<int, string> m2)
{

    node *temp = new node(s, pq, flag, m1, m2);
    // this->string=
    tail->next = temp;
    tail = temp;
}

void top()
{
    vector<pair<int, string>> bo, ba;
    for (auto it : topba)
    {
        ba.push_back({it.second, it.first});
    }

    for (auto it : topbo)
    {
        bo.push_back({it.second, it.first});
    }

    sort(all(ba));
    sort(all(bo));
    reverse(all(ba));
    reverse(all(bo));
    int cnt = 0;
    cout << "Top 3 batsman of the series are:" << endl
         << "-------------------------------" << endl;
    for (auto it : ba)
    {
        if (cnt == 3)
        {
            break;
        }
        cout << cnt + 1 << ") " << it.second << " --> " << it.first << endl;
        cnt++;
    }
    cout << endl;
    cnt = 0;

    cout << "Top 3 bowler of the series are:" << endl
         << "-------------------------------" << endl;
    for (auto it : bo)
    {
        if (cnt == 3)
        {
            break;
        }
        cout << cnt + 1 << ") " << it.second << " --> " << it.first << endl;
        cnt++;
    }
}

void print(node *&head)
{
    // cout<<head
    node *temp = head;
    while (temp != NULL)
    {
        map<string, int> m1 = temp->m1;
        map<int, string> m2 = temp->m2;
        priority_queue<int> p = temp->pq;
        vector<pair<string, int>> vt;
        // int totrun=0;
        for (auto it : m1)
        {
            // totrun+=it.second;
            p.push(it.second);
        }

        int cnt = 3;
        cout << "Player Name---> " << temp->s << endl;
        cout << "------------------------" << endl;
        // cout<<"|Date              Runs|"<<endl;
        // cout<<"-----             ----"<<endl;
        while (cnt && !p.empty())
        {
            int num = p.top();
            int sp = 0;
            while (num)
            {
                num /= 10;
                sp++;
            }

            if (sp == 3)
            {
                cout << "|" << m2[p.top()];
                int spa = 5;
                while (spa)
                {

                    cout << " ";
                    spa--;
                }
                spa = 5;
                cout << "|";
                while (spa)
                {

                    cout << " ";
                    spa--;
                }
                cout << p.top() << "|" << endl;
            }

            else if (sp == 2)
            {

                cout << "|" << m2[p.top()];
                int spa = 5;
                while (spa)
                {

                    cout << " ";
                    spa--;
                }
                spa = 5;
                cout << "|";
                while (spa)
                {

                    cout << " ";
                    spa--;
                }
                cout << " " << p.top() << "|" << endl;
            }

            else if (sp == 1)
            {

                cout << "|" << m2[p.top()];
                int spa = 5;
                while (spa)
                {

                    cout << " ";
                    spa--;
                }
                spa = 5;
                cout << "|";
                while (spa)
                {

                    cout << " ";
                    spa--;
                }
                cout << "  " << p.top() << "|" << endl;

                // cout<<p.top()<<"|"<<endl;
            }

            p.pop();
            cnt--;
        }
        cout << "------------------------" << endl;
        cout << endl;
        temp = temp->next;
    }
}

// map<string, int> mba1;
// map<int, string> mba2;
// map<string, int> mbo1;
// map<int, string> mbo2;
vector<string> vba, vbo;
vector<pair<string, map<string, int>>> v;
// priority_queue<int> pba, pbo;

int32_t main()
{
    node *tail;
    node *head;

    cout << "Please enter the number of players whose information is to be printed:" << endl;
    int n;
    cin >> n;
    int temp = 0;
    int pl = n;
    while (n--)
    {

        cout << "please enter the number of matches of player " << pl - n << " whose information is to be added:" << endl;
        int t;
        cin >> t;

        string name;
        string role;
        cout << "Please enter the name if the player:" << endl;
        cin >> name;
        cout << "please enter the role of the player:" << endl;
        cin >> role;

        if (role == "batsman")
        {
            vba.push_back(name);
            int i = 0, match = t;
            map<string, int> mba1;
            map<int, string> mba2;
            priority_queue<int> pba;
            while (t--)
            {

                player p1(true, match - t);
                mba1[p1.date] = p1.runs;
                mba2[p1.runs] = p1.date;
                pba.push(p1.runs);
            }

            if (temp == 0)
            {
                node *n = new node(name, pba, 1, mba1, mba2);
                tail = n;
                head = n;
                temp++;
            }

            else
            {
                insertTail(name, pba, tail, 1, mba1, mba2);
            }
            int totrun = 0;
            while (!pba.empty())
            {
                totrun += pba.top();
                pba.pop();
            }
            topba[name] = totrun;
        }

        else if (role == "bowler")
        {
            map<string, int> mbo1;
            map<int, string> mbo2;
            priority_queue<int> pbo;
            vbo.push_back(name);
            int j = 0, match = t;
            while (t--)
            {
                player p2(false, match - t);
                mbo1[p2.date] = p2.wickets;
                mbo2[p2.wickets] = p2.date;
                pbo.push(p2.wickets);
            }

            if (temp == 0)
            {
                node *n = new node(name, pbo, 0, mbo1, mbo2);
                tail = n;
                head = n;
                temp++;
            }

            else
            {
                insertTail(name, pbo, tail, 0, mbo1, mbo2);
            }

            int totwick = 0;
            while (!pbo.empty())
            {
                totwick += pbo.top();
                pbo.pop();
            }

            topbo[name] = totwick;
        }
    }

    print(head);
    top();

    return 0;
}
