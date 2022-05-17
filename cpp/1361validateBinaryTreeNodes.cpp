class Solution {
private:
    int count;  // Union-Find  ͼ�Ķ�̬��ͨ��  ���鼯��һ���������ݽṹ, ���ڴ���һЩ���ཻ���ϵĺϲ�����ѯ����
    vector<int> parent;  // ����ģ��һ��ɭ��
    vector<int> size;
    void initUF(int n) {
        count = n;
        parent.assign(n, 0);
        size.assign(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int a) {
        while (parent[a] != a) {
            parent[a] = parent[parent[a]];
            a = parent[a];
        }
        return a;
    }
    void uni(int a, int b) {
        int roota = find(a);
        int rootb = find(b);
        if (roota == rootb) return;
        if (size[roota] <= size[rootb]) {
            parent[roota] = rootb;
            size[rootb] += size[roota];
        } else {
            parent[rootb] = roota;
            size[roota] += size[rootb];
        }
        count--;
    }
    bool connected(int a, int b) {
        int roota = find(a);
        int rootb = find(b);
        return roota == rootb;
    }
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // ʹ�ò��鼯���, ÿһ�κϲ��������ܲ����� (��ͬһ�������е�Ԫ�غϲ�), ���ռ�������Ϊ1
        initUF(n);
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                if (connected(i, leftChild[i])) return false;  // ���i��i�ĺ��ӽڵ�����ͬһ��������, ��ô���ڻ�
                uni(i, leftChild[i]);
            }
            if (rightChild[i] != -1) {
                if (connected(i, rightChild[i])) return false;
                uni(i, rightChild[i]);
            }
        }
        return count == 1;
    }
};