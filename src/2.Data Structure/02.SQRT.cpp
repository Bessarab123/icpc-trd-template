ll n;
const int maxn = 2 * 1e5, c = 448; //c=sqrt(maxn)
vll arr(maxn), block(c), add(c);

void calc_sqrt() {
    for (ll i = 0; i < n; i++) {
        block[i / c] += arr[i];
    }
}

ll sum(ll l, ll r) {
    ll res = 0;
    while (l <= r) {
        if (l % c == 0 && l + c - 1 <= r) {
            res += block[l / c];
            l += c;
        }
        else {
            res += arr[l] + add[l / c];
            l += 1;
        }
    }
    return res;
}

void upd(ll l, ll r, ll x) {//arr[l...r]+=x
    while (l <= r) {
        if (l % c == 0 && l + c - 1 <= r) {
            block[l / c] += c * x;
            add[l / c] += x;
            l += c;
        }
        else {
            block[l / c] += x;
            arr[l] += x;
            l++;
        }
    }
}
