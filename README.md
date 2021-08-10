## PRACTICE MAKES PERFECT (Once for all? ! No way!)
------
- **��̬�滮**�ĺ�����������٣���������������ڡ��ص������⡹�����������ٵĻ�Ч�ʻἫ����£�������Ҫ������¼�����ߡ�DP table�����Ż���ٹ��̡�
- ��ȷ base case --> ��ȷ��״̬��--> ��ȷ��ѡ�� --> ���� dp ����/�����ĺ��塣
- ��̬�滮��ܣ�
  ```
  ��ʼ�� base case
  dp[0][0][...] = base
  ����״̬ת��
  for ״̬1 in ״̬1������ȡֵ��
      for ״̬2 in ״̬2������ȡֵ��
          for ...
              dp[״̬1][״̬2][...] = ����ֵ(ѡ��1��ѡ��2...)
  ```
- **��������**��ʵ���Ͼ���һ���������ı������̣������ʾ��˻���һ����ͨ��Լ������, ����ʱ�临�Ӷȡ�
- �����㷨��DFS���Ŀ�ܣ�
  ```
  result = []
  def backtrack(·��, ѡ���б�):
      if �����������:
          result.add(·��)
          return
      for ѡ�� in ѡ���б�:
       	  ��ѡ��
       	  ����ѡ���ѡ���б��Ƴ�
      	  ·��.add(ѡ��)
      	  backtrack(·��, ѡ���б�)
      	  ����ѡ��
      	  ·��.remove(ѡ��)
      	  ����ѡ���ټ���ѡ���б�
  ```
- **BFS**���ʣ���һ����㣬�ߵ��յ㣬�����·����
  ```
  // �������� start ���յ� target ���������
  int BFS(Node start, Node target) {
      queue<Node> q; 		  // �������ݽṹ
      set<Node> visited;  // �����߻�ͷ·
  	  q.push(start); 		  // �����������
  	  visited.add(start);
  	  int step = 0; 		  // ��¼��ɢ�Ĳ���
  	  while (q not empty) {
      int sz = q.size();
      /* ����ǰ�����е����нڵ���������ɢ */
      for (int i = 0; i < sz; i++) {
          Node cur = q.pop();
          if (cur is target)	     // �ж��Ƿ񵽴��յ�
              return step;
          for (Node x : cur.adj()) // ��cur���ڽڵ����
              if (x not in visited) {
                  q.push(x);
                  visited.add(x);
              }
      }
      step++;		// ���²���
  }
  ```
- ����**��������**
  ```
  int binary_search(int[] nums, int target) {
      int left = 0, right = nums.length - 1;
      while (left <= right) {
          int mid = left + (right - left) / 2;
          if (nums[mid] < target) {
              left = mid + 1;
          } else if (nums[mid] > target) {
              right = mid - 1;
          } else if(nums[mid] == target) {
              // ֱ�ӷ���
              return mid;
          }
      }
      // ֱ�ӷ���
      return -1;
  }
  ```
- Ѱ��**���Ҳ�߽�**�Ķ�������
  ```
  int left_bound(int[] nums, int target) {
      int left = 0, right = nums.length - 1;
      while (left <= right) {
          int mid = left + (right - left) / 2;
          if (nums[mid] < target) {
              left = mid + 1;
          } else if (nums[mid] > target) {
              right = mid - 1;
          } else if (nums[mid] == target) {
              right = mid - 1;  // �������߽�
          }
      }
      // ��� left Խ������
      if (left >= nums.length || nums[left] != target)
          return -1;
      return left;
  }

  int right_bound(int[] nums, int target) {
      int left = 0, right = nums.length - 1;
      while (left <= right) {
          int mid = left + (right - left) / 2;
          if (nums[mid] < target) {
              left = mid + 1;
          } else if (nums[mid] > target) {
              right = mid - 1;
          } else if (nums[mid] == target) {
              left = mid + 1;  // �����Ҳ�߽�
          }
      }
      // ��� right Խ������
      if (right < 0 || nums[right] != target)
          return -1;
      return right;
  }
  ```
- **��Ʊ��������**�� ��״̬������ѡ��
  ```
  for ״̬1 in ״̬1������ȡֵ��
      for ״̬2 in ״̬2������ȡֵ��
          for ...
              dp[״̬1][״̬2][...] = ����(ѡ��1��ѡ��2...)

  dp[i][k][0 or 1]
  0 <= i <= n-1, 1 <= k <= K
  n Ϊ�������� K Ϊ��ཻ����
  �����⹲ n �� K �� 2 ��״̬��ȫ����پ��ܸ㶨��
  for 0 <= i < n:
      for 1 <= k <= K:
          for s in {0, 1}:
              dp[i][k][s] = max(buy, sell, rest)

  ��һ����
  base case��
  dp[-1][k][0] = dp[i][0][0] = 0
  dp[-1][k][1] = dp[i][0][1] = -infinity
  ״̬ת�Ʒ��̣�
  dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
  dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
  ```

## Python�﷨��
------
- `str[::-1]`��ȡ�Ӻ���ǰ���෴����Ԫ��
- `str[len(str)-1::-1]`�� ȡ���±�Ϊ`len(str)-1`��Ԫ�ط�ת��ȡ
- `range(len-1,-1,-1)`������
  `(start,end,step)`����ʼλ�ã�Ĭ��0��������λ�ã�������Ĭ��1��
