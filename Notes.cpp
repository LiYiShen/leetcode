/* Git 分布式版本控制系统
 * $ git --help
 * $ git --version
 * $ git config                    				    查看 git config 的相关命令
 *
 * $ git config --global alias.lg "log --color --graph --pretty=format:'%Cred%h%Creset -%C(yellow)%d%Creset %s %Cgreen(%cr) %C(bold blue)<%an>%Creset' --abbrev-commit"
 * $ gitk   							            图形化查看分支演变
 * $ git config merge.tool vimdiff				    使用 git mergetool
 *
 * $ git config --global user.name "Your Name"		配置所有 Git 仓库的 用户名 和 email, 去掉--global 则配置当前 Git 仓库的 用户名 和 email
 * $ git config --global user.email "email@example.com"
 *
 * $ git config --global user.name    				查看全局配置的 用户名 和 email
 * $ git config --global user.email
 *
 * $ git init              					        把当前目录初始化为 git 仓库, 不想要 git 管理跟踪的文件, 可以在仓库根目录添加 .gitignore 文件, 在里面写对应的规则
 * $ ls -ah                					        查看当前目录下的文件, 包含隐藏文件
 *
 * $ git status
 * $ git add <file>
 * $ git commit -m "description"
 * $ git remote add origin git@github.com:serenity/test.git     关联远程仓库 (先有本地仓库)
 * $ git remote       						        查看远程库信息
 * $ git remote -v    						        查看远程库详细信息
 * $ git remote rm origin  					        删除已关联的远程库 origin
 * $ git push -u origin master    				    第一次推送, 除了第一次推送, 不需要添加 -u 参数
 * $ git push origin master      				    推送本地 master 分支到远程库
 * $ git push origin dev         				    推送本地 dev 分支到远程库
 *
 * $ git reflog
 * $ git reset --hard HEAD^
 * $ git reset --hard <commit_id>
 *
 * 丢弃工作区 (Working Directory) 的修改
 * $ git restore <file>  					        建议使用
 * $ git checkout -- <file>
 *
 * 丢弃暂存区 (stage/index) 的修改
 * $ git restore --staged <file>				    第一步: 把暂存区的修改撤销掉(unstage), 重新放回工作区
 * $ git restore <file>						        第二步: 撤销工作区的修改
 *
 * 一个本地库关联多个远程库, 如同时关联 GitHub 和 Gitee
 * $ git remote add github git@github.com:serenity/test.git
 * $ git remote add gitee git@gitee.com:serenity/test.git
 *
 * $ git branch       						        查看分支列表及当前分支
 * $ git branch -v    						        查看各个分支最后一个提交信息
 * $ git branch -r    						        查看远程分支
 * $ git branch -a    						        查看所有本地和远程分支
 * $ git branch dev   						        创建 dev 分支
 * $ git branch -d dev                           	删除 dev 分支
 * $ git branch -D dev                              强制删除 dev 分支
 * $ git branch --set-upstream-to=origin/dev dev  	指定本地 dev 分支与远程 origin/dev 分支的链接
 *
 * $ git switch dev                              	切换到 dev 分支  (git checkout dev)
 * $ git switch -c dev                           	创建并切换到新的 dev 分支  (git checkout -b dev)
 * $ git switch -c dev origin/dev                	创建远程 origin 的 dev 分支到本地并切换到该分支
 *
 * $ git merge dev                               	合并 dev 分支到当前分支 (当有冲突的时候, 需要先解决冲突)
 * $ git merge --no-ff -m "merge with no-ff" dev 	合并 dev 分支到当前分支(禁用 Fast forward 合并策略)
 *  								                为本次合并要创建一个新的 commit, 所以加上 -m 参数, 把 commit 描述写进去
 *  								                合并分支时，加上 --no-ff 参数就可以用普通模式合并，合并后的历史有分支，能看出来曾经做过合并，而 fast forward 合并就看不出来曾经做过合并
 *
 * $ git diff commitID1 commitID2				    commit 比较
 * $ git diff / git diff -- <文件名>	     		工作区和暂存区比较
 * $ git diff --cached       					    暂存区和 HEAD 比较
 * $ git reset HEAD          					    暂存区恢复成 HEAD
 * $ git checkout -- <文件名>   				     工作区恢复成暂存区文件
 * $ git push origin --delete <分支名>   			 删除远程分支
 * $ git rm <文件名>    					         删除文件
 *
 * $ git log --graph  						        查看分支合并图
 * $ git log --graph --pretty=oneline --abbrev-commit
 * $ git stash  						            保存当前工作区和暂存区的修改状态, 切换到其他分支修复 bug 等工作, 然后在回来继续工作
 * $ git stash list  						        查看保存现场的列表
 * $ git stash pop   						        恢复的同时把 stash 内容也删除
 * $ git stash apply  						        恢复现场, stash 内容并不删除
 * $ git stash drop   						        删除 stash 内容
 * $ git stash apply stash@{0}  				    多次 stash, 恢复的时候, 先用git stash list查看, 然后恢复指定的 stash
 *  								                通常在 dev 分支开发时, 需要有紧急 bug 需要马上处理, 保存现在修改的文件等, 先修复 bug 后再回来继续工作的情况
 * $ git cherry-pick <commit> 					    复制一个特定的提交到当前分支(当前分支的内容需要先 commit, 然后冲突的文件需要解决冲突, 然后 commit)
 * $ git rebase  						            把本地未push的分叉提交历史整理成直线(使得我们在查看历史提交的变化时更容易, 因为分叉的提交需要三方对比)
 *
 * 切换到对应的分支 branch 上, 查看或者操作对应的标签 tag
 * $ git tag  							            查看所有的标签
 * $ git tag <tagname>  					        打标签(默认标签是打在最新提交的commit上) 如: git tag v1.0
 * $ git tag <tagname> <commit_id>  				给对应的 commit_id 打标签
 * $ git tag -a <tagname> -m "标签说明信息" <commit_id> 	   创建带有说明的标签，用-a指定标签名，-m指定说明文字
 * $ git tag -d <tagname> 					        删除一个本地标签
 * $ git push origin :refs/tags/<tagname>			删除一个远程标签
 * $ git show <tagname>  					        查看标签信息
 * $ git push origin <tagname>  				    推送一个本地标签到远程
 * $ git push origin --tags     				    一次性推送全部尚未推送到远程的本地标签
 * 删除远程标签, 需要先删除本地标签, 然后在删除远程标签, 如:删除标签 v0.9
 * $ git tag -d v0.9
 * $ git push origin :refs/tags/v0.9
 *
 * merge 结果能够体现出时间线, rebase 会打乱时间线. rebase 看起来简洁, merge 看起来不太简洁.
 * git pull: git fetch + git merge
 * git pull -r (git pull --rebase): git fetch + git rebase
 */

/* sort(v.begin(), v,end(), compare);
 * bool compare(int a, int b) { return a < b; }  升序排列(默认)
 * #include <functional>
 * 升序: sort(begin, end, less<data-type>())
 * 降序: sort(begin, end, greater<data-type>())
 */

/* #include <numeric>
 * accumulate(v.begin(), v.end(), 0);  累加起始值
 * partial_sum(first, last, dest);  部分和
 */

/* C++ string
 * #include <string>
 * string s(str);						生成字符串为str的复制
 * string s(str, str_begin, str_len);	将字符串str中从下标str_begin开始、长度为str_len的部分作为字符串初值
 * string s(cstr, char_len);			以C_string类型cstr的前char_len个字符串作为字符串s的初值
 * string s(num, char);					生成num个c字符的字符串
 * string s(str, str_index);			将字符串str中从下标str_index开始到字符串结束的位置作为字符串初值
 *
 * size()、 length(): 	返回string对象的字符个数, 执行效果相同
 * max_size(): 			返回string对象最多包含的字符数，超出会抛出length_error异常
 * capacity()：			重新分配内存之前，string对象能包含的最大字符数
 *
 * 插入：push_back()、 insert()
 * s.push_back('a');
 * s.insert(s.begin(), '1');
 *
 * 拼接：append() 、 +
 *
 * 遍历：借助迭代器 或者 下标法
 * 正向迭代器 str.begin()、  str.end()
 * 反向迭代器 str.rbegin()、 str.rend()
 *
 * 删除：erase()
 * iterator erase(iterator p);						删除字符串中p所指的字符
 * iterator erase(iterator first, iterator last);	删除字符串中迭代器区间 [first, last) 上所有字符
 * string& erase(size_t pos, size_t len);			删除字符串中从索引位置 pos 开始的 len 个字符
 * void clear();									删除字符串中所有字符
 *
 * 大小写转换：tolower() 和 toupper() 或者 STL中的 transform 算法
 *
 * 排序
 * sort(iterator iter1, iterator iter2);  对[iter1, iter2)进行排序
 *
 * 分割/截取字符串：substr()
 * string s1("0123456789");
 * string s2 = s1.substr(2, 5);
 * cout << s2 << endl;  结果：23456，参数5表示截取的字符串的长度
 *
 * int转string: c++11标准增加了全局函数 std::to_string
 * string转int: 可以使用std::stoi/stol/stoll等函数
 */

/* C++ 常用数据结构 */
/* array
 * #include <array>
 * array<int, 10> arr;
 * for (auto it = arr.begin(); it != arr.end(); it++)
 * 	cout << *it << '\t';
 * arr.size();
 */

/* queue
 * #include <queue>
 * queue<int> q;
 * q.push(num); q.empty(); q.size(); q.top(); q.back(); q.pop();
 */

/* priority_queue <Type, Container, Functional> : 优先队列具有最高级先出 (first in, largest out)的行为特征
 * Type 数据类型
 * Container 容器类型 (必须是用数组实现的容器, 如vector, deque等，但不能用 list, STL里默认用vector)
 * Functional 比较方式
 * pq.push(); pq.pop(); pq.top(); pq.empty(); pq.size()
 * 默认是大顶堆 priority_queue<int, vector<int>, less<int>> pq;
 * #include <functional> : greater 和 less 是 std 实现的两个仿函数 (类中实现一个operator())
 * 用 pair 做优先队列元素：pair<int, int> 先比较第一个元素, 第一个相等比较第二个.
 * 自定义类型做优先队列元素 :  重写仿函数
 * struct compare {
 *    bool operator()(type a, type b) {
 *        return a.x < b.x;   * 大顶堆
 *    }
 * };
 * priority_queue<type, vector<type>, compare> pq;
 */

/* stack
 * #include <stack>
 * stack<int> st; st.push(num); st.empty(); st.size(); st.top(); st.pop();
 */

/* list 双向链表
 * #include <list>
 * int nums[] = {1, 2, 3, 4, 5};
 * list<int> li(nums, nums + sizeof(nums) / sizeof(int));
 * auto it = li.begin();
 * li.insert(it, num);
 * li.front(); li.back(); li.pop_front(); li.pop_back(); li.push_back(); li.push_front();
 * li.assign(); li.size(); li.resize(); li.unique(); li.erase(); li.clear(); li.empty();
 */

/* #include <map>
 * map 底层为红黑树, 所有元素根据键值key自动排序, 不允许有键值相同的元素
 * multimap 中的key可以重复, 单个元素版本的 insert() 返回值不再是一个pair, 而是一个iterator, 不再提供 operator[] 接口.
 *
 * C++11中4个关联式容器：unordered_map/unordered_set/unordered_multimap/unordered_multiset,
 * unordered_map 底层实现是哈希桶, empty(), insert(), erase(), 其 erase() 操作会缩容，导致元素重新映射，降低性能.
 * 若需要一个有序序列，使用红黑树系列的关联式容器; 若需要更高的查询效率，使用以哈希表为底层的关联式容器.
 *
 * map<char, int> m;
 * m['a'] = 1;
 * m.insert(pair<char, int>('b', 2));  make_pair内敛函数, 返回一个pair对象
 * m.erase('a');
 * auto it = m.find('b');
 * cout << it->first << it->second << endl;
 */

/* unordered_map
 * find() 判断某键值是否存在, map.find(key) == map.end() 时不存在
 * count() 统计key值在map中出现的次数
 */

/* set
 * #include <set>
 * int nums[] = {1, 2, 3, 4, 5};
 * set<int> s(nums, nums + sizeof(nums) / sizeof(int));
 * s.insert(6);
 * s.erase(2);
 * auto it = s.find(3);
 * cout << *it << endl;
 */

/* vector
 * #include <vector>
 * vector<int> vec; push_back(num); pop_back(); back(); empty(); size(); reverse()
 */

/* bitset
 * bitset的大小在编译时就需要确定
 * 定义bitset, bitset<16> b;
 * b.size() 	 返回位数
 * b.count() 	 返回1的个数
 * b.any() 		 返回是否有1
 * b.none() 	 返回是否没有1
 * b.set() 		 全部变成1
 * b.set(i) 	 将i+1位变成1
 * b.set(i,x) 	 将i+1位变成x
 * b.reset() 	 全部都变成0
 * b.flip() 	 全部去翻
 * b.to_string() 转为string类型
 */


/* 动态规划：明确【状态】 --> 定义【dp数组/函数】的含义 --> 明确【选择】 --> 明确【base case】 */
/* 斐波那契数列之记忆化搜索 */
int fib(int N) {
	if (N < 1) return 0;
	vector<int> memo(N + 1, 0);
	return helper(memo, N);
}

int helper(vector<int>& memo, int n) {
	// base case
	if (n == 1 || n == 2) return 1;
	if (memo[n] != 0) return memo[n];
	memo[n] = helper(memo, n - 1) + helper(memo, n - 2);
	return memo[n];
}

