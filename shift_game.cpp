#include <bits/stdc++.h>
using namespace std;

static vector<int> get_runs(const string& s) {
    int n = (int)s.size();
    vector<int> runs;
    int len = 1;
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1]) ++len;
        else {
            runs.push_back(len);
            len = 1;
        }
    }
    runs.push_back(len);
    return runs;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        string a, b;
        cin >> a >> b;

        int a0 = 0, a1 = 0, b0 = 0, b1 = 0;
        for (char c : a) (c == '0' ? a0 : a1)++;
        for (char c : b) (c == '0' ? b0 : b1)++;

        vector<long long> queries(q);
        for (int i = 0; i < q; ++i) cin >> queries[i];

        vector<long long> ans(q, 0);

        if (a1 == 0 || b1 == 0) {
            for (int i = 0; i < q; ++i) ans[i] = 0;
        } else if (a0 == 0 && b0 == 0) {
            for (int i = 0; i < q; ++i) ans[i] = queries[i];
        } else if (a0 == 0) {
            int first_one = 0;
            while (b[first_one] != '1') ++first_one;
            for (int i = 0; i < q; ++i) ans[i] = max(0LL, queries[i] - first_one);
        } else if (b0 == 0) {
            int first_zero = 0;
            while (a[first_zero] != '0') ++first_zero;
            for (int i = 0; i < q; ++i) ans[i] = min(queries[i], (long long)first_zero);
        } else {
            auto nice = [&](int pa, int pb) {
                int ppa = (pa - 1 + n) % n;
                int ppb = (pb - 1 + n) % n;
                return a[pa] == '0' && b[pb] == '0' && a[ppa] == '1' && b[ppb] == '1';
            };

            int pa = 0, pb = 0;
            long long score = 0;
            vector<long long> pref_manual(1, 0);

            int guard = 0;
            while (!nice(pa, pb) && guard <= 2 * n + 5) {
                score += (a[pa] - '0') * 1LL * (b[pb] - '0');
                if (a[pa] == b[pb]) pa = (pa + 1) % n;
                else pb = (pb + 1) % n;
                pref_manual.push_back(score);
                ++guard;
            }

            rotate(a.begin(), a.begin() + pa, a.end());
            rotate(b.begin(), b.begin() + pb, b.end());

            vector<int> runsA = get_runs(a), runsB = get_runs(b);
            int mA = (int)runsA.size(), mB = (int)runsB.size();

            vector<long long> prefA(mA + 1, 0), prefB(mB + 1, 0), prefAOnes(mA + 1, 0);
            for (int i = 0; i < mA; ++i) {
                prefA[i + 1] = prefA[i] + runsA[i];
                prefAOnes[i + 1] = prefAOnes[i] + ((i % 2 == 1) ? runsA[i] : 0);
            }
            for (int i = 0; i < mB; ++i) prefB[i + 1] = prefB[i] + runsB[i];

            auto steps_for_blocks = [&](long long blocks) {
                long long takeA = (blocks + 1) / 2;
                long long takeB = blocks / 2;

                long long fullA = takeA / mA, remA = takeA % mA;
                long long fullB = takeB / mB, remB = takeB % mB;

                long long res = 0;
                res += fullA * n + prefA[(int)remA];
                res += fullB * n + prefB[(int)remB];
                return res;
            };

            auto score_for_a_blocks = [&](long long takeA) {
                long long full = takeA / mA, rem = takeA % mA;
                return full * prefAOnes[mA] + prefAOnes[(int)rem];
            };

            for (int qi = 0; qi < q; ++qi) {
                long long k = queries[qi];
                if (k < (long long)pref_manual.size()) {
                    ans[qi] = pref_manual[(size_t)k];
                    continue;
                }

                long long res = pref_manual.back();
                long long rem = k - ((long long)pref_manual.size() - 1);

                long long lo = 0, hi = rem;
                while (lo < hi) {
                    long long mid = (lo + hi + 1) / 2;
                    if (steps_for_blocks(mid) <= rem) lo = mid;
                    else hi = mid - 1;
                }

                long long full_blocks = lo;
                long long used = steps_for_blocks(full_blocks);
                long long left = rem - used;

                long long doneA = (full_blocks + 1) / 2;
                res += score_for_a_blocks(doneA);

                bool next_is_a = (full_blocks % 2 == 0);
                if (next_is_a) {
                    int idxA = (int)(doneA % mA);
                    if (idxA % 2 == 1) res += left;
                }

                ans[qi] = res;
            }
        }

        for (int i = 0; i < q; ++i) {
            cout << ans[i] << (i + 1 == q ? '\n' : ' ');
        }
    }

    return 0;
}
