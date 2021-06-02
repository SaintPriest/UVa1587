#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include <stdio.h>
#include <stdbool.h>

int main()
{
    int data[6][2] = { {0} };
    int iptCount = 0, a = 0, b = 0, c = 0, aCount = 0, bCount = 0, cCount = 0;
    bool flag = true;
    while (scanf("%d %d", &data[iptCount][0], &data[iptCount][1]) != EOF)
    {
        if (iptCount == 5)
        {
            a = data[0][0];
            b = data[0][1];
            aCount = 1;
            bCount = 1;
            cCount = 0;
            c = -1;
            flag = true;
            for (int i = 1; i < 6; i++)
            {
                if (data[i][0] == a)
                {
                    aCount++;
                }
                if (data[i][0] == b)
                {
                    bCount++;
                }
                if (data[i][1] == a)
                {
                    aCount++;
                }
                if (data[i][1] == b)
                {
                    bCount++;
                }
                if (data[i][0] != a && data[i][0] != b)
                {
                    if (c != -1 && data[i][0] != c)
                    {
                        flag = false;
                    }
                    c = data[i][0];
                }
                else if (data[i][1] != a && data[i][1] != b)
                {
                    if (c != -1 && data[i][1] != c)
                    {
                        flag = false;
                    }
                    c = data[i][1];
                }
                if (data[i][0] == c)
                {
                    cCount++;
                }
                if (data[i][1] == c)
                {
                    cCount++;
                }
            }

            if (c != -1 && a != b) // all different
            {
                if (aCount != 4 || bCount != 4 || cCount != 4)
                {
                    flag = false;
                }
            }
            else if (c == -1 && a != b)
            {
                if (!((aCount == 8 && bCount == 4) || (aCount == 4 && bCount == 8)))
                {
                    flag = false;
                }
                if (aCount == 8)
                {
                    c = a;
                }
                else if (bCount == 8)
                {
                    c = b;
                }
            }
            else if (a == b && c == -1) // square
            {
                if (aCount != 12)
                {
                    flag = false;
                }
                c = a;
                b = a;
            }
            else if (a == b && c != -1)
            {
                if (aCount != 8 || cCount != 4)
                {
                    flag = false;
                }
            }
            int ab = 0, bc = 0, ac = 0; 
            for (int i = 0; i < 6; i++)
            {
                int orig = ab + bc + ac;
                if ((data[i][0] == a && data[i][1] == b) || (data[i][0] == b && data[i][1] == a))
                {
                    ab++;
                }
                if ((data[i][0] == a && data[i][1] == c) || (data[i][0] == c && data[i][1] == a))
                {
                    ac++;
                }
                if ((data[i][0] == b && data[i][1] == c) || (data[i][0] == c && data[i][1] == b))
                {
                    bc++;
                }
                if (ab + bc + ac == orig)
                {
                    flag = false;
                }
            }
            if (ab < 2 || bc < 2 || ac < 2)
            {
                flag = false;
            }
            if (flag)
            {
                printf("POSSIBLE\n");
            }
            else
            {
                printf("IMPOSSIBLE\n");
            }

            iptCount = 0;
        }
        else
        {
            iptCount++;
        }
    }
}