/* 斐波那契数列之dp数组迭代解法 */
int fib(int N) {
	vector<int> dp(N + 1, 0);
	// base case
	dp[1] = dp[2] = 1;
	for (int i = 3; i <= N; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	return dp[N];
}

/* 凑零钱问题之带备忘录递归 */
def coinChange(coins: List[int], amount: int):
	memo = dict()
	def dp(n):
		if n in memo: return memo[n]
		if n == 0: return 0
		if n < 0: return -1
		res = float('INF')
		for coin in coins:
			subproblem = dp(n - coin)
			if subproblem == -1: continue
			res = min(res, 1 + subproblem)
		memo[n] = res if res != float('INF') else -1
		return memo[n]
	return dp(amount)

/* 凑零钱问题之dp数组迭代解法 */
int coinChange(vector<int>& coins, int amount) {
	vector<int> dp(amount + 1, amount + 1);
	// base case  dp[i] = x 当目标金额为i时，至少需要x枚硬币
	dp[0] = 0;
	for (int i = 0; i < dp.size(); i++) {
		for (int coin: coins) {
			// 子问题无解，跳过
			if (i - coin < 0) continue;
			dp[i] = min(dp[i], 1 + dp[i - coin]);
		}
	}
	return (dp[amount] == amount + 1) ? -1 : dp[amount];
}

/* DFS 深度优先搜索之最大岛屿面积 */
class Solution {
public:
    vector<int> directions{-1, 0, 1, 0, -1};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, local_area, area = 0, x, y;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    local_area = 1;
                    grid[i][j] = 0;
                    stack<pair<int, int>> island;
                    island.push({i, j});
                    while (!island.empty()) {
                        auto [r, c] = island.top();
                        island.pop();
                        for (int k = 0; k < 4; ++k) {
                            x = r + directions[k], y = c + directions[k+1];
                            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                                grid[x][y] = 0;
                                ++local_area;
                                island.push({x, y});
                            }
                        }
                    }
                    area = max(area, local_area);
                }
            }
        }
        return area;
    }
};
/* 递归 主函数遍历所有搜索位置，判断是否可以开始搜索，辅函数递归进行搜索 */
class Solution {
public:
    vector<int> directions{-1, 0, 1, 0, -1};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int max_area = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    max_area = max(max_area, dfs(grid, i, j));
                }
            }
        }
        return max_area;
    }
    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (grid[r][c] == 0) return 0;
        grid[r][c] = 0;
        int x, y, area = 1;
        for (int i = 0; i < 4; ++i) {
            x = r + directions[i], y = c + directions[i+1];
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size())
                area += dfs(grid, x, y);
        }
        return area;
    }
};

/* 使用 DFS 求解回溯算法 */
result = []
def backtrack(路径, 选择列表):
	if 满足结束条件:
		result.append(路径)
		return
	for 选择 in 选择列表:
		做选择
		backtrack(路径, 选择列表)
		撤销选择

/* 回溯算法之N皇后问题 */
vector<vector<string>> res;
vector<vector<string>> solveNQueens(int n) {
	vector<string> board(n, string(n, '.'));
	backtrack(board, 0);
	return res;
}
void backtrack(vector<string>& board, int row) {
	// 触发结束条件
	if (row == board.size()) {
		res.push_back(board);
		return;
	}
	int n = board[row].size();
	for (int col = 0; col < n; col++) {
		// 排除不合法选择
		if (!isValid(board, row, col))
			continue;
		// 做选择
		board[row][col] = 'Q';
		// 进入下一行决策
		backtrack(board, row + 1);
		// 撤销选择
		board[row][col] = '.';
	}
}
// 是否可以在 board[row][col] 放置皇后
bool isValid(vector<string>& board, int row, int col) {
	int n = board.size();
	// 检查列冲突
	for (int i = 0; i < n; i++) {
		if (board[i][col] == 'Q')
			return false;
	}
	// 检查右上冲突
	for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
		if (board[i][j] == 'Q')
			return false;
	}
	// 检查左上冲突
	for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
		if (board[i][j] == 'Q')
			return false;
	}
	return true;
}

/* BFS算法(计算最短距离) */
int BFS(Node start, Node target) {
	queue<Node> q;		// 核心数据结构
	set<Node> visited;	// 避免回头路
	q.push(start);		// 起点入队
	visited.push(start);
	int step = 0;		// 记录扩散步数
	while (q not empty) {
		int sz = q.size();
		// 将当前队列中的所有节点向四周扩散
		for (int i = 0; i < sz; i++) {
			Node cur = q.pop();
			// 判断是否到达终点
			if (cur is target)
				return step;
			// cur相邻节点入队
			for (Node x : cur.adj())
				if (x not in visited) {
					q.push(x);
					visited.add(x);
				}
		}
		// 搜索完一层，更新步数
		step++;
	}
}

/* BFS算法之二叉树最小深度 */
int minDepth(TreeNode root) {
	if (root == NULL) return 0;
	queue<TreeNode> q = new LinkedList<>();
	q.push(root);
	int depth = 1;
	while (!q.isEmpty()) {
		int sz = q.size();
		for (int i = 0; i < sz; i++) {
			TreeNode cur = q.pop();
			if (cur.left == NULL && cur.right == NULL)
				return depth;
			if (cur.left)
				q.push(cur.left);
			if (cur.right)
				q.push(cur.right);
		}
		depth++;
	}
	return depth;
}

/* 基本二分查找 */
int binarySearch(int[] nums, int target) {
	int left = 0;
	int right = nums.length - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] == target)
			return mid;
		else if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid - 1;
	}
	return -1;
}

/* 寻找左侧边界的二分查找I */
int left_bound(int[] nums, int target) {
	if (nums.length == 0) return -1;
	int left = 0;
	int right = nums.length;
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] == target)
			right = mid;
		else if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid;
	}
	return left;
}

/* 寻找左侧边界的二分查找II */
int left_bound(int[] nums, int target) {
	if (nums.length == 0) return -1;
	int left = 0;
	int right = nums.length - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] == target)
			right = mid - 1;
		else if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid - 1;
	}
	if (left >= nums.length || nums[left] != target)
		return -1;
	return left;
}

/* 寻找右侧边界的二分查找 */
int right_bound(int[] nums, int target) {
	if (nums.length == 0) return -1;
	int left = 0;
	int right = nums.length - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (nums[mid] == target)
			left = mid + 1;
		else if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid - 1;
	}
	// 检查right越界
	if (right < 0 || nums[right] != target)
		return -1;
	return right;
}

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        string res = "";
        bool isNegative = num < 0;
        if (isNegative) num = -num;
        while (num) {
            res = to_string(num % 7;) + res;
            num /= 7;
        }
        return isNegative ? "-" + res : res;
    }
};

// n的阶乘后面有多少个0
class Solution {
public:
    int trailingZeroes(int n) {
        return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);  // 统计质因子5的个数
    }
};

/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

// 406--根据身高重建队列
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> res;
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] > b[0];
        });
        for (int i = 0; i < people.size(); ++i) {
            if (people[i][1] >= res.size()) {
                res.push_back(people[i]);
            }else {
                res.insert(res.begin() + people[i][1], people[i]);
            }
        }
        return res;
    }
};

文件查找
find: 根据文件属性进行查找，如文件名，文件大小，所有者，所属组，是否为空，访问时间，修改时间等。 find . -name '*.txt'
find是实时查找,如果需要更快的查询,可试试locate,locate会为文件系统建立索引数据库,如果有文件更新,需要定期执行更新命令来更新索引库,以获得最新的文件索引信息.
grep: 根据文件内容进行查找，会对文件每一行按照给定模式(patter)进行匹配查找。 grep "text" *

ls | head -n 20
给每项文件前面增加一个id编号: ls | cat -n

top: 用户空间、内核空间CPU利用率，负载因子，内存使用情况，实时显示各进程的资源占用
ps -ef 查看全格式的全部进程

typedef与#define的区别
typedef是编译期行为,有类型检查功能,有自己的作用域
#define是预编译期行为，发生在预处理阶段，只进行简单文本替换，不进行任何检查,没有作用域限制

MySQL数据库优化的八种方式:
1、选取最适用的字段属性 (将表中字段宽度设得尽可能小;尽量把字段设置为NOT NULL,执行查询时,数据库不用去比较NULL值;某些文本字段,如省份/性别,可以定义为ENUM类型,MySQL中ENUM类型被当作数值型数据来处理,其速度比文本类型快得多)
2、使用连接(JOIN)来代替子查询(Sub-Queries) (连接无需在内存中创建临时表来完成逻辑上需要两个步骤的查询工作)
3、使用联合(UNION)来代替手动创建的临时表
4、事务
5、锁定表
6、使用外键
7、使用索引
8、优化的查询语句

linux查看栈上限和设置上限: ulimit -a (查看进程所有资源上限)

同一进程间的线程共享的资源有4个：堆、全局变量、静态变量、文件等公用资源
独享的资源有：栈、寄存器

select和epoll对于用户态和内核态消耗的不同：select基于用户态，epoll红黑树基于内核态

拥塞控制：防止过多数据注入到网络中，使网络中的路由器或链路不致过载。
拥塞控制所要做的有一个前提：网络能够承受现有的网络负荷。
拥塞控制是一个全局性的过程，涉及到所有的主机、路由器，以及与降低网络传输性能有关的所有因素。

流量控制：指点对点通信量的控制，是端到端正的问题。流量控制所要做的就是抑制发送端发送数据的速率，以便使接收端来得及接收。
拥塞控制代价：需要获得网络内部流量分布的信息。在实施拥塞控制之前，还需要在结点之间交换信息和各种命令，以便选择控制的策略和实施控制。
这样就产生了额外的开销。拥塞控制还需要将一些资源分配给各个用户单独使用，使得网络资源不能更好地实现共享。

几种拥塞控制方法：慢开始(slow-start)、拥塞避免(congestion avoidance)、快重传(fast retransmit)和快恢复(fast recovery)

慢启动的阈值是在第二次握手时协商的,“慢”并非指cwnd增长速率慢,而是指在TCP开始发送报文段时先设置cwnd=1,使发送方开始时只发送一个报文段(试探网络拥塞情况),再逐渐增大cwnd
为了防止拥塞窗口cwnd增长过大引起网络拥塞，还需要设置一个慢开始门限ssthresh状态变量。慢开始门限ssthresh的用法如下：
当 cwnd < ssthresh 时，使用上述的慢开始算法。
当 cwnd > ssthresh 时，停止使用慢开始算法而改用拥塞避免算法。
当 cwnd = ssthresh 时，既可使用慢开始算法，也可使用拥塞控制避免算法。

拥塞避免算法：让拥塞窗口cwnd缓慢地增大，即每经过一个往返时间RTT就把发送方的拥塞窗口cwnd加1，而不是加倍。
这样拥塞窗口cwnd按线性规律缓慢增长，比慢开始算法的拥塞窗口增长速率缓慢得多。

无论在慢开始阶段还是在拥塞避免阶段，只要发送方判断网络出现拥塞（没有收到确认），就要把慢开始门限ssthresh设置为出现拥塞时的发送方窗口值的一半（但不能小于2）。
然后把拥塞窗口cwnd重新设置为1，执行慢开始算法。这样做的目的就是要迅速减少主机发送到网络中的分组数，使得发生拥塞的路由器有足够时间把队列中积压的分组处理完毕。

linux中open和fopen的区别:
1.层次不同,open是系统调用,返回文件句柄,即文件在文件描述符表里的索引;fopen是ANSIC标准C语言库函数，返回一个指向文件结构的指针(文件流)
linux中的系统函数是open,fopen是其封装函数,fopen的实现要调用open。
2.fopen和open最主要的区别是是否有缓存
fopen用户态下有缓存,它使用FILE结构保存缓冲数据,在进行read/write时减少了用户态和内核态的切换
open没有缓存,每次读操作都直接从文件系统中获取数据,在进行read和write的时候每次都需要进行内核态和用户态的切换
表现为,如果顺序访问文件,fopen系列的函数要比直接调用open系列快;如果随机访问文件open要比fopen快
3.一般用fopen打开普通文件,用open打开设备文件

TCP/IP：应用层、传输层、网际层、网络接口层（强调这一层是为了解决不同网络的互联问题）
不过从实质上讲，TCP/IP只有最上面三层，因为最下面的网络接口层并没有什么具体内容。
因此在学习计算机网络原理时往往采取折中的办法，即综合OSI和TCP/IP的优点，采取一种只有五层协议的体系结构：物理层、数据链路层、网络层、传输层、应用层

交换机工作在OSI的第2层-数据链路层，路由器工作在OSI的第3层-网络层。

堆与栈的区别有：
1、栈由系统自动分配，而堆是人为申请开辟；
2、栈获得的空间较小，而堆获得的空间较大；
3、栈由系统自动分配，速度较快，而堆一般速度比较慢；
4、栈是连续的空间，而堆是不连续的空间。

中断一般三类：
外中断：由CPU外部引起，如I/O中断、时钟中断；
内中断（异常，陷入）：CPU内部事件或程序执行中引起，例如地址越界、浮点溢出；
在程序中使用系统调用引起。

中断处理：一般分为中断响应、中断处理两个步骤，中断响应由硬件实施，中断处理主要由软件实施。

中断处理程序的处理过程：
1. 测定是否有未响应的中断信号。
2. 保护被中断进程的CPU环境。
3. 转入相应的设备处理程序。
4. 中断处理。
5. 恢复CPU的现场并退出中断。

connect()在第二次握手后返回，accept()过程发生在三次握手之后，三次握手完成后，客户端和服务器就建立了tcp连接并可以进行数据交互了。这时可以调用accept函数获得此连接。

构造函数能不能是虚函数：不能，在调用构造函数时，虚表指针并未在对象内存空间，必须构造函数调用完成后才能形成虚表指针

static可以修饰构造函数？
被static修饰的成员，是随着类的加载而存在，无须创建对象而可以直接被调用，而构造函数是给对象初始化的，它的存在必须依赖于对象而存在。

构造方法是一种特殊的方法:
1.构造方法的名字必须与定义他的类名完全相同，没有返回类型.
2.创建一个对象时用new,作用是初始化.
3.每个类可以有零个或者多个构造方法.(其中参数列表不同).可以被重载.
4.不能被static、final、synchronized、abstract和native修饰。构造方法不能被子类继承。
5.构造方法在创建对象时自动执行,一般不能显式地直接调用.

怎么保证数据一致性: Redis只做缓存，不做更新

单例模式如果有两个线程都创建单例对象怎么做: 使用锁机制; 利用静态变量只能被new一次的特点

malloc、vmalloc、kmalloc的区别：
1、kmalloc、vmalloc分配的是内核内存,malloc分配的是用户内存
2、kmalloc保证分配的内存在物理上是连续的,内存只有在要被DMA访问时才需要物理上连续，malloc和vmalloc保证的是在虚拟地址空间上连续
3、kmalloc能分配的大小有限,vmalloc和malloc能分配的大小相对较大
4、vmalloc比kmalloc要慢。
尽管在某些情况下才需要物理上连续的内存块，但是很多内核代码都用kmalloc来获得内存，而不是vmalloc。
这主要是出于性能的考虑。vmalloc函数为了把物理内存上不连续的页转换为虚拟地址空间上连续的页，必须专门建立页表项。
糟糕的是，通过vmalloc获得的页必须一个个地进行映射，因为它们物理上是不连续的，这就会导致比直接内存映射大得多的TLB抖动。
vmalloc仅在不得已时才会用--典型的就是为了获得大块内存时。

当调用一个对象的非静态成员函数时，系统会把该对象的起始地址赋给成员函数的this指针。
而静态成员函数不属于某一对象（所有对象共有，没有this指针，不能访问本类中非静态成员），它与任何对象都无关。

