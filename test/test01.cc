#include <iostream>
#include <vector>
using namespace std;
void old_test(void);
int main(){
    vector<int> d{1};
    vector<int> c;
    c.insert(c.begin(), 1, 2);
    c.insert(c.begin() + 1, 1, 3);
    c.emplace(c.end(), 1);
    cout << c[1] << endl;
    return EXIT_SUCCESS;
}
void old_test(void){
    vector<int> val1;
    val1.push_back(10);
    vector<int> val2(val1);
    vector<int> val3(val2.begin(), val2.end());
    vector<int> val4{1, 2, 3};
    vector<int> val5 = {1, 2, 3};
    int n = 4;
    vector<int> val6(n, 1);
    cout << val6[2] << endl;

    vector<int> a, b;
    b = {1, 2, 3};
    a = b;
    a.push_back(1);
    b.push_back(3);
    a.swap(b);
    swap(a, b);
}