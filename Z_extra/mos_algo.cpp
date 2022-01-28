/*
    -> Mo's Algorithm
    -> ref: https://cp-algorithms.com/data_structures/sqrt_decomposition.html#mos-algorithm
*/

void rem(int idx);
void add(int idx);
int getAnswer();

const int SZ; //block size

struct Query {
    int l, r, idx;

    bool operator<(Query other) const {
        return make_pair(l / SZ, r) < make_pair(other.l / SZ, other.r);
    }
};

vector<int> MosAlgo(vector<Query> queries) {
    vector<int> answers(queries.size());

    sort(queries.begin(), queries.end());

    int cur_l = 0;
    int cur_r = -1;

    for (Query &q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }

        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }

        while (cur_l < q.l) {
            rem(cur_l);
            cur_l++;
        }

        while (cur_r > q.r) {
            rem(cur_r);
            cur_r--;
        }

        answers[q.idx] = getAnswer();
    }

    return answers;
}
