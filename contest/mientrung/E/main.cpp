#include <stdio.h>

#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
#define X first
#define Y second

ii origin;
void operator-=(ii &A, ii B) {
    A.X -= B.X;
    A.Y -= B.Y;
}

bool ccw(ii O, ii A, ii B) {
    A -= O, B -= O;
    return A.X * B.Y > A.Y * B.X;
}
bool cmp(ii A, ii B) { return ccw(origin, A, B); }

int n;

void solve()
{
    ii a[100];
    n = 4;
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &a[i].X, &a[i].Y);
    sort(a + 1, a + n + 1);
    origin = a[1];
    sort(a + 2, a + n + 1, cmp);
    a[0] = a[n];
    a[n + 1] = a[1];
    int j = 1;
    for (int i = 1; i <= n + 1; i++) {  // a[1] and a[n+1] will be both added
        while (j > 2 && !ccw(a[j - 2], a[j - 1], a[i])) j--;
        a[j++] = a[i];
    }
    n = j - 2;
    if ( n == 4 )
    {
        printf("%s\n","YES");
    }
    else
        printf("%s\n","NO");
    //for (int i = 1; i <= n; i++) printf("%d %d\n", a[i].X, a[i].Y);
}
int main() {
    int te;
    scanf("%d" ,&te);
    while ( te -- )
        solve();
}
