
#include <iostream>
#include <algorithm>

    using namespace std;
    const int MAX = 105;
    int A[MAX];

    int main()
    {
        int T, N, numberOfThings = 0, currentTime = 0;
        cin >> N >> T;
        for(int i = 0;i < N;++i)
            cin >> A[i];
        sort(A, A + N);
        for(int i = 0;i < N;++i)
        {
            currentTime += A[i];
            if(currentTime > T)
                break;
            numberOfThings++;
        }
        cout << numberOfThings << endl;
        return 0;

        }
