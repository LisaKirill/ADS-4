// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int cnt = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                cnt += 1;
            }
        }
    }
    return cnt;
}

int countPairs2(int *arr, int len, int value) {
  int lt = 0;
    int rt = len - 1;
    int cnt = 0;
    while (lt < rt) {
        int cSum = arr[lt] + arr[rt];
        if (cSum == value) {
            if (arr[lt] == arr[rt]) {
                int size = rt - lt + 1;
                cnt = cnt + size * (size - 1) / 2;
                break;
            }
            int leftVal = arr[lt];
            int rightVal = arr[rt];
            int idx = lt;
            int leftCnt = 0;
            while (idx <= rt && arr[idx] == leftVal) {
                leftCnt++;
                idx++;
            }
            idx = rt;
            int rightCnt = 0;
            while (idx >= lt && arr[idx] == rightVal) {
                rightCnt++;
                idx--;
            }
            cnt = cnt + leftCnt * rightCnt;
            lt = lt + leftCnt;
            rt = rt - rightCnt;
        } else if (cSum < value) {
            lt++;
        } else {
            rt--;
        }
    }
    return cnt;
}
int countPairs3(int *arr, int len, int value) {
  int cnt = 0;
    for (int i = 0; i < len - 1; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }
        int n = value - arr[i];
        if (n < arr[i]) {
            break;
        }
        int l = i + 1;
        int h = len - 1;
        int first = -1;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (arr[mid] == n) {
                first = mid;
                h = mid - 1;
            } else if (arr[mid] < n) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        if (first == -1) {
            continue;
        }
        l = first;
        h = len - 1;
        int last = first;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (arr[mid] == n) {
                last = mid;
                l = mid + 1;
            } else if (arr[mid] < n) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        if (arr[i] == n) {
            int lenRange = last - i + 1;
            cnt = cnt + lenRange * (lenRange - 1) / 2;
            break;
        }
        int leftCnt = 1;
        while (i + leftCnt < len && arr[i + leftCnt] == arr[i]) {
            leftCnt++;
        }
        cnt = cnt + leftCnt * (last - first + 1);
    }
    return cnt;
}
