// Range add + range sum query 

void push(int v, ll tl, ll tr) {
    ll tm = (tl + tr) / 2;
    t[v*2] += lazy[v]*(tm-tl+(ll)1);
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v]*(tr-tm);
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}
 
void update(int v, ll tl, ll tr, ll l, ll r, ll addend) {
    if (l > r) return;
    if (l == tl && tr == r) {
        t[v] += addend*(tr-tl+(ll)1);
        lazy[v] += addend;
    } else {
        push(v, tl, tr);
        ll tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
		t[v] = t[v*2] + t[v*2+1];
    }
}
 
ll query(int v, ll tl, ll tr, ll l, ll r) {
    if (l > r) return 0;
    if (l == tl && tr == r)
        return t[v];
    push(v, tl, tr);
    ll tm = (tl + tr) / 2;
    return query(v*2, tl, tm, l, min(r, tm)) + query(v*2+1, tm+1, tr, max(l, tm+1), r);
}