c++规定const静态类成员可以直接初始化，其他非const的静态类成员需要在类外初始化，且不能使用static关键字。
静态成员变量在类中仅仅是声明，没有定义，所以要在类的外面定义，实际上是给静态成员变量分配内存。

虚基类：被“virtual”继承的类，任何类都可以成为虚基类。
虚基类解决多重多级继承造成的二义性问题。

模板出现不能解决的类型，通过第三代具体化来解决。
template<> 返回值 函数名<具体类型>(参数)
类模板不能自动类型推导，函数模板可以。
类模板做函数参数(显示指定类型、参数模板化、整体模板化)
空参数实参列表限定编译器只能通过模板匹配。
模板二次编译进行检测。
成员函数在运行时才去创建。

无法解析的外部命令 通常链接阶段出错
建议：模板不要分文件编写(.h声明和.cpp实现链接不到一起,类模板的成员函数运行时才创建)，写到一个类中即可，类内声明和实现，最后把后缀改为.hpp 约定俗成

栈解旋：从try开始，到throw抛出异常之前，所有栈上的对象都会被释放，这个过程即栈解旋。

异常的接口声明(抛出特定类型异常)  void func() throw(int, char) {}

string转char *： .c_str()

cin.get()
cin.getline()
cin.ignore()
cin.peek()
cin.putback()
查看标志位：cin.fail()
0正常 1不正常  cin.clear() 重置标志位  cin.sync() 清空缓冲区

从文件中读取元素向向量中添加：
ifstream in("data.txt");
vector<int> a;
for (int i; in >> i) { a.push_back(i); }

设置随机数种子：
#include <ctime>
srand(unsigned int) time(NULL);

容器：存放数据，STL容器是一种class template。
算法：STL算法是一种function template。
迭代器：容器与算法之间的胶合剂，共有五种类型，所有STL容器都附带有自己专属的迭代器，原生指针也是一种迭代器。
仿函数：行为类似函数，可作为算法的某种策略，是一种重载了operator()的class或class template。
适配器：用来修饰容器或仿函数或迭代器接口。
空间配置器：负责空间的配置与管理，是一个实现了动态空间配置、空间管理、空间释放的class template。

仿函数( 重载() )：函数对象调用的时候像函数调用
myCompare mc;
mc();

equal_range():返回两个迭代器  lower_bound()  upper_bound()

谓词：普通函数或者仿函数返回值bool类型

C++中public、protect、private的访问权限控制
访问权限
一个类的public成员变量、成员函数，可以通过类的成员函数、类的实例变量进行访问。
一个类的protected成员变量、成员函数，无法通过类的实例变量进行访问。但是可以通过类的友元函数、友元类进行访问。
一个类的private成员变量、成员函数，无法通过类的实例变量进行访问。但是可以通过类的友元函数、友元类进行访问。

继承权限
public继承
派生类通过public继承，基类的各种权限不变。
派生类的成员函数，可以访问基类的public成员、protected成员，但是无法访问基类的private成员。
派生类的实例变量，可以访问基类的public成员，但是无法访问protected、private成员，仿佛基类的成员之间加到了派生类一般。
可以将public继承看成派生类将基类的public,protected成员囊括到派生类，但是不包括private成员。

protected继承
派生类通过protected继承，基类的public成员在派生类中的权限变成了protected 。protected和private不变。
派生类的成员函数，可以访问基类的public成员、protected成员，但是无法访问基类的private成员。
派生类的实例变量，无法访问基类的任何成员，因为基类的public成员在派生类中变成了protected。
可以将protected继承看成派生类将基类的public,protected成员囊括到派生类，全部作为派生类的protected成员，但是不包括private成员。
private成员是基类内部的隐私，除了友元，所有人员都不得窥探。派生类的友元，都不能访问

private继承
派生类通过private继承，基类的所有成员在派生类中的权限变成了private。
派生类的成员函数，可以访问基类的public成员、protected成员，但是无法访问基类的private成员。
派生类的实例变量，无法访问基类的任何成员，因为基类的所有成员在派生类中变成了private。
可以将private继承看成派生类将基类的public,protected成员囊括到派生类，全部作为派生类的private成员，但是不包括private成员。
private成员是基类内部的隐私，除了友元，所有人员都不得窥探。派生类的友元，都不能访问

总结：继承修饰符，就像是一种筛子，将基类的成员筛到派生类。public、protected、private，就是筛子的眼。
通过public继承，所有基类成员（除了private），public、protected都到了派生类里面，public筛眼比较大，不会改变访问权限。
通过protected继承，所有基类成员（除了private），public、protected都到了派生类里面，protected筛眼大小适中，所有过来的成员都变成了protected。
通过private继承，所有基类成员（除了private），public、protected都到了派生类里面，private筛眼最小，所有过来的成员都变成了private。

extern：置于变量或函数前，标示其定义在别的文件中，提示编译器在其他模块中寻找。也可用来指定链接。
extern “C”：C++调用C函数需要extern C，因为C语言没有函数重载.

static：修饰局部变量时，使得被修饰的变量成为静态变量，存储在静态区。其生命周期与程序相同，在main函数之前初始化，程序退出时销毁。（无论是局部静态还是全局静态）。
此外，static限制了链接属性，被修饰的全局变量只能被包含该定义的文件访问（多文件编译时，隐藏），在C++中还可以实现不同对象之间数据共享。

volatile：“易变的”，因为访问寄存器要比访问内存单元快,所以编译器一般会作减少存取内存的优化，但可能会读脏数据。
当要求使用volatile声明变量值时，系统总是重新从它所在的内存读取数据，即使它前面的指令刚刚从该处读取过数据。
精确地说就是，遇到这个关键字声明的变量，编译器对访问该变量的代码就不再进行优化，从而可以提供对特殊地址的稳定访问；
如果不使用valatile，则编译器将对所声明的语句进行优化。
（简洁的说就是：volatile关键词影响编译器编译的结果，用volatile声明的变量表示该变量随时可能发生变化，与该变量有关的运算，不要进行编译优化，以免出错）

const：防止变量被修改，必须定义时初始化。对于指针又分为顶层和底层，表示指针本身或指向内容的修改。
可通过const_cast进行类型转换。（函数的值传递会创建临时变量，不会改变实参，加不加const无影响，即无法重载进行区分）

C++中四种类型转换是：static_cast, dynamic_cast, const_cast, reinterpret_cast
1、const_cast：用于将const变量转为非const
2、static_cast：用于各种隐式转换，比如非const转const，void*转指针等, static_cast能用于多态向上转化，如果向下转能成功但是不安全，结果未知；
3、dynamic_cast：用于动态类型转换。只能用于含有虚函数的类，用于类层次间的向上和向下转化。只能转指针或引用。向下转化时，如果是非法的对于指针返回NULL，对于引用抛异常。要深入了解内部转换的原理。
向上转换：指的是子类向基类的转换
向下转换：指的是基类向子类的转换
它通过判断在执行到该语句的时候变量的运行时类型和要转换的类型是否相同来判断是否能够进行向下转换。
4、reinterpret_cast：几乎什么都可以转，比如将int转指针，可能会出问题，尽量少用；
5、为什么不使用C的强制转换？
C的强制转换表面上看起来功能强大什么都能转，但是转化不够明确，不能进行错误检查，容易出错。

C/C++ 中指针和引用的区别？
1.指针保存所指对象的地址，有自己的空间，而引用只是所指对象的别名，指针通过解引用间接访问，而引用是直接访问；
2.使用sizeof看一个指针的大小是4，而引用则是被引用对象的大小；
3.指针可以被初始化为NULL，而引用必须被初始化且必须是一个已有对象 的引用；
4.作为参数传递时，指针需要被解引用才可以对对象进行操作，而直接对引 用的修改都会改变引用所指向的对象；
5.可以有const指针，但是没有const引用；
6.指针在使用中可以指向其它对象，但是引用只能是一个对象的引用，不能 被改变；
7.指针可以有多级指针（**p），而引用至于一级；
8.指针和引用使用++运算符的意义不一样；
9.如果返回动态内存分配的对象或者内存，必须使用指针，引用可能引起内存泄露。

一个一维int数组的数组名实际上是一个int* const 类型；
一个二维int数组的数组名实际上是一个int (*const p)[n];
数组名做参数会退化为指针

内存对齐原则
从0位置开始存储；
变量存储的起始位置是该变量大小的整数倍；
结构体总的大小是其最大元素的整数倍，不足的后面要补齐；
结构体中包含结构体，从结构体中最大元素的整数倍开始存；
如果加入pragma pack(n) ，取n和变量自身大小较小的一个。

内联函数有什么优点？内联函数与宏定义的区别？
宏定义在预编译的时候就会进行宏替换；
内联函数在编译阶段，在调用内联函数的地方进行替换，减少了函数的调用过程，但是使得编译文件变大。
因此，内联函数适合简单函数，对于复杂函数，即使定义了内联编译器可能也不会按照内联的方式进行编译。
内联函数相比宏定义更安全，内联函数可以检查参数，而宏定义只是简单的文本替换。因此推荐使用内联函数，而不是宏定义。
使用宏定义函数要特别注意给所有单元都加上括号，#define MUL(a, b) a * b，这很危险，正确写法：#define MUL(a, b) ((a) * (b))

引用的本质就是所引用对象的地址。

C++里面的四个智能指针(防止内存泄漏): auto_ptr, shared_ptr, weak_ptr, unique_ptr 其中后三个是c++11支持，并且第一个已经被11弃用。
unique_ptr 是一种独享被管理对象指针所有权的智能指针。
unique_ptr对象包装一个原始指针，并负责其生命周期。当该对象被销毁时，会在其析构函数中删除关联的原始指针。

野指针就是指向一个已删除的对象或者未申请访问受限内存区域的指针。

为什么析构函数必须是虚函数？为什么C++默认的析构函数不是虚函数？
将可能会被继承的父类的析构函数设置为虚函数，可以保证当我们new一个子类，然后使用基类指针指向该子类对象，释放基类指针时可以释放掉子类的空间，防止内存泄漏。
C++默认的析构函数不是虚函数是因为虚函数需要额外的虚函数表和虚表指针，占用额外的内存。
而对于不会被继承的类来说，其析构函数若是虚函数，会浪费内存。只有需要作父类时才设为虚函数。

为了实现多态进行动态绑定，将派生类对象指针绑定到基类指针上，对象销毁时，如果析构函数没有定义为虚函数，则会调用基类的析构函数，显然只能销毁部分数据。
如果要调用对象的析构函数，就需要将该对象的析构函数定义为虚函数，销毁时通过虚函数表找到对应的析构函数。

virtual ~myClass() = 0;

析构函数与构造函数对应，当对象结束其生命周期，如对象所在函数调用完毕，系统会自动执行析构函数

静态函数和虚函数的区别：静态函数在编译时就已经确定运行时机，虚函数在运行时动态绑定。虚函数因为用了虚函数表机制，调用的时候会增加一次内存开销。

多态：多态的实现主要分为静态多态和动态多态，静态多态主要是模板技术和函数重载，在编译时确定；
动态多态采用虚函数机制，通过继承关系重写基类的虚函数，在运行期间动态绑定。
举个例子：一个父类类型的指针指向一个子类对象时候，使用父类的指针去调用子类中重写了的父类中的虚函数的时候，会调用子类重写过后的函数，
在父类中声明为加了virtual关键字的函数，在子类中重写时候不需要加virtual也是虚函数。

虚函数的作用：用于实现多态，在设计上还具有封装和抽象的作用。

虚函数的实现：在有虚函数的类中，类的最开始部分是一个虚函数表的指针，这个指针指向一个虚函数表，表中放了虚函数的地址，
实际的虚函数在代码段(.text)中。当子类继承了父类的时候也会继承其虚函数表，当子类重写父类中虚函数时候，会将其继承到的虚函数表中的地址替换为重新写的函数地址。
使用了虚函数，会增加访问内存开销，降低效率。

++i 实现：int&  int::operator++ () { *this +=1；return *this；}
i++ 实现：const int  int::operator (int) { int oldValue = *this；++（*this）；return oldValue；}

写个函数在main函数执行前先运行：
__attribute((constructor))void before() { printf("before main\n"); }

__attribute((constructor))是gcc扩展，标记这个函数应当在main函数之前执行。同样__attribute((destructor))，
标记函数应当在程序结束之前（main结束之后，或者调用了exit后）执行。

C++里是怎么定义常量的？常量存放在内存的哪个位置？
常量在C++里的定义就是一个top-level const加上对象类型，常量定义必须初始化。
对于局部对象，常量存放在栈区，对于全局对象，常量存放在全局/静态存储区。对于字面值常量，常量存放在常量存储区。

智能指针shared_ptr的实现：核心要理解引用计数，什么时候销毁底层指针，还有赋值，拷贝构造时候的引用计数的变化，
析构的时候要判断底层指针的引用计数为0了才能真正释放底层指针的内存。

以下四行代码的区别是什么？
const char * arr = "123"; char * brr = "123"; const char crr[] = "123"; char drr[] = "123";

const char * arr = "123";
字符串123保存在常量区，const本来是修饰arr指向的值不能通过arr去修改，但是字符串“123”在常量区，本来就不能改变，所以加不加const效果都一样

char * brr = "123";
字符串123保存在常量区，这个arr指针指向的是同一个位置，同样不能通过brr去修改"123"的值

const char crr[] = "123";
123本来是在栈上的，但是编译器可能会做某些优化，将其放到常量区

char drr[] = "123";
字符串123保存在栈区，可以通过drr去修改

C++函数栈空间的最大值：默认是1M，不过可以调整。

new/delete与malloc/free的区别是什么：new/delete是C++关键字，而malloc/free是C语言库函数，后者使用必须指明申请内存空间的大小，
对于类类型的对象，后者不会调用构造函数和析构函数。new是分配在自由存储区而malloc分配在堆上，自由存储区可以是堆也可以不是，具体要看new内部的实现。

说说你了解的RTTI：
运行时类型检查，在C++层面主要体现在dynamic_cast和typeid,VS中虚函数表的-1位置存放了指向type_info的指针。
对于存在虚函数的类型，typeid和dynamic_cast都会去查询type_info

虚函数表具体是怎样实现运行时多态的?
编译器为每一个类维护一个虚函数表，虚函数表是类对象之间共享的，子类若重写父类虚函数，虚函数表中，该函数的地址会被替换，
对于存在虚函数的类的对象，在VS中，对象的头部存放指向虚函数表的指针，对虚函数指针的地址解引用得到虚函数表的地址。

C语言是怎么进行函数调用的：每一个函数调用都会分配函数栈，在栈内进行函数执行过程。调用前，先把返回地址压栈，然后把当前函数的esp指针压栈。

