#include<bits/stdc++.h>
#define MAXN 1000001

int bit[MAXN];

void update(int i, int val){
    while(i <= MAXN){
        bit[i] += val;
        i += (-i & i);
    }
}

/* If using range update, range query with this implementation will not work */
void rangeUpdate(int l, int r, int val){
    update(l, v);
    update(r + 1, -v);
}

int sum(int i){
    int sum = 0;
    while(i > 0){
        sum += bit[i];
        i -= (-i & i);
    }
    return sum;
}

int main()
{

}