-  Python�б�ʾ�������`float("inf")`, `float("-inf")`
- `zip()`���ѿɵ���������Ϊ�������������ж�Ӧ��Ԫ�ش����һ����Ԫ�飬������ЩԪ����ɵ��б�
  ```python
  str = ['a', 'b', 'c', 'd', 'e','f']
  print(zip(str[:-1], str[1:]))

  [('a', 'b'), ('b', 'c'), ('c', 'd'), ('d', 'e'), ('e', 'f')]

  nums = ['flower','flow','flight']
  for i in zip(*nums):
      print(i)

  ('f', 'f', 'f')
  ('l', 'l', 'l')
  ('o', 'o', 'i')
  ('w', 'w', 'g')
  ```
- `sorted(iterable, cmp=None, key=None, reverse=False)`
  - iterable -- �ɵ�������
  - cmp -- �Ƚϵĺ���
  - key -- ��Ҫ���������бȽϵ�Ԫ�أ�ֻ��һ������
  - reverse -- reverse = False ����Ĭ�ϣ�
  - `sort()`��Ӧ����`list`�ϵķ�����`sorted()`���Զ����пɵ����Ķ���������������
  - `list`��`sort()`�Ƕ��Ѿ����ڵ��б���в������޷���ֵ�����ڽ�����`sorted()`�������ص���һ���µ�`list`��������ԭ���Ļ����Ͻ��еĲ�����

## C++:
------
- C++11������**nullptr**�ؼ��֣���ͬ��**NULL**����궨�塣��C++��NULLֱ�Ӷ���Ϊ`0`������C�NULL����Ϊ`(void*)0`����ΪC���Կ�����ʽת������C++ȴ����Ҫ��ʾ��д������ת�������Ǵ���һ�����⣬һ��int���ͱ����ں�������ʱ���ض�����ַ�Ԥ�ڵĽ����
  - `func(NULL) --> int`; `func(nullptr) --> char *`��
- `#include<queue>`��
  - push()��pop()��size()��empty()��front()��back()
- `#include <unordered_map>`��
  - unordered_map<int, int> record;
  - record[key] = value;
  - record.find(key) != record.end();
- `string.substr(pos, n)`��posĬ��ֵ0��nĬ��ֵs.size() - pos
  - `s.substr(1))`�� ȡ�Ӵ�������ȥ���ַ������ַ�
- `lower_bound()`��`upper_bound()`�������ö��ֲ��ҵķ�����һ���ź���������н��в��ҡ�
  - `lower_bound(begin, end, num)`���������beginλ�õ�end-1λ�ö��ֲ��ҵ�һ�����ڻ����`num`�����֣��ҵ����ظ����ֵĵ�ַ���������򷵻�`end`��ͨ�����صĵ�ַ��ȥ��ʼ��ַ`begin`���õ��ҵ������������е��±ꡣ
- `map`��`set`�ĵײ�ʵ��Ϊƽ���������`unordered_map`��`unordered_set`�ĵײ�ʵ��Ϊ��ϣ��
- �����C++98��׼��C++11���͵����ı���Ƕ���**long long**����Ϊ���֣�**long long**��**unsigned long long**����`C++11`�У���׼Ҫ��long long���Ϳ����ڲ�ͬƽ̨���в�ͬ�ĳ��ȣ���������`64λ`����long long������ص�һ����3����`LONG_MIN`��`LONG_MAX`��`ULONG_MAX`���ֱ����ƽ̨����С��long longֵ������long long ֵ���Լ����� unsigned long longֵ��

## Leetcode
------
- ̰�ģ�455, 135, 435, 605, 452, **763**, 122, **406**, **665**
- ˫ָ�룺167, 88, 142��**76**�� **633**�� 680�� **524**
- ���ֲ��ң�69, 34, **81**, **154**, **540**, **4**
- �����㷨��**215**, **347**, 451, **75**
- һ�нԿ�������695, **547**, **417**, 46, 77, **78**, **79**, **51**, **934**, **126**, 130, **257**, **47**, **40**, **37**, **310**
- ��̬�滮��70, 198, 413, 64, **542**, 221, 279, 91, 139, 300, 1143, 416, 474, 322, 72, 650, 10, 121, 188, 309, 213, 53, 343, 714
- ���η���**241**, 932, 312
- ��ѧ���⣺204, 504, 172, 415, 326, **384**, **528**, 382, 169, 202
- λ���㣺461, 190, 136, 342, **318**, **338**, 268
- ���ݽṹ��448, 48, 240, 769, 232, 155, 20, 739, 23, **218**, 239, 1, 128, 149, 332, 303, 304, 560, 503, 217
- �ַ�����242, 205, 647, 696, 227, 28, 3
- ����206, **92**, 21, **23**, 24, **160**, 234, 83, 328, 19, 148
- ����104, 110, 543, 437, 101, 1110, 637, 105, 144, 99, 669, 208, 226, 617, 572, 404, 513, 538, 235, 530, 889, 106, 94, 145, **236**, 109, 897, 653, 450
- ͼ��785, 210, 1059, 1135, 882
- �������ݽṹ��684, 146, 1135, 380, 432, 716