C语言参数压栈顺序：从右到左

C++如何处理返回值：生成一个临时变量，把它的引用作为函数参数传入函数内。

C++中拷贝赋值函数的形参能否进行值传递？
不能。如果是这种情况下，调用拷贝构造函数的时候，首先要将实参传递给形参，这个传递的时候又要调用拷贝构造函数。。如此循环，无法完成拷贝，栈也会满。

1. 不要在析构函数中抛出异常！虽然C++并不禁止析构函数抛出异常，但这样会导致程序过早结束或出现不明确的行为（abort导致程序非正常退出）。
2. 如果某个操作可能会抛出异常，class应提供一个普通函数（而非析构函数），来执行该操作。目的是给客户一个处理错误的机会。
3. 如果析构函数中异常非抛不可，那就用try catch来将异常吞下，但这样并不好，我们提倡有错早些报出来。

1. 构造函数中抛出异常，会导致析构函数不能被调用，但对象本身已申请到的内存资源会被系统释放（已申请到资源的内部成员变量会被系统依次逆序调用其析构函数）。
2. 因为析构函数不能被调用，所以可能会造成内存泄露或系统资源未被释放。
3. 构造函数中可以抛出异常，但必须保证在构造函数抛出异常之前，把系统资源释放掉，防止内存泄露。（如何保证？使用auto_ptr）

不要在构造函数中调用虚函数：因为父类对象会在子类之前进行构造，此时子类部分的成员还未初始化， 因此调用子类的虚函数是不安全的。
不要在析构函数中调用虚函数：析构函数在销毁一个对象时，先调用子类析构，再调用基类析构，此时派生类对象的数据成员已经“销毁”，再调用子类虚函数没有意义。

智能指针能够帮助我们处理资源泄露、空悬指针、比较隐晦的由异常造成的资源泄露问题。
 1 #include <iostream>
 2 using namespace std;
 3
 4 int main()
 5 {
 6     int *ptr = new(nothrow) int(0);
 7     if(!ptr)
 8     {
 9         cout << "new fails."
10         return 0;
11     }
12     // 假定hasException函数原型是 bool hasException()
13     if (hasException())
14         throw exception();
15
16     delete ptr;
17     ptr = nullptr;
18     return 0;
19 }

1 // 假定hasException函数原型是 bool hasException()
2 if (hasException())
3 {
4         delete ptr;
5         ptr = nullptr;
6         throw exception();
7 }

1. Class shared_ptr实现共享式拥有，多个智能指针可以指向相同对象，该对象和其相关资源会在“最后一个引用被销毁”时释放。为了在结构复杂情境中执行上述工作，标准库提供了weak_ptr、bad_weak_ptr和enable_shared_from_this等辅助类。
2. Class unique_ptr实现独占式拥有，保证同一时间只有一个智能指针可以指向该对象。它对于避免资源泄露（resourece leak）——例如“以new创建对象后因为发生异常而忘记调用delete”——特别有用。

shared_ptr本身提供默认内存释放器（default deleter），调用的是delete，不过只对“由new建立起来的单一对象”起作用。
1 shared_ptr<int> pJutta2(new int[10],
2         // deleter (a lambda function)
3         [](int *p)
4         {
5             delete[] p;
6         }
7     );
或者使用为unique_ptr而提供的辅助函数作为内存释放器，其内调用delete[]：
1 shared_ptr<int> p(new int[10], default_delete<int[]>());

1 #include <memory>
2 using namespace std;
3
4 int main()
5 {
6     unique_ptr<int> ptr(new int(0));
7     return 0;
8 }

基于引用计数的智能指针可以简单实现如下
#include <iostream>
using namespace std;

template<class T>
class SmartPtr {
public:
    SmartPtr(T *p);
    ~SmartPtr();
    SmartPtr(const SmartPtr<T> &orig);                // 浅拷贝
    SmartPtr<T>& operator=(const SmartPtr<T> &rhs);    // 浅拷贝
private:
    T *ptr;
    // 将use_count声明成指针是为了方便对其的递增或递减操作
    int *use_count;
};

template<class T>
SmartPtr<T>::SmartPtr(T *p) : ptr(p) {
    try {
        use_count = new int(1);
    }
    catch (...) {
        delete ptr;
        ptr = nullptr;
        use_count = nullptr;
        cout << "Allocate memory for use_count fails." << endl;
        exit(1);
    }
    cout << "Constructor is called!" << endl;
}

template<class T>
SmartPtr<T>::~SmartPtr() {
    // 只在最后一个对象引用ptr时才释放内存
    if (--(*use_count) == 0) {
        delete ptr;
        delete use_count;
        ptr = nullptr;
        use_count = nullptr;
        cout << "Destructor is called!" << endl;
    }
}

template<class T>
SmartPtr<T>::SmartPtr(const SmartPtr<T> &orig) {
    ptr = orig.ptr;
    use_count = orig.use_count;
    ++(*use_count);
    cout << "Copy constructor is called!" << endl;
}

// 重载等号函数不同于复制构造函数，即等号左边的对象可能已经指向某块内存。
// 这样，我们就得先判断左边对象指向的内存已经被引用的次数。如果次数为1，
// 表明我们可以释放这块内存；反之则不释放，由其他对象来释放。
template<class T>
SmartPtr<T>& SmartPtr<T>::operator=(const SmartPtr<T> &rhs) {
    // 《C++ primer》：“这个赋值操作符在减少左操作数的使用计数之前使rhs的使用计数加1，
    // 从而防止自身赋值”而导致的提早释放内存
    ++(*rhs.use_count);

    // 将左操作数对象的使用计数减1，若该对象的使用计数减至0，则删除该对象
    if (--(*use_count) == 0) {
        delete ptr;
        delete use_count;
        cout << "Left side object is deleted!" << endl;
    }

    ptr = rhs.ptr;
    use_count = rhs.use_count;

    cout << "Assignment operator overloaded is called!" << endl;
    return *this;
}

STL中hash_map扩容发生什么？
1、创建一个新桶，该桶是原桶两倍大最接近的质数(判断n是不是质数的方法：用n除2到sqrt(n)范围内的数)；
2、将原来桶里的数通过指针转换，插入到新桶中(注意STL这里做的很精细，没有直接将数据从旧桶遍历拷贝数据插入到新桶，而是通过指针转换)
3、通过swap函数将新桶和旧桶交换，销毁新桶。

GCC是C/C++语言的编译工具，Make是增量式（编译）批处理工具，CMake是Make脚本生成工具。
开发者需要编写CMakelist.txt文件，来配置项目相关的CMake参数。
通过运行cmake命令，自动生成对应平台的Make工具自动构建脚本Makefile文件。
当然，CMake也支持生成其他的构建工具的配置文件，比如Xcode的xxxx.xcodeproj，Visual Studio的xxxx.sln，Ninja的xxxx.ninja等等。
目前，大多数开源的C/C++项目都支持使用CMake生成Makefile文件，再调用make命令，使用Make工具进行自动构建。
Makefile文件可以看成是一系列依赖于文件的Shell命令。
它基于文件修改的时间戳来实现增量式处理。
具体规则大致如下，若生成的目标文件的时间戳早于依赖文件的时间戳时，则执行对应的命令，重新生成目标文件。
这实际上暗示了，Make工具不只用于编译，还可以用于其他的增量式文件生成任务。
使用Make工具来编译C/C++项目时，一般会使用Shell命令来调用gcc，自动化且增量式地实现C/C++源代码的编译链接等一系列工作。

GCC被重新定义为GNU Compiler Collection，即 GNU编译器套件。

Apple基于LLVM重新开发了编译工具Clang。

n & (~n + 1)提取出整数n最后一位为1的数

STL里的内存池实现
STL内存分配分为一级分配器和二级分配器，一级分配器就是采用malloc分配内存，二级分配器采用内存池。

二级分配器设计的非常巧妙，分别给8k，16k,…, 128k等比较小的内存片都维持一个空闲链表，每个链表的头节点由一个数组来维护。
需要分配内存时从合适大小的链表中取一块下来。假设需要分配一块10K的内存，那么就找到最小的大于等于10k的块，也就是16K，从16K的空闲链表里取出一个用于分配。释放该块内存时，将内存节点归还给链表。
如果要分配的内存大于128K则直接调用一级分配器。
为了节省维持链表的开销，采用了一个union结构体，分配器使用union里的next指针来指向下一个节点，而用户则使用union的空指针来表示该节点的地址。

set和map都是基于红黑树实现的。
红黑树是一种平衡二叉查找树，与AVL树的区别是什么？AVL树是完全平衡的，红黑树基本上是平衡的。
为什么选用红黑数呢？因为红黑数是平衡二叉树，其插入和删除的效率都是N(logN)，与AVL相比红黑数插入和删除最多只需要3次旋转，而AVL树为了维持其完全平衡性，插入和删除的时候在最坏的情况下要旋转logN次。
红黑树的定义：
(1) 节点是红色或者黑色；
(2) 父节点是红色的话，子节点就不能为红色；
(3) 从根节点到每个页子节点路径上黑色节点的数量相同；
(4) 根是黑色的，NULL节点被认为是黑色的。

必须在构造函数初始化式里进行初始化的数据成员有哪些
(1) 常量成员，因为常量只能初始化不能赋值，所以必须放在初始化列表里面
(2) 引用类型，引用必须在定义的时候初始化，并且不能重新赋值，所以也要写在初始化列表里面
(3) 没有默认构造函数的类类型，因为使用初始化列表可以不必调用默认构造函数来初始化，而是直接调用拷贝构造函数初始化

模板特化
(1) 模板特化分为全特化和偏特化，模板特化的目的就是对于某一种变量类型具有不同的实现，因此需要特化版本。例如，在STL里迭代器为了适应原生指针就将原生指针进行特化。

定位内存泄露
(1)在windows平台下通过CRT中的库函数进行检测；
(2)在可能泄漏的调用前后生成块的快照，比较前后的状态，定位泄漏的位置
(3)Linux下通过工具valgrind检测

类之间的关系
（1）继承：is a子类继承父类的方法（鹅和鸟的关系）
（2）组合：has-a整体和部分的关系，整体和部分之间是不可可分离的，它们具有相同的生命周期（鸟和翅膀的关系）
（3）聚合：contains-a：整体和部分的关系，整体和部分之间是可分离的，它们可以具有各自的生命周期，部分可以属于多个整体对象，也可以为多个整体对象共享。如员工和公司之间的关系。
（4）关联：弱关系，双方一般是平等的。如明星和粉丝之间的关系。
（5）实现：实现是类和接口之间的关系。接口通过纯虚函数来实现。
（6）依赖： 简单的理解，依赖就是一个类A使用到了另一个类B，而这种使用关系是具有偶然性的、临时性的、非常弱的，但是类B的变化会影响到类A。
比如某人要过河，需要借用一条船，此时人与船之间的关系就是依赖。表现在代码层面，为类B作为参数被类A在某个method方法中使用。

面对对象的设计原则：
（1）开放封闭原则：
一个软件实体应当对扩展开放，对修改关闭。
（2）里式代换原则
在任何父类出现的地方都可以用他的子类来替代。
（3）依赖倒转原则
要依赖于抽象，不要依赖于具体实现。
（4）单一职责原则
一个类应该仅有一个引起它变化的原因。
（5）接口隔离原则
使用多个专门的接口比使用单个接口要好的多。

unordered_map是如何解决哈希冲突的
（1）一个桶中可以放多个元素，元素的关键字相同；也就是通常的链地址法
（2）unordered_map会维护桶的平均元素数量，会在需要时添加新的桶，以使得load_factor<=max_load_factor

防止继承发生：在类名后跟一个关键字final。
区分前置和后置运算符：后置版本接受一个额外的（不被使用）int类型的形参。
输入输出运算符必须是非成员函数。因为IO运算符通常需要读写类的非公有数据成员，所以IO运算符一般被声明为友元。

topk （前k大）用小根堆，维护堆大小不超过 k 即可。每次压入堆前和堆顶元素比较，如果比堆顶元素还小，直接扔掉，否则压入堆。检查堆大小是否超过 k，如果超过，弹出堆顶。复杂度是 nlogk
避免使用大根堆，因为你得把所有元素压入堆，复杂度是 nlogn，而且还浪费内存。如果是海量元素，那就挂了。

[注意]求前 k 大，用小根堆，求前 k 小，用大根堆。

topk 复杂度不是 klogk，是 nlogk.
建堆，建堆复杂度是 n.
插入，logn，上浮操作。
删除（堆顶），一次 sink 操作，logn.


---------------------------------------------面试题------------------------------------------

MySQL中常用的四种存储引擎： MyISAM存储引擎、innoDB存储引擎、MEMORY存储引擎、ARCHIVE存储引擎。

1、存储引擎是对数据库文件的一种存取机制，如何实现存储数据，如何为存储的数据建立索引以及如何更新，查询数据等技术实现的方法。
2、MySQL中数据用不同的技术存储在文件（或内存）中，每一种技术都使用不同的存储机制，索引技巧，锁定水平等。在MySQL中将这些不同的技术及配套的相关功能称为存储引擎。

1、show engines; // 查看mysql所支持的存储引擎，以及mysql默认的存储引擎。
2、show variables like ‘% storage_engine’; // 查看mysql 默认的存储引擎
3、show create table tablename ; // 查看具体某一个表所使用的存储引擎，这个默认存储引擎被修改了！
4、show table status from database where name=“tablename” //准确查看某个数据库中的某一表所使用的存储引擎

MyISAM存储引擎：
存放位置： MySQL如果使用MyISAM存储引擎，数据库文件类型就包括.frm、.MYD、.MYI，默认存放位置是C:\Documentsand Settings\All Users\Application Data\MySQL\MySQL Server 5.1\data
存放方式： MyISAM 存储引擎不支持事务，不支持行级锁，只支持并发插入的表锁
索引方式： MyISAM使用B+tree索引，但是和Innodb的在具体实现上有些不同。
该引擎基于ISAM数据库引擎，除了提供ISAM里所没有的索引和字段管理等大量功能，MyISAM还使用一种表格锁定的机制来优化多个并发的读写操作，
但是需要经常运行OPTIMIZE TABLE命令，来恢复被更新机制所浪费的空间，否则碎片也会随之增加，最终影响数据访问性能。
MyISAM还有一些有用的扩展，例如用来修复数据库文件的MyISAMChk工具和用来恢复浪费空间的 MyISAMPack工具。

MyISAM强调了快速读取操作，主要用于高负载的select，这可能也是MySQL深受Web开发的主要原因：在Web开发中进行的大量数据操作都是读取操作

