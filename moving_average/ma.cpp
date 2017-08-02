#include <vector>
#include <iostream>
using namespace std;

//prevent value's copy & Unintended modify(const vector<double> &)
vector<double> movingAverage1(const vector<double>& A, int M) 
{
    int n = A.size();
    vector<double> ret;
    double partialSum = 0;
    for(int i = 0; i < M-1; i++){
        partialSum += A[i];
    }
    for(int i = M-1; i < n; i++){
        partialSum += A[i];
        ret.push_back(partialSum/M);
        partialSum -= A[i-M+1];
    }
    return ret;
}

int main(void)
{
    int n,m;
    vector<double> data;

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        double temp;
        cin >> temp;
        data.push_back(temp);
    }
    vector<double> ma = movingAverage1(data,m);
    for(vector<double>::iterator iter=ma.begin(); iter != ma.end(); iter++)
        cout << *iter << ' ';
    cout << endl;
}
    

        
            
    
