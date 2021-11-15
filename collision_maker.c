#include "TXLib.h"
#include "queue"

using namespace std;

vector<vector<int>> add_obj(vector<vector<int>> a, int x, int y, int obj_num, int l);
vector<vector<int>> remove_obj(vector<vector<int>> a, int x, int y, int l);
void draw(vector<vector<int>> a, int x, int y, map<int, COLORREF> dict, int l);

int main()
{
    int x, y, l, k;
    char s[300];
    again:
    printf("Enter block size: ");
    scanf("%d",&l);
    printf("Enter number of blocks (y, x): ");
    scanf("%d%d", &y, &x);
    printf("Enter file name (less than 300 symbols): ");
    scanf("%s", &s);
    printf("Enter number of different blocks (less than 6): ");
    scanf("%d", &k);
    printf("Keys and meanings:\n");
    printf("LMB - add obj\n");
    printf("RMB - remove obj\n");
    printf("MMB - change obj\n");
    printf("Esc - finish\n");
    printf("Colors and meanings:\n");
    printf("Red - code 1\n");
    printf("Blue -code 2\n");
    printf("Yellow - code 3\n");
    printf("Pink - code 4\n");
    printf("Cyan - code 5\n");
    printf("Green - code 0\n");
    printf("Program will make the tablet %dx%d, with named %s\n",y,x,s);
    printf("If correct - press Alt, else - press Esc");

    while(true)
    {
        if (GetAsyncKeyState(VK_MENU))
        {
            system("cls");
            break;
        }
        if (GetAsyncKeyState(VK_ESCAPE))
        {
            system("cls");
            goto again;
        }
    }
    txCreateWindow(x * l, y * l);
    vector<vector<int>> a(y,vector<int> (x));
    map<int, COLORREF> dict;
    dict[0] = RGB(0, 255, 0);
    dict[1] = RGB(255, 0, 0);
    dict[2] = RGB(0, 0, 255);
    dict[3] = RGB(255, 255, 0);
    dict[4] = RGB(255, 0, 255);
    dict[5] = RGB(0, 255, 255);

    queue <int> q;
    for (int i = 1; i <= k; i++)
        q.push(i);
    int using_type = q.front();
    q.pop();
    txSetConsoleAttr(FOREGROUND_WHITE);
    txBegin();
    while(!GetAsyncKeyState(VK_ESCAPE))
    {
        txClear();
        system("cls");
        draw(a,x,y,dict,l);
        printf("Using type is: %d\n", using_type);
        txSleep(10);
        if(GetAsyncKeyState(VK_LBUTTON))
            a = add_obj(a,x,y,using_type,l);
        if(GetAsyncKeyState(VK_RBUTTON))
            a = remove_obj(a,x,y,l);
        if(GetAsyncKeyState(VK_MBUTTON))
        {
            q.push(using_type);
            using_type = q.front();
            q.pop();
            while(GetAsyncKeyState(VK_MBUTTON));
        }
    }
    txEnd();
    FILE *f = fopen(s, "w");
    for (int i = 0; i < y; i++)
    {
        for(int j = 0; j < x; j++)
        {
            fprintf(f, "%d ",a[i][j]);
        }
        fprintf(f, "\n");
    }
}

vector<vector<int>> add_obj(vector<vector<int>> a, int x, int y, int obj_num, int l)
{
    int mx = txMouseX()/l;
    int my = txMouseY()/l;
    if(my >= 0 && my < y && mx >= 0 && mx < x)
        a[my][mx] = obj_num;
    return a;
}

vector<vector<int>> remove_obj(vector<vector<int>> a, int x, int y, int l)
{
    int mx = txMouseX()/l;
    int my = txMouseY()/l;
    if(my >= 0 && my < y && mx >= 0 && mx < x)
        a[my][mx] = 0;
    return a;
}

void draw(vector<vector<int>> a, int x, int y, map<int, COLORREF> dict, int l)
{
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            txSetFillColor(dict[a[i][j]]);
            txSetColor(TX_BLACK, 1);
            txRectangle(j * l, i * l, j * l + l, i * l + l);
        }
    }
}