MyISAM类型的表支持三种不同的存储结构：静态型、动态型、压缩型。
静态型：指定义的表列的大小是固定（即不含有：xblob、xtext、varchar等长度可变的数据类型），这样MySQL就会自动使用静态MyISAM格式。
使用静态格式的表的性能比较高，因为在维护和访问以预定格式存储数据时需要的开销很低；但这种高性能是以空间为代价换来的，因为在定义的时候是固定的，所以不管列中的值有多大，都会以最大值为准，占据了整个空间。

动态型：如果列（即使只有一列）定义为动态的（xblob, xtext, varchar等数据类型），这时MyISAM就自动使用动态型，虽然动态型的表占用了比静态型表较少的空间，但带来了性能的降低，
因为如果某个字段的内容发生改变则其位置很可能需要移动，这样就会导致碎片的产生，随着数据变化的增多，碎片也随之增加，数据访问性能会随之降低。

因碎片增加而降低数据访问性，有两种解决办法：
a、尽可能使用静态数据类型；
b、经常使用optimize table table_name语句整理表的碎片，恢复由于表数据的更新和删除导致的空间丢失。如果存储引擎不支持optimize table table_name，则可以转储并重新加载数据，

压缩型：如果在数据库中创建在整个生命周期内只读的表，则应该使用MyISAM的压缩型表来减少空间的占用。

优缺点：MyISAM的优势在于占用空间小，处理速度快。缺点是不支持事务的完整性和并发性。

innoDB存储引擎
存储位置：MySQL如果使用InnoDB存储引擎，数据库文件类型就包括.frm、ibdata1、.ibd，存放位置有两个，
.frm文件默认存放位置是C:\Documents and Settings\All Users\ApplicationData\MySQL\MySQL Server 5.1\data，ibdata1、.ibd文件默认存放位置是MySQL安装目录下的data文件夹。

innodb存储引擎的mysql表提供了事务，回滚，系统崩溃修复能力，多版本迸发控制的事务安全。

innodb存储引擎支持事务，以及事务相关联功能，支持mvcc的行级锁，支持外键,使用B+Tree，支持自增长列（auto_increment）

优缺点：InnoDB的优势在于提供了良好的事务处理、崩溃修复能力和并发控制。缺点是读写效率较差，占用的数据空间相对较大。

MEMORY存储引擎
memory存储引擎使用存储在内存中的数据来创建表，所有的数据都存储在内存中。每个基于memory存储引擎的表实际对应一个磁盘文件，该文件的文件名和表名相同，类型为.frm。
该文件只存储表的结构，而其数据文件，都是存储在内存中，这样有利于数据的快速处理，提高表的处理能力。如果mysqld进程发生异常，重启或关闭机器这些数据都会消失。所以表的生命周期很短，一般只使用一次。

memory存储引擎默认使用哈希（HASH）索引，其速度比使用B-+Tree型要快，如果读者希望使用B树型，则在创建的时候可以引用。

ARCHIVE存储引擎
适合存储大量存储归档数据。ARCHIVE提供压缩功能，拥有高效的插入速度，但是不支持索引，所以查询性能较差。

InnoDB：支持事务处理，支持外键，支持崩溃修复能力和并发控制。如果需要对事务的完整性要求比较高（比如银行），要求实现并发控制（比如售票），那选择InnoDB有很大的优势。

MyISAM：插入数据快，空间和内存使用比较低。如果数据表主要用来插入和查询记录，则MyISAM引擎能提供较高的处理效率

MEMORY：所有的数据都在内存中，数据的处理速度快，但是安全性不高。它对表的大小有要求，不能建立太大的表。MySQL中使用该引擎作为临时表，存放查询的中间结果

注意，同一个数据库也可以使用多种存储引擎的表。如果一个表要求比较高的事务处理，可以选择InnoDB。这个数据库中可以将查询要求比较高的表选择MyISAM存储。如果该数据库需要一个用于查询的临时表，可以选择MEMORY存储引擎。

什么情况下数据库索引会失效
1.条件中有or，即使其中有条件带索引也不会使用(这也是为什么尽量少用or的原因)。注意：要想使用or，又想让索引生效，只能将or条件中的每个列都加上索引
2.对于多列索引，不是使用的第一部分，则不会使用索引
3.like查询是以%开头
4.列类型是字符串，那一定要在条件中将数据使用引号引用起来,否则不使用索引
5.mysql估计使用全表扫描要比使用索引快,则不使用索引

mysql 的索引模型：自适应哈希索引、B+树索引、有序数组索引

“读已提交”解决了脏读；“可重复读”不仅解决了脏读，还解决了不可重复读；它们的原理都是通过给数据行加锁（共享读锁和排他写锁）来完成的。

幻读：前后多次读取，数据总量不一致
幻读产生的根本原因是采用的行级锁，所以只针对脏读和重复读有用
幻读的解决方案：表级锁，mysql innodb自带版本控制

MyISAM是非集聚引擎，支持全文索引；不支持事务；它是表级锁；会保存表的具体行数
innoDB是集聚引擎，5.6以后才有全文索引；支持事务；它是行级锁；不会保存表的具体行数

一般：不用事务,count计算多的时候适合myisam引擎，对可靠性要求高就用innodby引擎。

索引分类
1.普通索引index :加速查找
2.唯一索引
主键索引：primary key ：加速查找+约束（不为空且唯一）
唯一索引：unique：加速查找+约束 （唯一）
3.联合索引
-primary key(id,name)：联合主键索引
-unique(id,name)：联合唯一索引
-index(id,name)：联合普通索引
4.全文索引fulltext：用于搜索很长一篇文章的时候，效果最好。
5.空间索引spatial :了解就好，几乎不用
普通索引保存的是主键地址，然后再根据主键去查询，所以要检索两次，主键索引只需要检索一次。

多版本并发控制（MVCC）是一种用来解决读-写冲突的无锁并发控制，也就是为事务分配单向增长的时间戳，为每个修改保存一个版本，版本与事务时间戳关联，读操作只读该事务开始前的数据库的快照。
好处: 并发读写数据库，可做到读操作不用阻塞写操作，写操作也不阻塞读操作，提高数据库并发读写性能; 同时还可以解决脏读，幻读，不可重复读等事务隔离问题，但不能解决更新丢失问题

主从复制可以实现数据备份、故障转移、MySQL集群、高可用、读写分离
实现服务器负载均衡(读写分离)
通过复制实现数据的异地备份(数据备份)
提高数据库系统的可用性(故障转移)

一次HTTP操作称为一个事务：
地址解析；封装HTTP请求数据包；封装成TCP包，建立TCP连接（TCP的三次握手）；客户机发送请求命令；服务器响应；服务器关闭TCP连接。

HTTPS的加密算法
首先介绍两个概念：
对称秘钥:对称密钥加密又叫专用密钥加密，即发送和接收数据的双方必使用相同的密钥对明文进行加密和解密运算。通常有两种模式：流加密和分组加密。
非对称秘钥：非对称加密算法需要两个密钥：公开秘钥（publickey）和私有密钥（privatekey）。
公开密钥与私有密钥是一对，如果用公开密钥对数据进行加密，只有用对应的私有密钥才能解密；
如果用私有密钥对数据进行加密，那么只有用对应的公开密钥才能解密。
因为加密和解密使用的是两个不同的密钥，所以这种算法叫作非对称加密算法。
4.1 HTTPS保证数据安全的机制：
　　在HTTP的概念中介绍了HTTP是非常不安全的，那么在服务器与客户端传递数据的过程中HTTPS是如何保证数据的安全呢？
　　1.客户端向服务器端发起SSL连接请求；（在此过程中依然存在数据被中间方盗取的可能，下面将会说明如何保证此过程的安全）
　　2 服务器把公钥发送给客户端，并且服务器端保存着唯一的私钥；
　　3.客户端用公钥对双方通信的对称秘钥进行加密，并发送给服务器端；
　　4.服务器利用自己唯一的私钥对客户端发来的对称秘钥进行解密，在此过程中，中间方无法对其解密（即使是客户端也无法解密，因为只有服务器端拥有唯一的私钥），
      这样保证了对称秘钥在收发过程中的安全，此时，服务器端和客户端拥有了一套完全相同的对称秘钥。
　　5.进行数据传输，服务器和客户端双方用公有的相同的对称秘钥对数据进行加密解密，可以保证在数据收发过程中的安全，即是第三方获得数据包，也无法对其进行加密，解密和篡改。

4.2 CA（电子商务认证机构）认证作用：
　　在上面提到的 客户端向服务器端发起请求时存在数据被盗取的过程：  假如服务器端经由中间方向客户端发送公钥的时候，中间方没有将公钥发送给客户端，而是伪造了一对公钥，并将伪造的公钥发送给客户端，
    此时客户端用中间方伪造的公钥对自己正确的对称秘钥加密并由中间方发送给服务器端，而中间方将用自己伪造的公钥的私钥对其进行解密，得到正确的对称秘钥，
    并将得到的正确的对称秘钥用服务器端发过来的公钥进行加密发给服务器端，服务器daunt再用正确的私钥进行解密，也得到正确的对称秘钥，此时客户端，服务器端，中间方三者都拥有一套正确的对称秘钥，可以对传送的数据进行加密，解密。
　　为了解决上述问题，一般情况下，服务器端会向CA申请认证书，此证书包含了CA及服务器端的一些信息（可以理解为类似公章），这样，服务器端将证书发给客户端的过程中，中间方是无法伪造的，保证了，发给客户端的公钥是服务器端发送的。

------------------------------------------------------------------------------------------------------------------
腾讯一面 45min
了解云产品、docker、find ./ *.txt、tcp和udp、DNS本身、epoll为啥高并发、进程间通信方式、Redis数据类型、
Python、https安全机制、Webbench压力测试、Mysql数据库的优化方式(除了语句explain分析外还了解哪些)
------------------------------------------------------------------------------------------------------------------
腾讯二面 30min
项目(内容、分工、我负责的部分)
常用Linux命令，Python基本数据结构（()/[]/{}），Pandas定位、筛选元素
服务器里客户端、服务端的流程:
socket()--connect()连接目的方ip/port--send()/recv()--close()
socket()--bind()绑定ip/port--listen()设置监听--accept()--recv()/send()--close()
ubuntu基本：
sudo apt install
sudo dpkg -i packge-name.deb
搜索可用于安装的软件包名称: sudo apt-cache search
ps -ef | wc -l
ps -C httpd | wc -l
------------------------------------------------------------------------------------------------------------------
美团一面 35min
反转数字(考虑溢出,必须在溢出前进行判断)
class Solution {
public:
    int reverse(int x) {
        bool isNeg = false;
        if (x < 0) isNeg = true;
        if (isNeg) x = -x;
        int res = 0;
        while (x) {
            int tmp = x % 10;
            if (x / 10 == 0 && res > (INT_MAX - tmp) / 10) return -1;
            res  = res * 10 + tmp;
            x /= 10;
        }
        return isNeg ? -res : res;
    }
};
计网  TCP/IP体系结构描述,各层的协议  三次握手过程  两次握手的问题
数据库  事务的特点acid  Mysql存储引擎Innodb/MyISAM区别,B+树索引(MyISAM索引比Innodb慢,聚簇索引)
Redis基本数据类型,为什么查询快(针对性的数据结构,map空间)
hash_map原理,处理冲突的方法
------------------------------------------------------------------------------------------------------------------
#include <iomanip>
cout << fixed << setprecision(n) << a;
// setprecision() 控制输出流的输出精度（精度控制采用四舍五入）
// 注意：setprecision单独使用是控制有效位数，与fixed合用才是控制小数点后位数
#include <stdio.h>
#include <math.h>
int main() {
    double n, m;
    while (scanf("%lf%lf", &n, &m) != EOF) {
        double res = 0;
        while (m--) {
            res += n;
            n = sqrt(n);
        }
        printf("%.2f\n", res);
    }
    return 0;
}

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
    double n, m;
    while (cin >> n >> m) {
        double res = 0;
        while (m--) {
            res += n;
            n = sqrt(n);
        }
        cout << fixed << setprecision(2) << res << endl;
    }
    return 0;
}

#include <stdio.h>
#include <math.h>
int main() {
    int m,n;
    while (scanf("%d%d", &m, &n) != EOF) {
        int count = 0;
        while (m++ <= n) {
            int g = m % 10;
            int s = (m - g) / 10 % 10;
            int b = (m - g - s * 10) / 100 % 10;
            if (pow(g, 3) + pow(s, 3) + pow(b, 3) == m) {
                if (count == 0) {
                    printf("%d",m);
                    count = 1;
                    continue;
                }
                count = 1;
                printf(" %d", m);
            }
        }
        if (count == 0) printf("no\n");
        else printf("\n");
    }
    return 0;
}

#include <iostream>
#include <cmath>
using namespace std;
int main() {
    int m,n;
    while (cin >> m >> n) {
        int count = 0;
        while (m++ <= n) {
            int g = m % 10;
            int s = (m / 10) % 10;
            int b = m / 100;
            if (pow(g, 3) + pow(s, 3) + pow(b, 3) == m) {
                if (count == 0) {
                    cout << m;
                    count = 1;
                    continue;
                }
                count = 1;
                cout << " " << m;
            }
        }
        if (count == 0) cout << "no" << endl;
        else cout << endl;
    }
    return 0;
}


ET（边沿触发）和LT（电平触发）是epoll对文件描述符的两种操作。
LT工作模式：当文件描述符上的事件就绪后，如果事务没有处理完成或者没有处理，那么下一次epoll会提醒应用程序。
ET工作模式：当文件描述符上的事件就绪后，如果事务没有处理完成或者没有处理，那么下一次epoll则不会提醒应用程序，这就要求应用程序收到一次提醒后，必须将当下的数据处理完成。

先有ET，才有LT。在功能层面，一次处理完数据，LT完全可以做。但不代表LT可以替代ET，LT的通知机制比ET复杂，难免在设计层面会带走部分性能，
在某些情况下ET的性能按理要高一些(据场景而定)，但使用ET有编程较为复杂的缺陷，有利有弊。大部分的网络库或网络服务器都使用LT，比如muduo，但也有使用ET的，像nginx

io复用是同步的，所以每个就绪事件的处理时间要合理!
LT可以触发多次，所以数据量多的时候可以分多次处理。
ET只触发一次，减少了多次事件触发带来的消耗，所以在触发后尽量把数据一次性处理完才有意义，所以ET适合每次处理的数据量较少的场景。

