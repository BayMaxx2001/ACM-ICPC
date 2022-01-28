#include <bits/stdc++.h>
#define maxn 100
#define PB push_back
using namespace std;

long long Rand(long long l, long long h)
{
    return l + ((long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) * (RAND_MAX + 1) +
                (long long)rand() * (RAND_MAX + 1) +
                rand()) %
                   (h - l + 1);
}

struct toado
{
    long long x;
    long long y;
    int type;
} input[6];

void genTest()
{
    std::random_device rd;

    /* Random number generator */
    std::default_random_engine generator(rd());

    /* Distribution on which to apply the generator */
    std::uniform_int_distribution<long long unsigned> distribution(0, 1e120);
    int id = 1 + (rand() % static_cast<int>(5 - 1 + 1));
    for (int i = 1; i <= 5; i++)
    {
        input[i].x = distribution(generator);
        input[i].y = distribution(generator);
        if (i == id)
        {
            input[i].type = 1;
        }
        else
            input[i].type = 0;
    }
}

void genSmallTest()
{
    std::random_device rd;                          // obtain a random number from hardware
    std::mt19937 gen(rd());                         // seed the generator
    std::uniform_int_distribution<> distr(-10, 10); // define the range

    for (int i = 1; i <= 5; i++)
    {
        string file = "test" + std::to_string(i) + ".txt";
        std::ofstream outfile(file);
        int id = 1 + (rand() % static_cast<int>(5 - 1 + 1));
        for (int i = 1; i <= 5; i++)
        {
            if (i == id)
            {
                input[i].type = 1;
            }
            else
                input[i].type = 0;
            input[i].x = distr(gen);
            input[i].y = distr(gen);
        }
        for (int i = 1; i <= 5; i++)
            outfile << input[i].x << " " << input[i].y << " " << input[i].type << std::endl;
        outfile.close();
    }
}

void genMediumTest()
{
    std::random_device rd;
    std::mt19937 gen(rd());                           // seed the generator
    std::uniform_int_distribution<> distr(-100, 100); // define the range

    for (int i = 6; i <= 10; i++)
    {
        string file = "test" + std::to_string(i) + ".txt";
        std::ofstream outfile(file);
        int id = 1 + (rand() % static_cast<int>(5 - 1 + 1));
        for (int i = 1; i <= 5; i++)
        {
            input[i].x = distr(gen);
            input[i].y = distr(gen);
            if (i == id)
            {
                input[i].type = 1;
            }
            else
                input[i].type = 0;
        }
        for (int i = 1; i <= 5; i++)
            outfile << input[i].x << " " << input[i].y << " " << input[i].type << std::endl;

        outfile.close();
    }
}
void genBigTest()
{
    for (int i = 11; i <= 20; i++)
    {
        string file = "test" + std::to_string(i) + ".txt";
        std::ofstream outfile(file);
        genTest();
        for (int i = 1; i <= 5; i++)
            outfile << input[i].x << " " << input[i].y << " " << input[i].type << std::endl;

        outfile.close();
    }
}
int main()
{
    genSmallTest();
    genMediumTest();
    genBigTest();
}