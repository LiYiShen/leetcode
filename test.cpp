�����⣬������ҳ����������

��һ��Next�����ƶ��ڵ��ǰ�����������ƶ���
�ǵ�

���ݵĹ����Լ�������У���
���������������½�


1. ʵ��һ�������������ĵ�������
��Ĺ��캯������Ƕ����������ĸ��ڵ�
����һ��Next����֧���ƶ������������ص�������ǰָ��Ľڵ�

�����������ڵ㶨������
struct TreeNode {
		int value;
		struct TreeNode * left, * right;
};

class Iter {
public:
    void Inorder(TreeNode* root) {
        if (!root) return;
        Inorder(root->left);
        vec.push_back(root->val);
        Inorder(root->right);
    }

    Iter(TreeNode* root) {
        Inorder(root);
        start = 0;
    }
    int Next() {
        if (start >= vec.size()) return -1;
        return vec[start++];
    }
private:
    int start;
    vector<int> vec;
}

2. һ������ΪN�����У����������ƶ������е�������ʵ��һ���������������б�Ϊ����������ƶ�����
ʾ��������4,1,2,3,5,6,7,8 ��4�ƶ���3��5֮�䣬��һ���ƶ�

int minExchange(vector<int>& nums) {
    int n = nums.size();
    vector<int> sortedNums(nums.begin(), nums.end());
    sort(sortedNums.begin(), sortedNums.end());
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (sortedNums[i] != nums[i]) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] == sortedNums[i]) {
                    swap(nums[j], nums[i]);
                    res++;
                }
            }
        }
    }
    return res;
}

3. �����������ʣ�start��end����һ���ֵ䣬ÿ��ֻ�ܸı�һ����ĸ���任�����еĵ��ʱ������ֵ��г��֣��������start��end�����ת�����г��ȡ�
ע�⣬���û��ת�������򷵻�0�����е��ʾ�����ͬ�ĳ��ȣ����е��ʶ�ֻ����Сд��ĸ��
ʾ����start = "abc"��end = "xyz"��dict = ["aoc","xoc","xoz","not"]

int minDistance(string start, string end, vector<string>& dict) {
    queue<string> q;
    q.push(start);
    int res = 0;
    while (!q.empty()) {
        res++;
        for (int sz = q.size(); sz > 0; sz--) {
            string cur = q.front();
            if (cur == end) {
                return res;
            }
            q.pop();
            for (auto & w: dict) {
                //if (w.empty()) continue;
                int diff = 0;
                for (int i = 0; i < w.size(); i++) {
                    if (w[i] != cur[i]) ++diff;
                    if (diff > 1) break;
                }
                if (diff <= 1) {
                    q.push(w);
                    w = "";
                }
            }
        }
    }
    return 0;
}

4. һ��д��¥�����жಿ���� �������һ������ʵ�ֵ��ݵĹ��� ��Ҫ������Ľӿڶ��塢�ؼ������ݽṹ

class elevator {
public:
    elevator(int floors) {
    	_floors = floors;
    }
    void up(int n){
    	_target = n;
      run();
    }
    void down(int n){
    	_target = n;
      run();
    }
    void run() {

    }

private:
    int _floors;
    int _now;
    int _target;
}