netstat：显示网络状态，如网络连接、路由表、接口状态等等
linux中查看某个端口是哪个进程在运行: netstat -anp | grep 3306 (结束该进程kill -9 3005)
查看占内存最多的进程: top 然后按下P
free：显示内存状态，包括实体内存，虚拟的交换文件内存，共享内存区段，以及系统核心使用的缓冲区等。
以总和形式查询内存使用信息：free -t
tcpdump：用于倾倒网络传输数据，列出经过指定网络界面的数据包文件头
ps主要看进程，关注点在于查看需要查看的进程
top主要看cpu、内存使用情况，及占用资源最多的进程由高到低排序，关注点在于资源占用情况，监视系统性能

tail -f /var/log/messages  参数-f使tail不停地去读最新的内容，这样有实时监视的效果 用Ctrl＋c来终止

查看文件的第5行到第10行: sed -n '5,10p' /etc/passwd

自旋锁：指当一个线程在获取锁时，如果锁已经被其它线程获取，那么该线程将循环等待，不断的判断锁是否能够被成功获取，直到获取到锁才会退出循环。
自旋锁不会使线程状态发生切换，一直处于用户态，即线程一直都是active的，不会使线程进入阻塞状态，减少了不必要的上下文切换，执行速度快；
非自旋锁在获取不到锁的时候会进入阻塞状态，从而进入内核态，当获取到锁的时候从内核态恢复，需要线程上下文切换。

MSL（Maximum Segment Lifetime）：报文最大生存时间，指任何报文在网络上存在的最长时间，超过这个时间报文将被丢弃。
通信要解决的首要问题：保持通信双方信息对称，使双方处于同步状态。

稳定的排序算法就是对于任何的排序数据，排序之后相同大小的数值的的顺序没有发生变化。
比如：2 4 4 1 6 3 排序之后第二个4的位置依然在一个4之后，没有发生位置变化，称之为稳定；否则称之为不稳定的排序。
快排在中间是要直接交换前端和后端的值，所以为不稳定排序。

STL的sort算法，数据量大时采用QuickSort快排算法，分段归并排序。
一旦分段后的数据量小于某个门槛(16)，为避免快排递归调用带来过大的额外负荷，就改用InsertionSort插入排序。
如果递归层次过深，还会改用HeapSort堆排序。

TCP可靠连接怎么体现？接收端没收到报文时发送端如何重传？TCP建立连接的过程？
1.三次握手建立连接通道;
2.传输过程中有确认机制和重传机制，配合流量控制和拥塞控制，使传输效率更高效可靠;
3.断开连接时四次挥手。

流量控制
接收端处理数据的速度是有限的，如果发送方发送数据的速度过快，导致接收端的缓冲区满，而发送方继续发送，就会造成丢包，继而引起丢包重传等一系列连锁反应。
因此TCP支持根据接收端的处理能力，来决定发送端的发送速度，这个机制叫做流量控制。在TCP报文段首部中有一个16位窗口长度，当接收端接收到发送方的数据后，
在应答报文ACK中就将自身缓冲区的剩余大小，放入16窗口大小中。这个大小随数据传输情况而变，窗口越大，网络吞吐量越高，
而一旦接收方发现自身的缓冲区快满了，就将窗口设置为更小的值通知发送方。
如果缓冲区满，就将窗口置为0，发送方收到后就不再发送数据，但是需要定期发送一个窗口探测数据段，使接收端把窗口大小告诉发送端。

socket编程判断对端断开：
1.当recv()返回值小于等于0时，socket连接断开。但是还需要判断 errno是否等于 EINTR,
如果errno == EINTR 则说明recv函数是由于程序接收到信号后返回的，socket连接还是正常的，不应close掉socket连接。

2.
struct tcp_info info;
int len=sizeof(info);
getsockopt(sock, IPPROTO_TCP, TCP_INFO, &info, (socklen_t *)&len);
if ((info.tcpi_state == TCP_ESTABLISHED)) 则说明未断开 else 断开

3.若使用了select等系统函数，若远端断开，则select返回1，recv返回0则断开。其他注意事项同法一

4.
int keepAlive = 1; // 开启keepalive属性
int keepIdle = 60; // 如该连接在60秒内没有任何数据往来,则进行探测
int keepInterval = 5; // 探测时发包的时间间隔为5 秒
int keepCount = 3; // 探测尝试的次数.如果第1次探测包就收到响应了,则后2次的不再发.
setsockopt(rs, SOL_SOCKET, SO_KEEPALIVE, (void *)&keepAlive, sizeof(keepAlive));
setsockopt(rs, SOL_TCP, TCP_KEEPIDLE, (void*)&keepIdle, sizeof(keepIdle));
setsockopt(rs, SOL_TCP, TCP_KEEPINTVL, (void *)&keepInterval, sizeof(keepInterval));
setsockopt(rs, SOL_TCP, TCP_KEEPCNT, (void *)&keepCount, sizeof(keepCount));
设置后，若断开，则在使用该socket读写时立即失败，并返回ETIMEDOUT错误

5.实现一个心跳检测，一定时间内未收到自定义的心跳包则标记为已断开。

当前任务在执行完 CPU 时间片切换到另一个任务之前会先保存自己的状态，以便下次再切换回这个任务时，可以再加载这个任务的状态。
任务从保存到再加载的过程就是一次上下文切换。上下文切换通常是计算密集型的。

所谓的端口也就是指传输层服务访问点TSAP，即传输层地址。应用层不同进程的报文通过不同的端口向下递交到传输层，由传输层复用到一条传输连接上后递交给网络层。
当这些报文到达目的主机后，目的主机的传输层使能分离功能，通过不同的端口将报文分别向上提交给相应的应用进程处理。

行锁确实部分解决了不可重复读的问题,但是行锁跟版本号没关系.
a. 不可重复读分为2部分: 1.快照度 2.当前读
b. 行锁+间隙锁 解决了当前读可能会导致的不可重复读的问题
c. mvcc(多版本控制,可以理解为版本号) 解决了快照读可能会导致的不可重复读的问题
d.补充,mysql的锁和mvcc的设计不单单解决了不可重复读的问题,也解决了幻读的问题

TCP的滑动接收窗口大小实际上就是socket的剩余接收缓冲区大小的字节数。

TCP粘包和拆包问题：
操作系统在发送TCP数据的时候，底层会有一个缓冲区，如果一次请求发送的数据量比较小，没达到缓冲区大小，
TCP会将多个请求合并进行发送，即粘包；如果一次请求发送的数据量比较大，超过了缓冲区大小，TCP会将其拆分为多次发送，即拆包。
解决方案：
1.客户端在发送数据包时，每个包都固定长度，如果发送数据长度不足，则通过补充空格的方式补全到指定长度；
2.客户端在每个包的末尾使用固定分隔符，如\r\n，如果一个包被拆分了，则等待下一个包发送过来之后找到其中的\r\n；
3.将消息分为头部和消息体，在头部中保存当前整个消息的长度，只有在读取到足够长度的消息之后才算是读到了一个完整的消息；
4.通过自定义协议进行粘包和拆包的处理。

Redis的高并发和快速原因
1.redis是基于内存的，内存的读写速度非常快；
2.redis是单线程的，省去了很多上下文切换线程的时间；
3.redis使用多路复用技术，可以处理并发的连接。非阻塞IO内部实现采用epoll，采用了epoll+自己实现的简单的事件框架。
epoll中的读、写、关闭、连接都转化成了事件，然后利用epoll的多路复用特性，绝不在io上浪费一点时间。

为什么Redis是单线程的
官方答案：因为Redis是基于内存的操作，CPU不是Redis的瓶颈，瓶颈最有可能是机器内存的大小或者网络带宽(IO)。

进程调度算法：先来先服务FCFS、轮转法、最短进程、最短剩余时间、优先权调度算法、多级反馈队列调度算法
页面调度算法：先入先出FIFO、最佳页面置换OPT、最近最少使用LRU、最近未使用CLOCK(NRU，判断读R写M标志位的状态)

实际业务中如果真有并发读写 map 的场景，除了加锁的方法，有其他方式去保证线程安全么？
关于并发，四个选择（1最易读，4性能最好。得根据业务trade-off）：
1、不共享（shuffle，hash，chan分派）；
2、加锁，或者用sync.map；
3、优化锁的粒度（如槽锁）；
4、lock-free（用原子操作来代替互斥锁）。

CAS(compare and swap) 是一种用于在多线程环境下实现同步功能的机制。CAS 操作包含三个操作数: 内存值、旧的预期值、要修改的新值。
CAS 的实现逻辑是将内存位置处的数值与预期数值相比较，若相等，则将内存位置处的值替换为新值。若不等，则不做任何操作。
(即CPU去更新一个值，但如果想改的值不再是原来的值，操作就失败。)
CAS 由三个步骤组成，分别是“读取->比较->写回”，存在 ABA 问题，通常的处理措施是对每一次 CAS 操作设置版本号。
CAS 是CPU指令级操作，只有一步原子操作，所以非常快。

值 (value) 和 变量 (variable) 是两个独立的概念：
值 只有 类别(category) 的划分，变量 只有 类型(type) 的划分
值 不一定拥有 身份(identity)，也不一定拥有 变量名（例如 表达式中间结果 i + j + k）

值类别 (value category) 可以分为两种：
左值(lvalue, left value) 是 能被取地址、不能被移动 的值
右值(rvalue, right value) 是 表达式中间结果/函数返回值（可能拥有变量名，也可能没有）
c++中，一个值要么是右值，要么是左值。左值是指表达式结束后依然存在的持久化对象，右值是指表达式结束时就不再存在的临时对象。

引用类型 可以分为两种：
左值引用(l-ref, lvalue reference) 用 & 符号引用 左值（但不能引用右值）
右值引用(r-ref, rvalue reference) 用 && 符号引用 右值（也可以引用左值）

为了充分利用右值的资源，减少不必要的拷贝，C++11引入了右值引用(&&)，移动构造函数，移动复制运算符以及std::move()

右值引用，用以引用一个右值，可以延长右值的生命期，比如：
int&& i = 123;
int&& j = std::move(i);
int&& k = i;  //编译不过，这里i是一个左值，右值引用只能引用右值

std::move(t) 表明对象 t 是可以moved from的, 它允许高效的从 t 资源转换到 lvalue 上.
被移动的对象进入一个合法但未指定状态(valid but unspecified state),调用该对象的方法（包括析构函数）不会出现异常，甚至在重新赋值后可以继续使用.

template <class T> struct atomic;
C++11标准从不同的视角看待问题(多线程下访问共享资源/数据)：需要同步的总是资源/数据，而不是代码。因此C++11对数据进行了更为良好的抽象，引入"原子数据类型"/atomic类型，以达到对开发者掩盖互斥锁、临界区的目的。
C++11对常见的原子操作进行了抽象，定义出统一的接口，并根据编译选项/环境产生平台相关的实现。新标准将原子操作定义为atomic模板类的成员函数，囊括了绝大多数典型的操作——读、写、比较、交换等。

通常情况下，内存模型是一个硬件上的概念，表示机器指令（或者将其视为汇编指令）是以什么样的顺序被处理器执行的。现代的处理器并不是逐条处理机器指令的(强顺序的(strong ordered)/弱顺序的(weak ordered))。
弱顺序的内存模型: 可以进一步挖掘指令中的并行性，提高指令执行的性能。

你一会想顺序执行，一会又想“乱序”执行，更有甚者，还想对“乱”的程度分等级……如何提供这种灵活性呢？
在C++11标准中，设计者给出的解决方式是让程序员为原子操作指定所谓的内存顺序：memory_order。
实际上，atomic类型的其他原子操作接口都有memory_order这个参数，而且默认值都是std::memory_order_seq_cst。

顺序一致内存顺序/memory_order_seq_cst：全部存取都按照顺序执行(不要重排序指令，不要整什么指令乱序执行，就按照代码的先后顺序执行机器指令)。
松散内存顺序/memory_order_relaxed：不对执行顺序做任何保证。

《深入理解C++11 - C++11新特性解析与应用》
原子操作彻底宣告C++11来到了多线程和并行编程的时代。相对于偏于底层的pthread库，C++通过定义原子类型的方式，轻松地化解了互斥访问共享数据的难题。
不过C++也延续了其易于学习难于精通的特性，虽然atomic/原子类型使用上较为简单，但其函数接口(原子操作)却可以有不用的内存顺序。
C++11从各种不同的平台上抽象出了一个软件的内存模型，并以内存顺序进行描述，以使得想进一步挖掘并行系统性能的程序员有足够简单的手段来完成以往只能通过内联汇编来完成的工作。

C++11中这些内存顺序相关的设计，主要还是为了从各种繁杂不同的平台上抽象出独立于硬件平台的并行操作。
对于我们日常的开发工作，默认的顺序一致内存顺序memory_order_seq_cst足可以应付了，
但是开发者想让多线程程序获得更好的性能的话，尤其是在一些弱内存顺序的平台上，比如PowerPC，建立原子操作间的内存顺序还是很有必要的，
因为着能带来极大的性能提升，这也是一些弱一致性内存模型平台的优势。

但对于并行编程来说，可能最根本的，还是思考如何将大量计算的问题，按需分解成多个独立的、能够同时运行的部分，并找出真正需要在线程间共享的数据，实现为C++11的原子类型。
虽然有了原子类型的良好设计，实现这些都可以非常的便捷，但并不是所有的问题或者计算都适合用并行计算来解决，对于不适用的问题，强行用并行计算来解决会收效甚微，甚至起到相反效果。
因此在决定使用并行计算解决问题之前，程序员必须要有清晰的设计规划。而在实现了代码并行后，进一步使用一些性能调试工具来提高并行程序的性能也是非常必要的。

查看进程下所有线程的当前调用栈：
第一种：pstack 进程ID
第二种，使用gdb 然后attach 进程ID，然后再使用命令 thread apply all bt

gstack 打印正在运行的进程的堆栈跟踪

产生死锁的四个必要条件：
互斥条件：一个资源每次只能被一个进程使用。
请求与保持条件：一个进程因请求资源而阻塞时，对已获得的资源保持不放。
不剥夺条件:进程已获得的资源，在末使用完之前，不能强行剥夺。
循环等待条件:若干进程之间形成一种头尾相接的循环等待资源关系。

事务就是并发控制的基本单位

想要保证事务的原子性，就需要在异常发生时，对已经执行的操作进行回滚。
在 MySQL 中，恢复机制是通过回滚日志（undo log）实现的，所有事务进行的修改都会先记录到这个回滚日志中，然后在对数据库中的对应行进行写入。
回滚日志除了能够在发生错误或者用户执行 ROLLBACK 时提供回滚相关的信息，它还能够在整个系统发生崩溃、数据库进程直接被杀死后，
当用户再次启动数据库进程时，还能够立刻通过查询回滚日志将之前未完成的事务进行回滚，这也就需要回滚日志必须先于数据持久化到磁盘上

