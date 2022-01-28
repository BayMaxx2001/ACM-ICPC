#include <bits/stdc++.h>
#define PB push_back
#define mp make_pair
using namespace std;

typedef pair<int,int> pii;
vector<pii> baoquanh;
vector<double> vectorTrongtam;
vector<bool> hn[5050];
int n, w, h, m;
pii a[100001];
int main()
{
    cin >> n >> w;
    cin >> h >> m;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<n;j++)
            hn[i].PB(1);
        vectorTrongtam.PB((double)n/2);
        baoquanh.PB(mp(0,n));
    }

    if ( h == 1 )
    {
        cout <<"no" << endl;
        return 0;
    }
    for(int i=0;i<m;i++)
    {
        int x, y;
        cin >> x >> y;
        x -- ;
        y -- ;
        hn[x][y] = 0;
        int cnt = 0;
        double sum = 0;
        for(int j=0;j<n;j++)
        {
            sum += hn[x][j]*(j+0.5);
            cnt += hn[x][j];
        }
        double trongtam = sum/cnt;
        vectorTrongtam[x] = trongtam;

        int fs = 0 , ls = 0 ;
        for(int j=0;j<n;j++)
        {
            if ( hn[x][j])
            {
                fs = j;
                break;
            }
        }
        for(int j=n-1; j>= 0; j -- )
        {
            if ( hn[x][j])
            {
                ls = j+1;
                break;
            }
        }

        baoquanh[x] = mp(fs,ls);

        if ( x != h - 1)
        {
            if ( ls <= (double)n/2 || fs >= (double)n/2 )
            {
                cout <<"yes" << endl << i + 1;
                return 0;
            }
        }
        if ( ls < fs )
        {
            cout <<"yes" << endl << i + 1;
            return 0;
        }
        //check trong tam hien tai dong xuong co bi do khong
        for(int j = x-1;j>=0;j--)
        {
            double d = baoquanh[j].first;
            double r = baoquanh[j].second;
            if(trongtam >= r || trongtam <= d )
            {
                cout <<"yes"<< endl << i + 1 ;
                return 0;
            }
        }
        // check bao quanh hien tai co lam sap o tren khong

        for(int j=x+1;j<h;j++)
        {
            double d = baoquanh[j].first;
            double r = baoquanh[j].second;
            if(vectorTrongtam[j] >= r || vectorTrongtam[j] <= d )
            {
                cout <<"yes"<< endl << i + 1;
                return 0;
            }
        }
    }
    cout <<"no";
    return 0;
}





