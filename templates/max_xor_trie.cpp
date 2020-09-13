#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define rep(i, j, n) for (int i = j; i <= n; i++)
#define repr(i, j, n) for (int i = n - 1; i >= j; i--)
#define test_cases     \
    int test_cases;    \
    cin >> test_cases; \
    while (test_cases--)
#define pb push_back
#define mp make_pair
#define vc vector
#define vi vector<int>
#define pi pair<int, int>
#define vpi vector<pi>
#define pqmx priority_queue<ll>
#define pqmn priority_queue<ll, vector<ll>, greater<int>()>
#define S second
#define F first
#define sc scanf
#define pf printf
#define boost1 ios::sync_with_stdio(false);
#define boost2 cin.tie(0);
#define mem(a, val) memset(a, val, sizeof a)

struct trieNode {
    trieNode* left;
    trieNode* right;
};

void insert(int n, trieNode* head) {
    trieNode* curr = head;
    for(int i = 31;i>=0;i-- ) {
        int b = (n>>i) & 1;
        if(b == 0) {
            if(!curr->left) {
                curr->left = new trieNode;

            }
            curr = curr -> left;
        } else {
            if(!curr -> right) {
                curr -> right = new trieNode;
            }
            curr = curr -> right;
        }
    }
}

int findMaxXorPair(trieNode* head, int * arr, int n) {
    int max_xor = INT_MIN;
    for(int i=0;i<n;i++) {
        int value = arr[i];
        trieNode* curr = head;
        int curr_xor = 0;
        for(int j= 31;j>=0;j--) {
            int b = (value>>j) &1;

            if(b == 0) {
                if(curr -> right) {
                    curr = curr -> right;
                    curr_xor += pow(2,j);
                } else {
                    curr = curr -> left;
                }
            } else {
                if(curr -> left) {
                    curr = curr -> left;
                    curr_xor += pow(2,j);
                } else {
                    curr = curr -> right;
                }
            }
        }
        if(curr_xor > max_xor) {
            max_xor = curr_xor;
        }
    }
    return max_xor;
}

int main() {
    int arr[6] = {8,1,2,15,10,5};
    trieNode* head = new trieNode;
    for(int i=0;i<6;i++) {
        insert(arr[i], head);
    }
    cout<<findMaxXorPair(head, arr, 6)<<endl;
}