与原子性一样，事务的持久性也是通过日志来实现的，MySQL 使用重做日志（redo log）实现事务的持久性，
重做日志由两部分组成，一是内存中的重做日志缓冲区，因为重做日志缓冲区在内存中，所以它是易失的，另一个就是在磁盘上的重做日志文件，它是持久的。
当我们在一个事务中尝试对数据进行修改时，它会先将数据从磁盘读入内存，并更新内存中缓存的数据，然后生成一条重做日志并写入重做日志缓存，
当事务真正提交时，MySQL 会将重做日志缓存中的内容刷新到重做日志文件，再将内存中的数据更新到磁盘上

保证两点：
发生错误或者需要回滚的事务能够成功回滚（原子性）；
在事务提交后，数据没来得及写会磁盘就宕机时，在下次重新启动后能够成功恢复数据（持久性）；

数据库对于隔离级别的实现就是使用并发控制机制对在同一时间执行的事务进行控制，限制不同的事务对于同一资源的访问和更新，而最重要也最常见的并发控制机制，在这里我们将简单介绍三种最重要的并发控制器机制的工作原理。
锁： MySQL 和常见数据库中的锁都分为两种，共享锁（Shared）和互斥锁（Exclusive），前者也叫读锁，后者叫写锁。
时间戳：读时间戳中包括了所有访问该记录的事务中的最大时间戳，而记录行的写时间戳中保存了将记录改到当前值的事务的时间戳。
多版本和快照隔离：通过维护多个版本的数据，数据库可以允许事务在数据被其他事务更新时对旧版本的数据进行读取，很多数据库都对这一机制进行了实现；
因为所有的读操作不再需要等待写锁的释放，所以能够显著地提升读的性能，MySQL 和 PostgreSQL 都对这一机制进行自己的实现，也就是 MVCC，虽然各自实现的方式有所不同，
MySQL 就通过文章中提到的回滚日志实现了 MVCC，保证事务并行执行时能够不等待互斥锁的释放直接获取数据。

CAP 定理中的数据一致性，其实是说分布式系统中的各个节点中对于同一数据的拷贝有着相同的值；
而 ACID 中的一致性是指数据库的规则，如果 schema 中规定了一个值必须是唯一的，
那么一致的系统必须确保在所有的操作中，该值都是唯一的，由此来看 CAP 和 ACID 对于一致性的定义有着根本性的区别。

堆和栈的区别：
申请方式不同：栈是系统自动分配，堆是程序员申请。
系统响应不同：
　　栈：只要栈的剩余空间大于所申请的空间，系统就会为程序提供内存，否则栈溢出。　
　　堆：系统收到申请空间的请求后，会遍历一个操作系统用于记录内存空闲地址的链表，当找到一个空间大于所申请空间的堆结点后，
        就会为该结点从记录内存空闲地址的链表中删除，并将该结点的内存分配给程序，然后在这块内存区域的首地址处记录分配的大小，
        这样我们在使用delete来释放内存的时候，delete才能正确地识别并删除该内存区域的所有变量。
        另外，我们申请的内存空间与堆结点的内存空间不一定相等，这是系统会自动将堆结点上多出来的那部分内存空间回收到空闲链表中。
空间大小不同：栈是一块连续的区域，大小一般是1~2M；堆是不连续的区域，空间很大，上限取决于有效的虚拟内存。
碎片问题：栈是后进先出的队列，内存是连续的，而堆则在多次的new和delete后会产生很多碎片。
生长方向：栈是向下，堆是向上。
分配方式：堆是动态分配，没有静态分配。栈是静态分配和动态分配，静态分配由编译器完成，例如局部变量的内存分配；动态分配则由alloca函数分配，不同于堆的手工释放，它的分配是完全由编译器自动释放。
分配效率：栈是系统的底层数据结构，由专门的寄存器存放栈的地址，专门指令执行压栈出栈，这就决定了栈的效率比较高。而堆是C++函数库提供的，机制复杂，效率低。

内存映射段(mmap)的作用是：内核将硬盘文件的内容直接映射到内存，任何应用程序都可通过 Linux 的 mmap() 系统调用请求这种映射。
内存映射是一种方便高效的文件 I/O 方式， 因而被用于装载动态共享库。
用户也可创建匿名内存映射，该映射没有对应的文件，可用于存放程序数据。
在 Linux 中，若通过 malloc() 请求一大块内存，C 运行库将创建一个匿名内存映射，而不使用堆内存。“大块”意味着比阈值MMAP_THRESHOLD还大，缺省为 128KB，可通过 mallopt() 调整。
mmap 映射区向下扩展，堆向上扩展，两者相对扩展，直到耗尽虚拟地址空间中的剩余区域。

在 TCP 三次握手的时候，Linux 内核会维护两个队列，分别是：
半连接队列，也称 SYN 队列；
全连接队列，也称 accepet 队列；
服务端收到客户端发起的 SYN 请求后，内核会把该连接存储到半连接队列，并向客户端响应 SYN+ACK，接着客户端会返回 ACK，
服务端收到第三次握手的 ACK 后，内核会把连接从半连接队列移除，然后创建新的完全的连接，并将其添加到 accept 队列，等待进程调用 accept 函数时把连接取出来。

TCP顺序传输
1. 主机每次发送数据时，TCP就给每个数据包分配一个序列号，并且在一个特定的时间内等待接收主机对分配的这个序列号进行确认
2. 如果发送主机在一个特定时间内没有收到接收主机的确认，则发送主机会重传此数据包
3. 接收主机利用序列号对接收的数据进行确认，以便检测对方发送的数据是否有丢失或者乱序等
4. 接收主机一旦收到已经顺序化的数据，它就将这些数据按正确的顺序重组成数据流并传递到高层进行处理。

UDP 可以在应用层来实现可靠传输，比如设计数据校验、确认和重传等功能。

HTTP 的 keep-alive 是长连接，TCP 的 keep-alive 是保活机制，用来探测对端 TCP 是否还存活。

Linux查看某个服务是否启动的三种方法
方法一：查看redis服务进程情况
ps -ef | grep redis
方法二：查看6379（为redis的端口号）端口号是否被占用
lsof -i : 6379
方法三：显示tcp的端口和进程等相关情况
netstat -tnlp

在现在的网络中，IP地址分为公网IP和私有IP地址。公网IP是在Internet使用的IP地址，而私有IP地址是在局域网中使用的IP地址。
由于IPV4协议的限制，现在IP地址的数量是有限的。这样就不能为居于网中的每一台计算机分配一个公网IP。所以局域网中的每台计算机就只能使用私有IP地址。
私有IP地址是一段保留的IP地址。只是使用在局域网中，在Internet上是不使用的。
私有IP地址的范围有：
    10.0.0.0-10.255.255.255
    172.16.0.0—172.31.255.255
    192.168.0.0-192.168.255.255

静态成员 -- 解决数据共享问题 -- 本源文件中可见 -- 全局数据区 -- 本类所有对象共享，在没产生类对象时其作用域就可见，类内声明，类外初始化
静态成员变量必须初始化，而且只能在类外进行。否则，编译能通过，链接不能通过。

三次握手能不能两次
目的：防止已失效的连接请求报文段突然又传送到了服务端, 因而产生错误(网络中存在延迟的重复分组)
本质：信道不可靠, 但是通信双发需要就某个问题达成一致(三次确保双方都知道对方能正确收发数据). 要解决这个问题, 无论你在消息中包含什么信息, 三次通信是理论上的最小值.

四次挥手：因为TCP是全双工通信的
第一次挥手：当主动方发送断开连接的请求（即FIN报文）给被动方时，仅仅代表主动方不会再发送数据报文了，但主动方仍可以接收数据报文。
第二次挥手：被动方此时有可能还有相应的数据报文需要发送，因此需要先发送ACK报文，告知主动方“我知道你想断开连接的请求了”。这样主动方便不会因为没有收到应答而继续发送断开连接的请求（即FIN报文）。
第三次挥手：被动方在处理完数据报文后，便发送给主动方FIN报文；这样可以保证数据通信正常可靠地完成。发送完FIN报文后，被动方进入LAST_ACK阶段（超时等待）。
第四次挥手：如果主动方及时发送ACK报文进行连接中断的确认，这时被动方就直接释放连接，进入可用状态。

同步/异步关注的是消息通信机制（synchronous communication/asynchronous communication）
所谓同步，就是在发出一个调用时，在没有得到结果之前，该调用就不返回，即由调用者主动等待调用的结果。
而异步则是相反，调用在发出之后，这个调用就直接返回了，所以就没有返回结果。被调用者通过“状态”(定期检查，效率低)、“通知”、“回调”三种途径通知调用者。

阻塞/非阻塞关注的是程序在等待调用结果时的状态。
阻塞调用是指调用结果返回之前，当前线程会被挂起。调用线程只有在得到结果之后才会返回。
非阻塞调用指在不能立刻得到结果之前，该调用不会阻塞当前线程。

time_wait 状态的影响：TCP 连接中，「主动发起关闭连接」的一端，会进入 time_wait 状态，默认会持续 2 MSL（报文的最大生存时间），TCP 连接占用的端口，无法被再次使用。
大量 time_wait 状态存在，会导致新建 TCP 连接会出错，address already in use : connect异常
解决办法：服务器端允许 time_wait 状态的 socket 被重用 / 缩减 time_wait 时间

查询 TCP 连接状态
netstat -nat | grep TIME_WAIT
查询 TCP 连接状态，其中 -E 表示 grep 或的匹配逻辑
netstat -nat | grep -E "TIME_WAIT|Local Address"
统计各种连接的数量
netstat -n | awk '/^tcp/ {++S[$NF]} END {for(a in S) print a, S[a]}'

list::splice(STL内置函数，用于将元素从一个列表传输到另一个列表。
list.splice (iterator position, list2, iterator first, iterator last)

分布式缓存Redis可用于以下场景：
1、缓存
缓存现在几乎是所有中大型网站都在用的必杀技，合理的利用缓存不仅能够提升网站访问速度，还能大大降低数据库的压力。Redis提供了键过期功能，也提供了灵活的键淘汰策略。
2、排行榜
很多网站都有排行榜应用的，如京东的月度销量榜单、商品
3、计数器
什么是计数器，如电商网站商品的浏览量、视频网站视频的播放数等。为了保证数据实时效，每次浏览都得给+1，并发量高时如果每次都请求数据库操作无疑是种挑战和压力。
Redis提供的incr命令来实现计数器功能，内存操作，性能非常好，非常适用于这些计数场景。
4、分布式会话
集群模式下，在应用不多的情况下一般使用容器自带的session复制功能就能满足，当应用增多相对复杂的系统中，一般都会搭建以Redis等内存数据库为中心的session服务，session不再由容器管理，而是由session服务及内存数据库管理。
5、分布式锁
在很多互联网公司中都使用了分布式技术，分布式技术带来的技术挑战是对同一个资源的并发访问，如全局ID、减库存、秒杀等场景，
并发量不大的场景可以使用数据库的悲观锁、乐观锁来实现，但在并发量高的场合中，利用数据库锁来控制资源的并发访问是不太理想的，大大影响了数据库的性能。
可以利用Redis的setnx功能来编写分布式的锁，如果设置返回1说明获取锁成功，否则获取锁失败，实际应用中要考虑的细节要更多。
6、 社交网络
点赞、踩、关注/被关注、共同好友等是社交网站的基本功能，社交网站的访问量通常来说比较大，而且传统的关系数据库类型不适合存储这种类型的数据，Redis提供的哈希、集合等数据结构能很方便的的实现这些功能。
7、最新列表
Redis列表结构，LPUSH可以在列表头部插入一个内容ID作为关键字，LTRIM可用来限制列表的数量，这样列表永远为N个ID，无需查询最新的列表，直接根据ID去到对应的内容页即可。
8、消息系统
消息队列是大型网站必用中间件，如ActiveMQ、RabbitMQ、Kafka等流行的消息队列中间件，主要用于业务解耦、流量削峰及异步处理实时性低的业务。
Redis提供了发布/订阅及阻塞队列功能，能实现一个简单的消息队列系统。另外，这个不能和专业的消息中间件相比。

缓存和数据库一致性解决方案
第一种方案：采用延时双删策略
void write(String key, Object data) {
    redis.delKey(key);
    db.update(data);
    Thread.sleep(500);  // 需要评估项目读数据业务逻辑的耗时, 还要考虑redis和数据库主从同步的耗时
    redis.delKey(key);
}
设置缓存过期时间: 从理论上来说，给缓存设置过期时间，是保证最终一致性的解决方案。所有的写操作以数据库为准，只要到达缓存过期时间，则后面的读请求自然会从数据库中读取新值然后回填缓存。
延时双删策略 + 缓存超时过期，这样最差的情况就是在超时时间内数据存在不一致，而且又增加了写请求的耗时。

第二种方案：异步更新缓存(基于订阅binlog的同步机制)
1）读Redis：热数据基本都在Redis
2）写MySQL: 增删改都是操作MySQL
3）更新Redis数据：MySQL的数据操作binlog，来更新到Redis(全量/增量，消息队列)

Linux系统在编程上提供的共享内存方案有三种：
mmap内存共享映射
XSI共享内存
POSIX共享内存

python采用的是引用计数机制为主，标记-清除和分代收集（隔代回收）两种机制为辅的策略。
gc模块提供一个接口给开发者设置垃圾回收的选项，且一个主要功能就是解决循环引用的问题。

linux查看系统日志文件：cat / tail -f

谈谈你对tRPC框架的理解
使用IDL 在gRPC上增加插件化管理 微服务框架  123平台(基于腾讯云服务的支持tRPC的容器运营平台，上线/部署服务
北极星(名字服务插件，用于解决远程调用的服务注册发现、动态路由、负载均衡和容错问题，在分布式和微服务架构中至关重要

C 语言中的 select 关键字可以同时监听多个文件描述符的可读或者可写的状态，在文件描述符发生状态改变之前，select 会一直阻塞当前的线程，
Go语言中的 select 关键字与其类似，它能够让一个 Goroutine 同时等待多个 Channel 达到准备状态(在语言层面实现)。

实现多个goroutine间的同步与通信大致有：
- 全局共享变量
- channel通信（CSP模型）
- Context包

八股 SAY NO！
数据库设计、索引怎么建立、系统功能模块设计（根据业务流程）

timestamp (4字节) / datatime (8字节)  --  常见时间储存类型(表示形式yyyy-mm-dd hh:mm:ss)
timestamp是当前时间到 Unix元年(1970年1月1日0时0分0秒)的秒数, 以utc的格式储存， 会自动检索当前时区并进行转换, 对于某些时间计算较为方便(直接加减);
对于NULL，timestamp会自动储存当前时间，而datetime会储存NULL, 即datetime存什么就取什么.

go里面的继承关系如何实现  --  组合 + 接口, 结构体嵌入

HTTP / RPC 协议  -- rpc是远端过程调用，其调用协议通常包含传输协议和序列化协议。
HTTP 就是一种 RPC，你通过一定的方法去调用 HTTP 服务器上的某个 procedure，执行完以后把结果返回。有的时候我们嫌标准 HTTP 太慢/太复杂/不适合特定场景，那么就自己发明一个新的。

一个完整的RPC架构里面包含了四个核心的组件，分别是Client，Client Stub，Server以及Server Stub，这个Stub可以理解为存根。
(1) client 以本地调用方式（接口）调用服务；
(2) client stub 接收到调用后，负责将方法、参数等组装成能够进行网络传输的消息体（将消息体对象序列化为二进制）；
(3) client 通过sockets将消息发送到服务端；
(4) server stub 收到消息后进行解码（将消息对象反序列化）；
(5) server stub 根据解码结果调用本地的服务；
(6) 本地服务执行，并将结果返回给 server stub；
(7) server stub 将返回结果打包成消息（将结果消息对象序列化）；
(8) server 通过sockets将消息发送到客户端；
(9) client stub 接收到结果消息，并进行解码（将结果消息发序列化）；
(10) client 得到最终结果。
RPC的目标是要把2、3、4、7、8、9这些步骤都封装起来。

为什么要用rpc调用？
因为良好的rpc调用是面向服务的封装，针对服务的可用性和效率等都做了优化。单纯使用http调用则缺少了这些特性。

指针和引用的本质区别: 两者都是地址的概念，指针指向一块儿内存，其内容为所指内存的地址；引用是某块儿内存的别名。
引用实际上就是基于指针加了一些语法糖，比如必须初始化、不能改变引用的指向等等。编译时，引用会被c++编译器当做const指针来进行操作.

I/O复用的本质，select/poll/epoll的本质区别  --  同时监听多个网络I/O事件

虚拟内存、页面调度算法及优缺点

shared_ptr 是否线程安全，不安全的情况
shared_ptr 的引用计数是原子操作的, 安全且无锁(智能指针管理的对象本身的线程安全由其自己保证);
多线程下读写shared_ptr所指向的同一个对象，不管是相同的shared_ptr对象，还是不同的shared_ptr对象，需要加锁保护.

软连接硬连接哪种可以跨文件系统，原因
硬连接: 直接建立在节点表上(inode)，建立硬连接指向一个文件时，会更新节点表上面的计数值，即共享一个 inode 号(文件在文件系统上的唯一标识)。
软链接(符号链接): 指向另一个文件的特殊文件，这种文件的数据部分仅包含它所要链接文件的路径名。
软链接是为了克服硬链接的不足而引入的，软链接不直接使用inode号作为文件指针，而是使用文件路径名作为指针(软链接：文件名 + 数据部分-->目标文件的路径名)。
软链接有自己的inode，并在磁盘上有一小片空间存放路径名。因此，软链接能够跨文件系统，也可以和目录链接，还可以对一个不存在的文件名进行链接，但直到这个名字对应的文件被创建后，才能打开其链接。

B+树的叶子节点链表是单向还是双向: 双向(双向链表)，用于倒序

undo log 是逻辑日志, 不是物理日志. 在多用户并发系统中,还有别的事务在对同一个页中的另几条记录进行修改,因此不能将一个页回滚到事务开始的样子.
采用逻辑恢复, 是insert的时候就delete, 是update的时候就采用相对的update来恢复数据.

如何查询慢sql产生的原因: 1、SQL编写问题(正确使用索引能加快查询速度); 2、锁; 3、业务实例相互干绕对 IO/CPU 资源争用; 4、服务器硬件

由 SQL 编写导致的慢 SQL 优化:
1、字段类型转换导致不用索引，如字符串类型的不用引号，数字类型的用引号等，这有可能会用不到索引导致全表扫描；
2、mysql 不支持函数转换，所以字段前面不能加函数，否则这将用不到索引；
3、不要在字段前面加减运算；
4、字符串比较长的可以考虑索引一部份减少索引文件大小，提高写入效率；
5、like % 在前面用不到索引；
6、根据联合索引的第二个及以后的字段单独查询用不到索引；
7、不要使用 select *；
8、排序请尽量使用升序;
9、or 的查询尽量用 union 代替 （Innodb）；
10、复合索引高选择性的字段排在前面；
11、order by / group by 字段包括在索引当中减少排序，效率会更高。

除了上述索引使用规则外，SQL 编写时还需要特别注意一下几点：
1、尽量规避大事务的 SQL，大事务的 SQL 会影响数据库的并发性能及主从同步；
2、分页语句 limit 的问题；
3、删除表所有记录请用 truncate，不要用 delete；
4、不让 mysql 干多余的事情，如计算；
5、输写 SQL 带字段，以防止后面表变更带来的问题，性能也是比较优的 ( 涉及到数据字典解析，请自行查询资料)；
6、在 Innodb上用 select count(*)，因为 Innodb 会存储统计信息；
7、慎用 Oder by rand()。

A, B列联合做主键
create table T(A int not null, B int not null, C int)
alter table T
add constraint pk primary key(A, B)

使用MD5加密算法, 将明文加密存在数据库中, 由于MD5是不可逆的, 所以在验证密码的时候需要将要验证的密码也用MD5加密, 然后和数据库中的数据进行对比.

为什么数据量小的时候用压缩列表: set是基于ziplist和skiplist实现的。数据量小的时候ziplist，当超过一定的阈值升级.
链表的前后指针是一个非常耗费内存的结构，因此在数据量小的时候，这一部分的空间尤其显得浪费。
压缩列表是一系列特殊编码的连续内存块组成的顺序性数据结构。

编程时如何判断对端关闭连接:
使用read返回值，如果返回0，并且errno=EAGAIN，则说明连接被对方关闭;
使用心跳包，长时间没有接到心跳包时，说明连接断开;
使用getsockopt判断连接状态，若是TCP_ESTABLISHED，则说明连接未断开，否则说明连接断开；

const和#define都可以定义常量，但是在C++中用const定义常量具有更多优点：
1、const常量有数据类型，而宏常量没有数据类型。编译器可以对前者进行类型安全检查，而对后者只进行字符替换，没有类型安全检查，并且在字符替换中可能会产生意料不到的错误。
2、有些集成的调试工具可以对const常量进行调试，但是不能对宏常量进行调试。在C++中用const常量完全取代了#define宏常量。

#define宏和函数的不同之处:
1、#define宏的执行速度快，而函数由于存在函数调用以及函数返回时的额外开销，因此函数的执行速度慢一些。
2、#define宏不便于调试(预处理阶段被编译器处理)，编译报错时，往往编译器报错的地方并不是真正发生错误的地方，而函数在程序运行过程中被处理，方便调试。
3、#define宏与类型无关，可以用于任何操作合法的参数类型，而函数参数与类型有关，如果参数类型不同，就需要不同的函数，且函数传参不可以传入数据类型。

几种替换宏的方式：
C++ 中使用 const 来代替宏常量；
使用 inline 来代替宏函数（包含类型检测）；
使用 typedef 来代替 define 定义的类型；
使用 enum 来代替定义多个宏常量，并且 enum 定义的常量可读性更高。

变量声明：表明变量的类型和名字。
变量定义：为变量分配存储空间，还可指定初始值。程序中，变量有且仅有一个定义。

函数声明时指定默认参数值可以吗？
可以。C++ 在声明函数的时候，如果指定了参数的默认值，再调用函数的时候可以省略后面的参数。

GET：URL发送请求，请求可被缓存，保留在浏览器历史记录中，可被收藏为书签，有长度限制
POST：HTTP消息主体中发送，请求不会被缓存，不会保留在浏览器历史记录中，不能被收藏为书签，对数据长度没有要求
HEAD：与 GET 相同，但只返回 HTTP 报头，不返回文档主体。
DELETE：删除指定资源。
PUT：上传指定的 URI 表示。
OPTIONS：返回服务器支持的 HTTP 方法。

怎么理解一切皆文件？
所有外设都是文件，本质上就是说他们都支持用来访问文件的那些接口，可以被当做文件来访问。这个原理与子类都能当做基类访问是一样的，就是操作系统层面的oop思想。

SYN泛洪，有一亿个链接怎办，怎么处理：
大量的握手请求涌向TCP服务端，而它们只发出SYN报文而不以ACK响应结束握手，服务端就要为这每一个请求都维持约一分多钟的连接去等待ACK，也就形成所谓的“半连接”。
维护这些半连接是需要消耗很多服务器的网络连接资源的。如果短时间内这些资源几乎都被半连接占满，那么正常的业务请求在这期间就得不到服务，处于等待状态。
对于SYN泛洪攻击的防范，优化主机系统设置是常用的手段。如降低SYN timeout时间，使得主机尽快释放半连接的占用；
又比如采用SYN cookie设置，如果短时间内连续收到某个IP的重复SYN请求，则认为受到了该IP的攻击，丢弃来自该IP的后续请求报文。
此外合理地采用防火墙等外部网络安全设施也可缓解SYN泛洪攻击。

Redis的多路复用是如何保证读写的顺序正确？
多个套接字产生的事件，由IO多路复用程序将它们放到一个队列中，然后通过这个队列，有序、同步地传递给文件事件分派器。

binlog 日志有三种格式，分别为 STATMENT、 ROW 和 MIXED。
在MySQL5.7.7之前，默认的格式是STATEMENT， MySQL5.7.7之后，默认值是ROW。日志格式通过 binlog-format 指定。

STATMENT：基于SQL语句的复制，每一条会修改数据的sql语句会记录到binlog中。
优点：不需要记录每一行的变化，减少了 binlog 日志量，节约了IO, 从而提高性能；
缺点：在某些情况下会导致主从数据不一致，比如执行sysdate()、slepp()等。

ROW：基于行的复制，不记录每条sql语句的上下文信息，仅需记录哪条数据被修改了。
优点：不会出现某些特定情况下的存储过程、或function、或trigger的调用和触发无法被正确复制的问题；
缺点：会产生大量的日志，尤其是`alter table`的时候会让日志暴涨

MIXED：基于STATMENT和ROW两种模式的混合复制，一般的复制使用STATEMENT模式保存binlog ，对于STATEMENT模式无法复制的操作使用ROW模式保存binlog

Map是如何提高并发时的吞吐性能：用更细粒度的锁，即为不同的Hash bucket（不同范围key对应的hash值）使用多个写锁；

QPS 每秒查询率

管道通信(PIPE)
两个进程利用管道进行通信时．发送信息的进程称为写进程．接收信息的进程称为读进程。管道通信方式的中间介质就是文件．通常称这种文件为管道文件．
写进程通过写入端(发送端)往管道文件中写入信息；读进程通过读出端(接收端)从管道文件中读取信息。两个进程协调不断地进行写和读，便会构成双方通过管道传递信息的流水线。
利用系统调用PIPE()可以创建一个无名管道文件，通常称为无名管道或PIPE；利用系统调用MKNOD()可以创建一个有名管道文件．通常称为有名管道或FIFO.
无名管道是一种非永久性的管道通信机构．当它访问的进程全部终止时，它也将随之被撤消。无名管道只能用在具有家族联系的进程之间。
有名管道可以长期存在于系统之中．而且提供给任意关系的进程使用，但是使用不当容易导致出错．

消息缓冲通信(MESSAGE)
多个独立的进程之间可以通过消息缓冲机制来相互通信．这种通信的实现是以消息缓冲区为中间介质．通信双方的发送和接收操作均以消息为单位。
在存储器中，消息缓冲区被组织成队列，通常称之为消息队列。消息队列一旦创建后即可由多进程共享．发送消息的进程可以在任意时刻发送任意个消息到指定的消息队列上，
并检查是否有接收进程在等待它所发送的消息。若有则唤醒它：而接收消息的进程可以在需要消息的时候到指定的消息队列上获取消息．如果消息还没有到来．则转入睡眠状态等待。

共享内存通信(SHARED MEMORY)
针对消息缓冲需要占用CPU进行消息复制的缺点．OS提供了一种进程间直接进行数据交换的通信方式一共享内存
这种通信方式允许多个进程在外部通信协议或同步，互斥机制的支持下使用同一个内存段(作为中间介质)进行通信．
它是一种最有效的数据通信方式，其特点是没有中间环节．直接将共享的内存页面通过附接．映射到相互通信的进程各自的虚拟地址空间中．
从而使多个进程可以直接访问同一个物理内存页面．如同访问自己的私有空间一样(但实质上不是私有的而是共享的)。
因此这种进程间通信方式是在同一个计算机系统中的诸进程间实现通信的最快捷的方法．而它的局限性也在于此．
即共享内存的诸进程必须共处同一个计算机系统．有物理内存可以共享才行。

三种方式的特点（优缺点）：
1.无名管道简单方便．但局限于单向通信的工作方式．并且只能在创建它的进程及其子孙进程之间实现管道的共享：
有名管道虽然可以提供给任意关系的进程使用．但是由于其长期存在于系统之中，使用不当容易出错。
2.消息缓冲可以不再局限于父子进程．而允许任意进程通过共享消息队列来实现进程间通信．
并由系统调用函数来实现消息发送和接收之间的同步．从而使得用户在使用消息缓冲进行通信时不再需要考虑同步问题．
使用方便，但是信息的复制需要额外消耗CPU的时间．不适宜于信息量大或操作频繁的场合。
3.共享内存针对消息缓冲的缺点改而利用内存缓冲区直接交换信息，无须复制，快捷、信息量大是其优点。
但是共享内存的通信方式是通过将共享的内存缓冲区直接附加到进程的虚拟地址空间中来实现的．
因此，这些进程之间的读写操作的同步问题操作系统无法实现。必须由各进程利用其他同步工具解决。
另外，由于内存实体存在于计算机系统中．所以只能由处于同一个计算机系统中的诸进程共享。不方便网络通信。

                Redo log                                                            Bin log
适用场景      适用于崩溃恢复，保持数据库持久性                                   适用于主从复制和数据恢复
实现方式      InnoDB 引擎层实现的，并不是所有引擎都有                            Server层实现的，所有引擎都可以使用 binlog 日志
记录方式      Redo log采用循环写的方式, 当写到结尾时, 会回到开头循环写日志        Bin log采用追加方式记录，当文件尺寸大于给配置值后，后续日志会记录到新文件上
文件大小      Redo log 的大小是固定的                                           Bin log 可通过配置参数 max_binlog_size 设置每个binlog文件的大小